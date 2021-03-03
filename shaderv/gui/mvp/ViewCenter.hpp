#ifndef _VIEW_CENTER_HPP_
#define _VIEW_CENTER_HPP_

#include "View.hpp"

class ViewCenter : public View {
public:
    QWidget* GetStuff() const
    {
        return stuff;
    }

protected:
    ViewCenter(QWidget* stuff, const QString& uniqueTitleName)
        : stuff(stuff), View(uniqueTitleName)
    {
        QVBoxLayout* layout = QT_NEW QVBoxLayout;
        layout->addWidget(stuff);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
        setLayout(layout);
    }

    ~ViewCenter() override
    {
    }

private:
    QWidget* stuff;
};

#endif
