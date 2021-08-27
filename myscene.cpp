#include "myscene.h"
#include <QGraphicsSceneMouseEvent>
#include <circle.h>
#include <figureTypes.h>
#include <line.h>
#include <QGraphicsView>


MyScene::MyScene(QObject *parent)
    : QGraphicsScene(parent)



{
    myCircleClass=nullptr;
    myLineClass=nullptr;
    //figureType_ = myMove;

    line = nullptr;





}


MyScene::~MyScene()
{


}



void MyScene::setFigureType(int figureType)
{
    figureType_=figureType;
}





void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     qDebug()<<Q_FUNC_INFO;


    if (event->buttons() !=Qt::LeftButton){return;}
    else{

    switch (figureType_)
    {
           case myCircle:
                       start_point=event->scenePos();
                       break;

           case myLine:

                     line = new QGraphicsLineItem(QLineF(event->scenePos(),event->scenePos()));

                      addItem(line);
                      break;

           case myMove:
                  start_point=(event->scenePos());

                if(itemAt(event->scenePos(),QTransform())==nullptr) {return;}

                mytemp= qgraphicsitem_cast<QGraphicsItem*>(itemAt(event->scenePos(),QTransform()));
                qDebug()<<mytemp->type();
                mytemp->setCursor(Qt::ClosedHandCursor);
                mytemp->setFlag(QGraphicsItem::ItemIsSelectable,true);
                mytemp->setFlag(QGraphicsItem::ItemIsMovable,true);
                break;





     }//__________switch


 }// statement

    QGraphicsScene::mousePressEvent(event);


}








void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    qDebug()<<Q_FUNC_INFO;

    switch (figureType_)
    {
       case myCircle: myCircleClass=nullptr; break;
       case myLine:{

     if (line != nullptr && figureType_==myLine ) {
           qDebug()<<"Enter Line";
       QList<QGraphicsItem *> startItems =this-> items(line->line().p1());
           qDebug()<<startItems;
           if (startItems.count() && startItems.first() == line)
               startItems.removeFirst();
           QList<QGraphicsItem *> endItems =this-> items(line->line().p2());
           if (endItems.count() && endItems.first() == line)
               endItems.removeFirst();

        removeItem(line);
         delete line;



           if (startItems.count() > 0 && endItems.count() > 0 &&
              startItems.first()->type() == Circle::Type &&
               endItems.first()->type() == Circle::Type &&
                startItems.first() != endItems.first()) {
               qDebug()<<startItems;
                qDebug()<<endItems;
               Circle *startItemC = qgraphicsitem_cast<Circle *>(startItems.first());
                Circle *endItemC = qgraphicsitem_cast<Circle *>(endItems.first());
             Line *myLineClassC = new Line(startItemC,endItemC);
             startItemC->addLine(myLineClassC);
             endItemC->addLine(myLineClassC);
             addItem(myLineClassC);
             myLineClassC->updatePosition();
           }
      }






                        } break;



    case myMove:
                    if(mytemp==nullptr){return;}
                    else {

                            mytemp->setCursor(Qt::ArrowCursor);
                            mytemp->setFlag(QGraphicsItem::ItemIsMovable,false);

                            mytemp=nullptr;
                            break;
                          }//____//else
      }//____switch



   // delete
    line = nullptr;
    QGraphicsScene::mouseReleaseEvent(event);
}



void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
qDebug()<<Q_FUNC_INFO;

    if (event->buttons() != Qt::LeftButton){ event->ignore(); return;}


    else{

        end_point=event->scenePos();

          switch (figureType_) {

            case myCircle:

                      if(myCircleClass){delete myCircleClass;}
                       myCircleClass=new Circle(start_point,end_point);
                       myCircleClass->setRect(myCircleClass->boundingRect());
                       addItem(myCircleClass);
                      // myCircleClass->setSelected(true);
                       update();
                       break;



           case myLine:{


                       QLineF newLine(line->line().p1(), event->scenePos());
                       line->setLine(newLine);




          }break;

            case myMove:
                       if(mytemp==nullptr){return;}
                       QRectF bbox = mytemp->boundingRect().normalized();

                       mytemp->setPos( event->scenePos()-bbox.center());



                       this->update();
                        break;


          }//______switch


  }//esle statement


QGraphicsScene::mouseMoveEvent(event);
}







