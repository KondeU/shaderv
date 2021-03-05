#include "MainWindow.h"
#include "subs/MGraph.h"
#include "subs/VGraph.h"

MainWindow::MainWindow() : vman(*this)
{
    //ui.setupUi(this);

    //mainStatusBar = QT_NEW StatusBar;
    //setStatusBar(mainStatusBar);
    //
    //// TODO: Toolbars...
    //
    //auto scene = dockerManager.BuildRenderer<RScene>();
    //auto game = dockerManager.BuildRenderer<RGame>();
    //
    //auto hierarchy = dockerManager.BuildWindow<WHierarchy>(
    //    DockerManager::WindowLocation::LEFT, *this);
    //auto inspector = dockerManager.BuildWindow<WInspector>(
    //    DockerManager::WindowLocation::RIGHT, *this);
    //auto project = dockerManager.BuildWindow<WProject>(
    //    DockerManager::WindowLocation::BOTTOM, *this);

    mman.BuildModel<MGraph>();

    auto graph = vman.BuildViewCenter<VGraph>(*mman.ObtainModel<MGraph>());

    //ui.menuView->addAction(project->GetToggleCheckableAction());
    //ui.menuView->addAction(hierarchy->GetToggleCheckableAction());
    //ui.menuView->addAction(inspector->GetToggleCheckableAction());
    //ui.menuView->addSeparator();

    // Default window geometry: 1280x720, center on screen
    resize(1280, 720);
    setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter,
        frameSize(), QGuiApplication::primaryScreen()->availableGeometry()));

    // Restore all states
    QSettings states("states/states.ini", QSettings::IniFormat);
    restoreGeometry(states.value("MainWindow/Geometry").toByteArray());
    restoreState(states.value("MainWindow/State").toByteArray());
    //--------------------------------------------------------------------
    // T.D.: NB: The rendering window uses the native window handle, call
    //           restoreState will trigger a Qt bug, causing the geometry
    //           of the widget to be misplaced!
    // Once the program is started, give the dock an area through code to
    // temporarily avoid this problem.
    // Link:
    //   https://github.com/githubuser0xFFFF/Qt-Advanced-Docking-System/issues/232
    //   https://bugreports.qt.io/browse/QTBUG-85990
    // 2020/09/19 wtf bug!
    //--------------------------------------------------------------------
    // I first found the problem in TiStudio graphics editor project, but
    // in this project, we are not going to use native window, so this
    // problem will not be triggered currently. [MARKED]
    //--------------------------------------------------------------------
    //dockerManager.RestoreState("states/docks.ini"); 
}

MainWindow::~MainWindow()
{
    // Save all states
    QSettings states("states/states.ini", QSettings::IniFormat);
    states.setValue("MainWindow/Geometry", saveGeometry());
    states.setValue("MainWindow/State", saveState());
    //dockerManager.SaveState("states/docks.ini");
}
