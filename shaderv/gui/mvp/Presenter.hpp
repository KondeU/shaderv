#ifndef _PRESENTER_HPP_
#define _PRESENTER_HPP_

#include "../UiBasic.hpp"

class Presenter : public QObject {
public:
    virtual ~Presenter() = default;
    virtual bool Init() = 0;

protected:
    Presenter() = default;
};

#endif
