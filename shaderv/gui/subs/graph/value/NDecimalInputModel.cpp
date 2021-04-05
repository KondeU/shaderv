#include "NDecimalInputModel.h"
#include "../GraphInternalWidgetDeleter.h"

NDecimalInputModel::NDecimalInputModel()
    : NBaseModel(0, 1, "Const Decimal")
{
    lineEdit = QT_NEW QLineEdit;
    doubleValidator = QT_NEW QDoubleValidator(lineEdit);
    lineEdit->setValidator(doubleValidator);
    lineEdit->setMaximumSize(lineEdit->sizeHint());
    connect(lineEdit, &QLineEdit::textChanged,
    [this](const QString& text) {
        bool success = false;
        double value = lineEdit->text().toDouble(&success);
        if (success) {
            decimal = std::make_shared<NDecimal>();
            decimal->Set(value);
            SetNodeState(NodeState::NORMAL);
            SetNodeMessage("");
        } else {
            decimal.reset();
            SetNodeState(NodeState::WARNING);
            SetNodeMessage("Please input a decimal!");
        }
        Update(0);
    });
    lineEdit->setText("0.0");

    SetTitle("Decimal");
    SetOutputPortDataType(0, NDecimal().type());
    SetInternalWidget(lineEdit);

    REGISTER_INTERNAL_WIDGET(
        "NDecimalInputModel", lineEdit);
}

void NDecimalInputModel::CbSave(
    QJsonObject& modelJson) const
{
    if (decimal) {
        modelJson["decimal"] =
            QString::number(decimal->Get());
    }
}

void NDecimalInputModel::CbRestore(
    const QJsonObject& modelJson)
{
    QJsonValue jsonValue = modelJson["decimal"];
    if (!jsonValue.isUndefined()) {
        QString valueString = jsonValue.toString();

        bool success = false;
        double value = valueString.toDouble(&success);
        if (success) {
            decimal = std::make_shared<NDecimal>();
            decimal->Set(value);

            lineEdit->setText(valueString);
        }
    }
}

void NDecimalInputModel::CbInData(
    int index, std::shared_ptr<PortData> in)
{
}

std::shared_ptr<NDecimalInputModel::PortData>
NDecimalInputModel::CbOutData(int index)
{
    if (index == 0) {
        return decimal;
    }
    return std::shared_ptr<PortData>();
}
