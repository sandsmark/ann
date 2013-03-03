#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWidget>

#include "vectorview.h"
#include "filereader.h"
#include "neuronnetwork.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow();
    virtual ~MainWindow();

private slots:
    void nextPressed();
    void trainPressed();
    
private:
    VectorView m_vectorView;
    FileReader m_fileReader;
    NeuronNetwork *m_network;
};

#endif//MAINWINDOW_H