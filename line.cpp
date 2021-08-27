#include "line.h"
#include <QPainter>
#include "circle.h"
#include <QPainter>
#include <QPen>
#include <QtMath>




Line::Line(Circle *start, Circle *end, QGraphicsItem *parent):QGraphicsLineItem (parent)
{
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setPen(QPen(myColor, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
qDebug()<<"Line Class";
mystartItem=start;
myendItem=end;
setLine(QLineF(mystartItem->boundingRect().center(),myendItem->boundingRect().center()));


}


Line::~Line()
{


}





QRectF Line::boundingRect() const
{
   // return QRectF  (start_p.x(),start_p.y(),(end_p.x())-start_p.x(),(end_p.y())-start_p.y());
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);

}

void Line::updatePosition()
{
 qDebug()<<Q_FUNC_INFO;

        QLineF line(mapFromItem(mystartItem, mystartItem->boundingRect().center().x(),mystartItem->boundingRect().center().y()),
                    mapFromItem(myendItem, myendItem->boundingRect().center().x(),myendItem->boundingRect().center().y()));
        setLine(line);

}

QPainterPath Line::shape() const
{
 qDebug()<<Q_FUNC_INFO;



   QPainterPath path = QGraphicsLineItem::shape();


   return path;

}









void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget)
{
    qDebug()<<"Paint Line Class";
    Q_UNUSED(option);
    Q_UNUSED(widget);
   if (mystartItem->collidesWithItem(myendItem))
       return;

    QPen myPen;

   myPen.setWidth(2);

   painter->setPen(myPen);

//setLine(QLineF( mystartItem->pos(),myendItem->pos()));  qDebug()<<"SetLine";


   painter->drawLine(line());

    if (isSelected()) {
        painter->setPen(QPen(myColor, 1, Qt::DashLine));
        QLineF myLine = line();
        myLine.translate(0, 4.0);
        painter->drawLine(myLine);
        myLine.translate(0,-8.0);
        painter->drawLine(myLine);
    }
}






