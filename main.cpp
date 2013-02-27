#include <QtGui/QApplication>
#include <eigen3/Eigen/Geometry>
#include "vectorview.h"
#include "filereader.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    VectorView foo;
    foo.setHorizontalRes(28);
    foo.setVerticalRes(28);
    FileReader reader("train.csv");
    foo.setVector(reader.readExample().inputs/255);
    foo.show();
    return app.exec();
}
