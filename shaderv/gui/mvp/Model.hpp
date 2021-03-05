#ifndef _MODEL_HPP_
#define _MODEL_HPP_

#include "../UiBasic.hpp"

class Model : public QObject {
public:
    virtual ~Model() = default;
    virtual bool Init() = 0;

protected:
    Model() = default;
};

#endif
