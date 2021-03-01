#include "MainWindow.h"

int main(int argc, char* argv[])
{
    DFX::Init(true, "runlogs/");
    DFX::EnableMemoryLeakDebugTracing();

    // Debugging memory leak:
    //_CrtSetBreakAlloc(0);

    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication application(argc, argv);
    application.setApplicationName(APP_NAME);

    MainWindow mainWindow;
    mainWindow.show();

    int exitCode = application.exec();

    DFX::Deinit();
    return exitCode;
}
