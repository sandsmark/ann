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


TrainingExample FileReader::readExample()
{
    QByteArray input = m_file.readLine();
    qDebug() << input;
    QList<QByteArray> values = input.split(',');
    TrainingExample example;
    example.expected = QString::fromAscii(values.takeFirst()).toInt();
    int i=0;
    ArrayXf vector(values.size());
    foreach(const QByteArray &value, values) {
        vector(i++) = QString::fromAscii(value).toInt();
    }
    example.inputs = vector;
    return example;
}
