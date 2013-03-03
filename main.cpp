#include <QtGui/QApplication>
#include <eigen3/Eigen/Geometry>
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    
    MainWindow window;
    window.show();
    return app.exec();
}
