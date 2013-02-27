#include "mainwindow.h"

#include <QtGui/QGridLayout>
#include <kurlrequester.h>

MainWindow::MainWindow() : QWidget(0)
{
    QGridLayout *layout = new QGridLayout;
    setLayout(layout);
    
    m_fileReader.openFile(QLatin1String("train.csv"));
    
    m_vectorView.setHorizontalRes(28);
    m_vectorView.setVerticalRes(28);
    layout->addWidget(&m_vectorView, 0, 0);
    
    QPushButton *button = new QPushButton("Next");
    layout->addWidget(button, 0, 1);
    connect(button, SIGNAL(clicked(bool)), SLOT(nextPressed()));
}

void MainWindow::nextPressed()
{
    m_vectorView.setVector(m_fileReader.readExample().inputs);
    m_vectorView.update();
}

#include "mainwindow.moc"