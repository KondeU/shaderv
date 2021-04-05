#ifndef _N_DECIMAL_INPUT_MODEL_H_
#define _N_DECIMAL_INPUT_MODEL_H_

#include "../NBaseModel.hpp"
#include "../NValueData.hpp"

class NDecimalInputModel : public NBaseModel {
public:
    NDecimalInputModel();

    void CbSave(QJsonObject& modelJson) const override;
    void CbRestore(const QJsonObject& modelJson) override;

    void CbInData(int index, std::shared_ptr<PortData> in) override;
    std::shared_ptr<PortData> CbOutData(int index) override;

private:
    std::shared_ptr<NDecimal> decimal;

    QLineEdit* lineEdit;
    QDoubleValidator* doubleValidator;
};

#endif
