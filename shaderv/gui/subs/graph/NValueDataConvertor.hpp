#ifndef _N_VALUE_DATA_CONVERTOR_HPP_
#define _N_VALUE_DATA_CONVERTOR_HPP_

#include "NValueData.hpp"

template <typename TI, typename TO>
class NValueDataConvertor {
public:
    std::shared_ptr<QtNodes::NodeData>
        operator()(std::shared_ptr<QtNodes::NodeData> in)
    {
        auto data = std::dynamic_pointer_cast<TI>(in);
        if (data) {
            Convert(data);
        } else {
            out.reset();
        }
        return out;
    }

protected:
    virtual void Convert(std::shared_ptr<TI> in) = 0;
    std::shared_ptr<TO> out;
};

class NDecimalToInteger : public NValueDataConvertor<NDecimal, NInteger> {
private:
    void Convert(std::shared_ptr<NDecimal> in) override
    {
        out = std::make_shared<NInteger>();
        out->Set(static_cast<long>(in->Get()));
    }
};

class NIntegerToDecimal : public NValueDataConvertor<NInteger, NDecimal> {
private:
    void Convert(std::shared_ptr<NInteger> in) override
    {
        out = std::make_shared<NDecimal>();
        out->Set(in->Get());
    }
};

#endif
