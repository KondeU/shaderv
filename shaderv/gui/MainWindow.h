#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

//#include "ui_MainWindow.h"
#include "UiBasic.hpp"
#include "mvp/ModelManager.hpp"
#include "mvp/ViewManager.hpp"
#include "mvp/PresenterManager.hpp"

class MainWindow final : public QMainWindow {
public:
    MainWindow();
    ~MainWindow() override;

private:
    //======= MVP Pattern =======//
    ModelManager     mman;  //-M-//
    ViewManager      vman;  //-V-//
    PresenterManager pman;  //-P-//
};

#endif
