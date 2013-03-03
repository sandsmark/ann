#ifndef FILEREADER_H
#define FILEREADER_H

#include "trainingexample.h"

#include <QtCore/QString>
#include <QtCore/QFile>
#include <eigen3/Eigen/Geometry>

using namespace Eigen;

class FileReader {
public:
    FileReader();
    void openFile(QString filename);
    TrainingExample readExample();
    bool atEnd() { return m_file.atEnd(); }
    
private:
    QFile m_file;
    
};
#endif//FILEREADER_H