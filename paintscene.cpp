#include "paintscene.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{
    Enable_pen=true;
    Run_pen=false;
    Run_stiker=false;
    Round_pen=5;
    Brush_pen=Qt::green;
    Brush_stiker=Qt::green;
    Pen=QPen(Brush_pen,Round_pen,Qt::SolidLine,Qt::RoundCap);

}

paintScene::~paintScene()
{

}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // При нажатии кнопки мыши отрисовываем эллипс
    if(Enable_pen)
    {
        Run_pen=true;
        addEllipse(event->scenePos().x() - Round_pen/2,
                   event->scenePos().y() - Round_pen/2,
                   Round_pen,
                   Round_pen,
                   QPen(Qt::NoPen),
                   Brush_pen);
        // Сохраняем координаты точки нажатия
        previousPoint = event->scenePos();
    }
    else if(Run_stiker)
    {
        itemText->setPos(event->scenePos().x(),event->scenePos().y());
        addItem(itemText);
        Run_stiker=false;
    }
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(Enable_pen)
    {
        if(Run_pen)
        {
            // Отрисовываем линии с использованием предыдущей координаты
            addLine(previousPoint.x(),
                    previousPoint.y(),
                    event->scenePos().x(),
                    event->scenePos().y(),
                    Pen);
            // Обновляем данные о предыдущей координате
            previousPoint = event->scenePos();
        }
    }
}
void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Run_pen=false;
}
void paintScene::setEnablePen(bool state)
{
    Enable_pen=state;
}

void paintScene::setColorMarker(QBrush brush)
{
    Brush_pen=brush;
    Pen=QPen(Brush_pen,Round_pen,Qt::SolidLine,Qt::RoundCap);
}
void paintScene::setColorStiker(QBrush brush)
{
    Brush_stiker=brush;
}

void paintScene::setNewStiker(QString text)
{
    Run_stiker=true;
    itemText = new QGraphicsTextItem;
    //itemText
    //itemText->setPlainText(text);




    itemText->setHtml("<div style='background-color:"+Brush_stiker.color().name()+";'><br>" + text.replace('\n',"<br>") + "</div>");



}
