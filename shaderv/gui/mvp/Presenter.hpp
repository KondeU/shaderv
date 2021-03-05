#ifndef _PRESENTER_HPP_
#define _PRESENTER_HPP_

#include "../UiBasic.hpp"

class Presenter : public QObject {
public:
    virtual ~Presenter() = default;

protected:
    Presenter() = default;
};

#endif
