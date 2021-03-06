#include "chartview.h"
#include <QtGui/QMouseEvent>
#include <QApplication>
#include <QDebug>

ChartView::ChartView(QWidget *parent) :
    QChartView(parent)

{
    setRubberBand(QChartView::RectangleRubberBand);
    setFocusPolicy(Qt::ClickFocus);
}



void ChartView::mousePressEvent(QMouseEvent *event)
{
    switch( event->button() ) {
    case Qt::MiddleButton:
        chart()->zoomReset();
        break;

    default:
        QChartView::mousePressEvent(event);
        break;
    }
}




void ChartView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        chart()->zoomIn();
        break;
    case Qt::Key_Minus:
        chart()->zoomOut();
        break;

    case Qt::Key_Left:
        chart()->scroll(-10, 0);
        break;
    case Qt::Key_Right:
        chart()->scroll(10, 0);
        break;
    case Qt::Key_Up:
        chart()->scroll(0, 10);
        break;
    case Qt::Key_Down:
        chart()->scroll(0, -10);
        break;
    default:
        QGraphicsView::keyPressEvent(event);
        break;
    }
}
