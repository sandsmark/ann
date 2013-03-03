#ifndef NETWORKVIEW_H
#define NETWORKVIEW_H

#include <QtGui/QWidget>

#include "neuronnetwork.h"

class NetworkView : public QWidget
{
    Q_OBJECT
public:
    NetworkView(const NeuronNetwork &network, QWidget *parent);
    void paintEvent(QPaintEvent *event);
    
private:
    const NeuronNetwork &m_network;
};
    

#endif//NETWORKVIEW_H