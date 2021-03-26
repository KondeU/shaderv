#ifndef _N_BASE_MODEL_HPP_
#define _N_BASE_MODEL_HPP_

#include "../../UiBasic.hpp"

class NBaseModel : public QtNodes::NodeDataModel {
public:
    using PortDataType = QtNodes::NodeDataType;
    using PortData = QtNodes::NodeData;

    enum PortInputAutogrowPolicy {
        FIXED,
        AUTO
    };

    enum class PortOutputConnectionPolicy {
        ONE,
        MANY
    };

    enum class NodeState {
        NORMAL,
        WARNING,
        INVALID
    };

    void SetName(const QString& name)
    {
        unique = name;
    }

    void SetTitle(const QString& title)
    {
        this->title = title;
    }

    void SetTitleVisible(bool titleVisible)
    {
        this->titleVisible = titleVisible;
    }

    void SetInputPortString(int index, const QString& string)
    {
        inputPortString[index] = string;
    }

    void SetOutputPortString(int index, const QString& string)
    {
        outputPortString[index] = string;
    }

    void SetInputPortStringVisible(int index, bool visible)
    {
        inputPortStringVisible[index] = visible;
    }

    void SetOutputPortStringVisible(int index, bool visible)
    {
        outputPortStringVisible[index] = visible;
    }

    void SetInputPortDataType(int index, const PortDataType& portDataType)
    {
        inputPortDataType[index] = portDataType;
    }

    void SetOutputPortDataType(int index, const PortDataType& portDataType)
    {
        outputPortDataType[index] = portDataType;
    }

    void SetPortInputAutogrowPolicy(PortInputAutogrowPolicy p)
    {
        inputAutogrowPolicy = p;
    }

    void SetPortOutputConnectionPolicy(PortOutputConnectionPolicy p)
    {
        outputConnectionPolicy = p;
    }

    void SetNodeState(NodeState state)
    {
        nodeState = state;
    }

    void SetNodeMessage(const QString& message)
    {
        nodeMessage = message;
    }

    void SetResizable(bool allowed)
    {
        allowResize = allowed;
    }

    void SetInternalWidget(QWidget* widget)
    {
        internalWidget = widget;
    }

    void Update(int outIndex)
    {
        emit dataUpdated(outIndex);
    }

    virtual void CbSave(QJsonObject& modelJson) const {}
    virtual void CbRestore(const QJsonObject& modelJson) {}

    virtual void CbInData(int index, std::shared_ptr<PortData> in) = 0;
    virtual std::shared_ptr<PortData> CbOutData(int index) = 0;

protected:
    NBaseModel(
        int inputPortCount,
        int outputPortCount,
        const QString& name)
        : inputPortCount(inputPortCount),
          outputPortCount(outputPortCount)
    {
        SetName(name);

        inputPortCount = std::max(0, inputPortCount);
        outputPortCount = std::max(0, outputPortCount);
        
        inputPortString.resize(inputPortCount);
        outputPortString.resize(outputPortCount);

        inputPortStringVisible.resize(inputPortCount);
        outputPortStringVisible.resize(outputPortCount);

        inputPortDataType.resize(inputPortCount);
        outputPortDataType.resize(outputPortCount);
    }

    QString name() const override
    {
        return unique;
    }

    QString caption() const override
    {
        return title;
    }

    bool captionVisible() const override
    {
        return titleVisible;
    }

    QString portCaption(
        QtNodes::PortType type,
        QtNodes::PortIndex index)
        const override
    {
        switch (type) {
        case QtNodes::PortType::In:
            return inputPortString[index];
        case QtNodes::PortType::Out:
            return outputPortString[index];
        case QtNodes::PortType::None:
        default:
            break;
        }
        return "";
    }

    bool portCaptionVisible(
        QtNodes::PortType type,
        QtNodes::PortIndex index)
        const override
    {
        switch (type) {
        case QtNodes::PortType::In:
            return inputPortStringVisible[index];
        case QtNodes::PortType::Out:
            return outputPortStringVisible[index];
        case QtNodes::PortType::None:
        default:
            break;
        }
        return false;
    }

    unsigned int nPorts(
        QtNodes::PortType type)
        const override
    {
        switch (type) {
        case QtNodes::PortType::In:
            return inputPortCount;
        case QtNodes::PortType::Out:
            return outputPortCount;
        case QtNodes::PortType::None:
        default:
            break;
        }
        return 0;
    }

    QtNodes::NodeDataType dataType(
        QtNodes::PortType type,
        QtNodes::PortIndex index)
        const override
    {
        switch (type) {
        case QtNodes::PortType::In:
            return inputPortDataType[index];
        case QtNodes::PortType::Out:
            return outputPortDataType[index];
        case QtNodes::PortType::None:
        default:
            break;
        }
        return {};
    }

    ConnectionPolicy portOutConnectionPolicy(
        QtNodes::PortIndex index)
        const override
    {
        // The index is no used yet.
        switch (outputConnectionPolicy) {
        case PortOutputConnectionPolicy::ONE:
            return ConnectionPolicy::One;
        case PortOutputConnectionPolicy::MANY:
            return ConnectionPolicy::Many;
        default:
            break;
        }
        return ConnectionPolicy::Many;
    }

    QtNodes::NodeValidationState validationState() const override
    {
        switch (nodeState) {
        case NodeState::NORMAL:
            return QtNodes::NodeValidationState::Valid;
        case NodeState::WARNING:
            return QtNodes::NodeValidationState::Warning;
        case NodeState::INVALID:
            return QtNodes::NodeValidationState::Error;
        default:
            break;
        }
        return QtNodes::NodeValidationState::Valid;
    }

    QString validationMessage() const override
    {
        return nodeMessage;
    }

    bool resizable() const override
    {
        return allowResize;
    }

    QWidget* embeddedWidget() override
    {
        return internalWidget;
    }

    QJsonObject save() const override
    {
        QJsonObject modelJson
            = NodeDataModel::save();
        CbSave(modelJson);
        return modelJson;
    }

    void restore(QJsonObject const& modelJson) override
    {
        NodeDataModel::restore(modelJson);
        CbRestore(modelJson);
    }

    void setInData(std::shared_ptr<QtNodes::NodeData> data,
        QtNodes::PortIndex port) override
    {
        CbInData(port, data);
    }

    std::shared_ptr<QtNodes::NodeData> outData(
        QtNodes::PortIndex port) override
    {
        return CbOutData(port);
    }

private:
    int inputPortCount;
    int outputPortCount;

    QString unique;

    QString title;
    bool titleVisible = true;

    QVector<QString> inputPortString;
    QVector<QString> outputPortString;

    QVector<bool> inputPortStringVisible;
    QVector<bool> outputPortStringVisible;

    QVector<PortDataType> inputPortDataType;
    QVector<PortDataType> outputPortDataType;

    PortInputAutogrowPolicy inputAutogrowPolicy
        = PortInputAutogrowPolicy::FIXED;
    PortOutputConnectionPolicy outputConnectionPolicy
        = PortOutputConnectionPolicy::ONE;

    NodeState nodeState = NodeState::NORMAL;
    QString nodeMessage;

    bool allowResize = false;

    QWidget* internalWidget = nullptr;
};

#endif
