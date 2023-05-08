#include "qmylabel.h"

QMyLabel::QMyLabel(QWidget *parent)
    : QLabel(parent)
{

}

void QMyLabel::mousePressEvent(QMouseEvent *ev) //이미지의 배율에 맟추어 클릭 위치가 나옴.
{
    if(ev->button() == Qt::LeftButton)
    {
        double w = this->width();
        double h = this->height();
        double x = ev->x();
        double y = ev->y();
        emit mouse_clicked(x,y);
    }
    
}


void QMyLabel::mouseReleaseEvent(QMouseEvent *ev) //이미지의 배율에 맟추어 클릭 위치가 나옴.
{
    if(ev->button() == Qt::LeftButton)
    {
        double w = this->width();
        double h = this->height();
        double x = ev->x();
        double y = ev->y();
        emit mouse_released(x,y);
    }

}
