#include <QtGui/QApplication>
#include "ann.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ann foo;
    foo.show();
    return app.exec();
}
