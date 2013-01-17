#include "ann.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include <QtGui/QPainter>
#include <QtCore/QDebug>

LayerView::LayerView()
{
}

LayerView::~LayerView()
{}

void LayerView::paintEvent(QPaintEvent* )
{
    int boxWidth = width() / m_horRes;
    int boxHeight = height() / m_vertRes;
    QPainter painter(this);
    for (int x=0; x<m_horRes; x++) {
        for (int y=0; y<m_vertRes; y++) {
            int val = abs(m_layer(x*m_horRes + y)) % 23;
            val = val * 10;
            QColor col = QColor::fromHsv(val, val, val);
            painter.setBrush(col);
            painter.drawRect(x*boxWidth, y*boxHeight, boxWidth-1, boxHeight-1);
        }
    }
    
}


#include "ann.moc"
