#include "networkview.h"
#include <QPainter>

NetworkView::NetworkView(const NeuronNetwork& network, QWidget* parent) :
    QWidget(parent),
    m_network(network)
{

}

void NetworkView::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    
    painter.drawText(rect(), "Hello");
}

#include "networkview.moc"