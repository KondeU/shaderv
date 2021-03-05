#ifndef _VIEW_DOCKER_HPP_
#define _VIEW_DOCKER_HPP_

#include "View.hpp"

class ViewDocker : public View {
public:
    QAction* GetToggleCheckableAction() const
    {
        return dockWidget->toggleViewAction();
    }

    void ShowWindow() const
    {
        #ifdef DOCK_USE_ADVANCED
        dockWidget->toggleView(true);
        #else
        dockWidget->setVisible(true);
        #endif
    }

    void HideWindow() const
    {
        #ifdef DOCK_USE_ADVANCED
        dockWidget->toggleView(false);
        #else
        dockWidget->setVisible(false);
        #endif
    }

protected:
    explicit ViewDocker(const QString& uniqueTitleName)
        : View(uniqueTitleName)
    {
        #ifdef DOCK_USE_ADVANCED
        dockWidget = QT_NEW ads::CDockWidget(uniqueTitleName);
        dockWidget->setWidget(this);
        #else
        scrollArea = QT_NEW QScrollArea;
        scrollArea->setWidgetResizable(true);
        scrollArea->setWidget(this);
        dockWidget = QT_NEW QDockWidget(uniqueTitleName);
        dockWidget->setObjectName(uniqueTitleName);
        dockWidget->setWidget(scrollArea);
        #endif
    }

    virtual ~ViewDocker() override
    {
    }

private:
    friend class DockerManager; // dockWidget
    #ifdef DOCK_USE_ADVANCED
    ads::CDockWidget* dockWidget;
    #else
    QScrollArea* scrollArea;
    QDockWidget* dockWidget;
    #endif
};

#endif
