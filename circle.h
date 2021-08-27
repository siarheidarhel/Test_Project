#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsItem>
#include <QObject>
#include <line.h>
#include <QPolygonF>





class Line;
class Circle : public QObject, public QGraphicsEllipseItem
{

Q_OBJECT
QPointF start_p;
QPointF end_p;
QPolygonF myPolygon;

QRectF myElips;
 QList<Line *> myLinesCont;
public:







public:
    Circle(QPointF point,QPointF point2, QGraphicsItem *parent=nullptr);
    ~Circle();
   // Line* myLineClass=nullptr;

    virtual QRectF boundingRect() const override;
   QPolygonF polygon() const { return myPolygon; }
   void addLine(Line *myLineClass);




   virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
};

#endif // CIRCLE_H
