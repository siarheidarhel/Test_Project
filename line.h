



#ifndef LINE_H
#define LINE_H
#include <QGraphicsLineItem>
#include <QPainterPath>
#include<circle.h>



class Circle;
class Line : public QGraphicsLineItem
{


    QPointF start_p;
    QPointF end_p;

    Circle *mystartItem;
    Circle *myendItem;
   // QLineF centerLine;


 QColor myColor = Qt::black;




public:
    Line(Circle *start, Circle *end, QGraphicsItem *parent=nullptr);
    ~Line();



    virtual QPainterPath shape() const override;

    QRectF boundingRect() const override;

    Circle *start() const { return mystartItem; }
    Circle *end() const { return myendItem; }

    void updatePosition();






protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;







};

#endif // LINE_H
