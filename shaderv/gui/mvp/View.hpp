#ifndef _VIEW_HPP_
#define _VIEW_HPP_

#include "../UiBasic.hpp"

class View : public QWidget {
public:
    const QString& GetTitleName() const
    {
        return title;
    }

protected:
    explicit View(const QString& uniqueTitleName)
        : title(uniqueTitleName) {}
    virtual ~View() {}

private:
    QString title;
};

#endif
