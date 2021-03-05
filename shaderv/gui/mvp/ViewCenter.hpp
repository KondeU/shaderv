#ifndef _VIEW_CENTER_HPP_
#define _VIEW_CENTER_HPP_

#include "View.hpp"

class ViewCenter : public View {
protected:
    explicit ViewCenter(const QString& uniqueTitleName)
        : View(uniqueTitleName)
    {
        layout = QT_NEW QVBoxLayout;
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
        setLayout(layout);
    }

    ~ViewCenter() override
    {
    }

    bool SetStuff(QWidget* widget)
    {
        if (stuff != nullptr) {
            return false;
        }
        stuff = widget;
        layout->addWidget(stuff);
        return true;
    }

private:
    QVBoxLayout* layout;
    QWidget* stuff = nullptr;
};

#endif
