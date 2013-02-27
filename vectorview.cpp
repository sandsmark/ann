#include "vectorview.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include <QtGui/QPainter>
#include <QtCore/QDebug>

VectorView::VectorView()
{
}

VectorView::~VectorView()
{}

void VectorView::paintEvent(QPaintEvent* )
{
    qDebug() << m_horRes * m_vertRes << m_layer.innerSize();
    int boxWidth = width() / m_horRes;
    int boxHeight = height() / m_vertRes;
    QPainter painter(this);
    for (int x=0; x<m_horRes; x++) {
        for (int y=0; y<m_vertRes; y++) {
            int val = m_layer(x*m_horRes + y)*255.0;
            qDebug() << val;
//            QColor col = QColor::fromHsv(val, val, val);
            QColor col(val, val, val);
            painter.setBrush(col);
            painter.drawRect(x*boxWidth, y*boxHeight, boxWidth-1, boxHeight-1);
        }
    }
    
}


#include "vectorview.moc"
