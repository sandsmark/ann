#ifndef VECTORVIEW_H
#define VECTORVIEW_H

#include <QtGui/QWidget>
#include <eigen3/Eigen/Geometry>

using namespace Eigen;

class VectorView : public QWidget
{
Q_OBJECT
public:
    VectorView();
    virtual ~VectorView();
    
    
    void setHorizontalRes(int num) { m_horRes = num; }
    void setVerticalRes(int num) { m_vertRes = num; }
    void setVector(const ArrayXf &vector) { m_layer = vector; }
    
protected:
    virtual void paintEvent(QPaintEvent*);
private:
    int m_horRes;
    int m_vertRes;
    ArrayXf m_layer;
    
};

#endif//VECTORVIEW_H
