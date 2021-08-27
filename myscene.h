#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QPointF>
#include <circle.h>
#include <line.h>
#include <QList>
#include <QGraphicsSceneMouseEvent>






class MyScene : public QGraphicsScene
{
    Q_OBJECT



    QPointF start_point;
    QPointF end_point;


    int figureType_=-1;



    QGraphicsItem *mytemp=nullptr;

    QGraphicsItem *startItem=nullptr;
    QGraphicsItem *endItem=nullptr;

    Circle *startItemC;
   Circle *endItemC;

    QGraphicsLineItem *line;

    QList<QGraphicsItem*> myList;




public:
    explicit MyScene (QObject *obj=nullptr );
   ~MyScene();
    Circle *myCircleClass;
    Line *myLineClass;

void setFigureType(int figureType);
bool isItemChange(int type) const;






    // QGraphicsScene interface

     void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

     void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

      void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // MYSCENE_H

















