#ifndef _VIEW_MANAGER_HPP_
#define _VIEW_MANAGER_HPP_

#include "../GraphBasic.hpp"

class ViewManager {
public:
    explicit ViewManager(QMainWindow& mainWindow) : mainWindow(mainWindow)
    {
        #ifdef DOCK_USE_ADVANCED
        ads::CDockManager::setConfigFlag(ads::CDockManager::FocusHighlighting);
        dockManager = std::make_unique<ads::CDockManager>(&mainWindow);
        // Central widget is used to display the scene window: graph and generated source.
        centralTabWidget = QT_NEW QTabWidget;
        centralDockWidget = QT_NEW ads::CDockWidget("Scene");
        centralDockWidget->setWidget(centralTabWidget);
        dockManager->                                             // Set this central widget
            setCentralWidget(centralDockWidget)->                 // and do not allow docked
            setAllowedAreas(ads::DockWidgetArea::OuterDockAreas); // other widgets.
        #else
        centralTabWidget = QT_NEW QTabWidget;
        mainWindow.setCentralWidget(centralTabWidget);
        #endif
    }

    virtual ~ViewManager()
    {
        // Move the dockManager->deleteLater() to the
        // DeleteLater function and call it in MainWindow,
        // otherwise the floating window cannot close normally!
    }

    void DeleteLater()
    {
        #ifdef DOCK_USE_ADVANCED
        // Delete dock manager here to delete
        // all floating widgets. This ensures
        // that all top level windows of the
        // dock manager are properly closed.
        dockManager->deleteLater();
        #endif
    }

    void SaveState(const QString& file)
    {
        #ifdef DOCK_USE_ADVANCED
        QSettings settings(file, QSettings::IniFormat);
        settings.setValue("DockerManager", dockManager->saveState());
        #endif
    }

    void RestoreState(const QString& file)
    {
        #ifdef DOCK_USE_ADVANCED
        QSettings settings(file, QSettings::IniFormat);
        dockManager->restoreState(settings.value("DockerManager").toByteArray());
        #endif
    }

    template <typename V, class ...Args>
    V* BuildViewCenter(const Args& ...args)
    {
        static_assert(std::is_base_of<ViewCenter, V>(),
            "Template is not base of ViewCenter");
        V* viewCenter = QT_NEW V(args...);
        centralTabWidget->addTab(viewCenter, viewCenter->GetTitleName());
        return viewCenter;
    }

    template <typename V, class ...Args>
    V* BuildViewDocker(const Args& ...args)
    {
        static_assert(std::is_base_of<ViewDocker, V>(),
            "Template is not base of ViewDocker");
        V* viewDocker = QT_NEW V(args...);
        #ifdef DOCK_USE_ADVANCED
        dockManager->addDockWidget(ads::OuterDockAreas, viewDocker->dockWidget);
        #else
        mainWindow.addDockWidget(Qt::AllDockWidgetAreas, viewDocker->dockWidget);
        #endif
        return viewDocker;
    }

    // Specify the location when the window is created because
    // of the bug in Qt(see MainWindow.cpp) that is impossible
    // to restore the window state.
    enum class WindowLocation { TOP, LEFT, RIGHT, BOTTOM };
    template <typename V, class ...Args>
    V* BuildViewDocker(WindowLocation location, const Args& ...args)
    {
        static_assert(std::is_base_of<ViewDocker, V>(),
            "Template is not base of ViewDocker");
        V* viewDocker = QT_NEW V(args...);
        #ifdef DOCK_USE_ADVANCED
        ads::DockWidgetArea area;
        switch (location) {
            case WindowLocation::TOP:    area = ads::TopDockWidgetArea;    break;
            case WindowLocation::LEFT:   area = ads::LeftDockWidgetArea;   break;
            case WindowLocation::RIGHT:  area = ads::RightDockWidgetArea;  break;
            case WindowLocation::BOTTOM: area = ads::BottomDockWidgetArea; break;
        }
        dockManager->addDockWidget(area, viewDocker->dockWidget);
        #else
        Qt::DockWidgetArea area;
        switch (location) {
            case WindowLocation::TOP:    area = Qt::TopDockWidgetArea;    break;
            case WindowLocation::LEFT:   area = Qt::LeftDockWidgetArea;   break;
            case WindowLocation::RIGHT:  area = Qt::RightDockWidgetArea;  break;
            case WindowLocation::BOTTOM: area = Qt::BottomDockWidgetArea; break;
        }
        mainWindow.addDockWidget(area, window->dockWidget);
        #endif
        return viewDocker;
    }

private:
    #ifdef DOCK_USE_ADVANCED
    std::unique_ptr<ads::CDockManager> dockManager;
    ads::CDockWidget* centralDockWidget; // The central area is used to
    QTabWidget* centralTabWidget;        // display the scene window.
    #else
    QTabWidget* centralTabWidget;
    #endif
    QMainWindow& mainWindow;
};

#endif
