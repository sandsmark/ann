#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWidget>

#include "vectorview.h"
#include "filereader.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow();

private slots:
    void nextPressed();
    
private:
    VectorView m_vectorView;
    FileReader m_fileReader;
};

#endif//MAINWINDOW_H