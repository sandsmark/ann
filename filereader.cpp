#include "filereader.h"

#include <QDebug>

FileReader::FileReader()
{
}

void FileReader::openFile(QString filename)
{
    m_file.setFileName(filename);
    m_file.open(QIODevice::ReadOnly);
    m_file.readLine(); // first line is just header
}

ArrayXf intToArray(int t)
{
    ArrayXf ret = ArrayXf::Zero(10);
    ret(t) = 1.0f;
    
    return ret;
}

TrainingExample FileReader::readExample()
{
    QByteArray input = m_file.readLine();
    QList<QByteArray> values = input.split(',');
    TrainingExample example;
    example.expectedOutput = intToArray(QString::fromAscii(values.takeFirst()).toInt());
    int i=0;
    ArrayXf vector(values.size());
    foreach(const QByteArray &value, values) {
        vector(i++) = QString::fromAscii(value).toInt();
    }
    example.inputs = vector;
    return example;
}
