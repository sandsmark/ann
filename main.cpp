#include <QtGui/QApplication>
#include <eigen3/Eigen/Geometry>
#include "ann.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    LayerView foo;
    foo.setHorizontalRes(9);
    foo.setVerticalRes(9);
    foo.setVector(VectorXi::Random(100));
    foo.show();
    return app.exec();
}
