#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include <QGraphicsTextItem>

class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();



    void setColorMarker(QBrush brush);
    void setColorStiker(QBrush brush);

    void setEnablePen(bool);

    void setNewStiker(QString text);


private:
    QPointF     previousPoint;      // Координаты предыдущей точки

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    bool Enable_pen, Run_pen;
    bool Run_stiker;
    QPen Pen;
    QBrush Brush_pen, Brush_stiker;
    uint Round_pen;

    QGraphicsTextItem *itemText;

};

#endif // PAINTSCENE_H
