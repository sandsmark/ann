#include "mainwindow.h"

#include "networkview.h"

#include <QtGui/QGridLayout>
#include <QDebug>
#include <kurlrequester.h>

MainWindow::MainWindow() :
    QWidget(0),
    m_network(0)
{
    setMinimumHeight(500);
    setMinimumWidth(500);
    QGridLayout *layout = new QGridLayout;
    setLayout(layout);
    
    m_fileReader.openFile(QLatin1String("train.csv"));
    
    m_vectorView.setHorizontalRes(28);
    m_vectorView.setVerticalRes(28);
    layout->addWidget(&m_vectorView, 0, 0, 2, 1);
    
    QPushButton *button = new QPushButton("Next");
    layout->addWidget(button, 0, 1);
    connect(button, SIGNAL(clicked(bool)), SLOT(nextPressed()));
    
    button = new QPushButton("Train");
    layout->addWidget(button, 1, 1);
    connect(button, SIGNAL(clicked(bool)), SLOT(trainPressed()));
    
    
    QList <int> networkWidths;
    networkWidths << 50 << 10;
    m_network = new NeuronNetwork(27*27, networkWidths);
}

MainWindow::~MainWindow()
{
    delete m_network;
}

void MainWindow::trainPressed()
{
    FileReader reader;
    reader.openFile(QLatin1String("train.csv"));
    int i=0;
    for (int i=0; i<42000; i++) {
        printf("Progress: %d/42000 (%3.1f%)\n", i, i/420.0f);
        qDebug() << reader.atEnd();
        i++;
        TrainingExample example = m_fileReader.readExample();
        m_network->setInput(example.inputs);
        m_network->train(example.expectedOutput);
    }
}


void MainWindow::nextPressed()
{
    TrainingExample example = m_fileReader.readExample();
    m_vectorView.setVector(example.inputs);
    m_network->setInput(example.inputs);
    for (int i=0; i<10; i++)
        qDebug() << i << m_network->output()(i);
    m_vectorView.update();
}

#include "mainwindow.moc"