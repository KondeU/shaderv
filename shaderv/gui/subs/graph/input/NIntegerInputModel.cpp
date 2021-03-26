#include "NIntegerInputModel.h"
#include "../GraphInternalWidgetDeleter.h"

NIntegerInputModel::NIntegerInputModel()
    : NBaseModel(0, 1, "Integer(Const)")
{
    lineEdit = QT_NEW QLineEdit;
    integerValidator = QT_NEW QIntValidator(lineEdit);
    lineEdit->setValidator(integerValidator);
    lineEdit->setMaximumSize(lineEdit->sizeHint());
    connect(lineEdit, &QLineEdit::textChanged,
    [this](const QString& text) {
        bool success = false;
        int value = lineEdit->text().toInt(&success);
        if (success) {
            integer = std::make_shared<NInteger>();
            integer->Set(value);
            SetNodeState(NodeState::NORMAL);
            SetNodeMessage("");
        } else {
            integer.reset();
            SetNodeState(NodeState::WARNING);
            SetNodeMessage("Please input a integer!");
        }
        Update(0);
    });
    lineEdit->setText("0");

    SetTitle("Integer");
    SetOutputPortDataType(0, NInteger().type());
    SetInternalWidget(lineEdit);

    REGISTER_INTERNAL_WIDGET(
        "NIntegerInputModel", lineEdit);
}

void NIntegerInputModel::CbSave(
    QJsonObject& modelJson) const
{
    if (integer) {
        modelJson["integer"] =
            QString::number(integer->Get());
    }
}

void NIntegerInputModel::CbRestore(
    const QJsonObject& modelJson)
{
    QJsonValue jsonValue = modelJson["integer"];
    if (!jsonValue.isUndefined()) {
        QString valueString = jsonValue.toString();

        bool success = false;
        double value = valueString.toDouble(&success);
        if (success) {
            integer = std::make_shared<NInteger>();
            integer->Set(value);

            lineEdit->setText(valueString);
        }
    }
}

void NIntegerInputModel::CbInData(
    int index, std::shared_ptr<PortData> in)
{
}

std::shared_ptr<NIntegerInputModel::PortData>
NIntegerInputModel::CbOutData(int index)
{
    if (index == 0) {
        return integer;
    }
    return std::shared_ptr<PortData>();
}
