#ifndef ann_H
#define ann_H

#include <QtGui/QWidget>
#include <eigen3/Eigen/Geometry>
#include <eigen3/Eigen/Dense>

using namespace Eigen;

class LayerView : public QWidget
{
Q_OBJECT
public:
    LayerView();
    virtual ~LayerView();
    
    
    void setHorizontalRes(int num) { m_horRes = num; }
    void setVerticalRes(int num) { m_vertRes = num; }
    void setVector(const VectorXi &vector) { m_layer = vector; }
    
protected:
    virtual void paintEvent(QPaintEvent*);
private:
    int m_horRes;
    int m_vertRes;
    VectorXi m_layer;
    
};

#endif // ann_H
