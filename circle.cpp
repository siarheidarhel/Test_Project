#include "circle.h"
#include <QPainter>




Circle::Circle(QPointF point, QPointF point2, QGraphicsItem *parent) : QGraphicsEllipseItem(parent)
{

   setFlag(QGraphicsItem::ItemIsSelectable,true);
   setFlag(QGraphicsItem::ItemSendsScenePositionChanges,true);
   setFlag(QGraphicsItem::ItemSendsGeometryChanges,true );


    start_p=point;
    end_p=point2;
    myPolygon << QPointF(-100, -100) << QPointF(100, -100)
              << QPointF(100, 100) << QPointF(-100, 100)
              << QPointF(-100, -100);

}


Circle::~Circle()
{

}

QRectF Circle::boundingRect() const
{
     QRectF rect (start_p.x(),start_p.y(),(end_p.x())-start_p.x(),(end_p.y())-start_p.y());


    return rect;



}

void Circle::addLine(Line *myLineClass)
{
    myLinesCont.append(myLineClass);
}





void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    auto w=end_p.x()-start_p.x();
    auto h=end_p.y()-start_p.y();


    QRectF myElips(start_p.x()+5,start_p.y()+5,w-10,h-10);



      painter->setPen(QPen(Qt::red, 1));
     // painter->setBrush(QBrush(Qt::darkCyan));

      painter->drawEllipse(myElips);
if(isSelected()){

       painter->setPen(QPen(Qt::black, 1, Qt::DashLine));
      // painter->setBrush(QBrush(Qt::red));

      painter->drawRect(this->boundingRect());
       // painter->drawEllipse(myElips);
        //painter->eraseRect(myElips);
}





}

QVariant Circle::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{

qDebug()<<Q_FUNC_INFO;
    if (change == QGraphicsItem::ItemPositionChange) {
        for (Line *myLineClass : qAsConst(myLinesCont))
            myLineClass->updatePosition();
    }

    return value;
}

