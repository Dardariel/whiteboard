#include "paint.h"
#include "ui_paint.h"
#include <QRadioButton>
#include <QGraphicsTextItem>
#include "createnewstiker.h"

Paint::Paint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Paint)
{
    ui->setupUi(this);

    ui->pb_addNewStiker->setEnabled(false);

    scene = new paintScene();       // Инициализируем графическую сцену
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену

    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &Paint::slotTimer);
    timer->start(100);          // Запускаем таймер

    connect(ui->rb_green, SIGNAL(clicked()), SLOT(slotGetColor()));
    connect(ui->rb_blue, SIGNAL(clicked()), SLOT(slotGetColor()));
    connect(ui->rb_black, SIGNAL(clicked()), SLOT(slotGetColor()));
    connect(ui->rb_red, SIGNAL(clicked()), SLOT(slotGetColor()));
    connect(ui->rb_orange, SIGNAL(clicked()), SLOT(slotGetColor()));
    connect(ui->rb_stiker, SIGNAL(clicked()), SLOT(slotStiker()));

    connect(ui->pb_clear, SIGNAL(clicked()), SLOT(slotClear()));

    connect(ui->pb_addNewStiker, SIGNAL(clicked()), SLOT(slotAddStiker()));
}

Paint::~Paint()
{
    delete ui;
}

void Paint::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void Paint::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}
void Paint::slotGetColor()
{
    scene->setEnablePen(true);
    ui->pb_addNewStiker->setEnabled(false);
    if(ui->rb_green->isChecked())
    {
        scene->setColorMarker(Qt::green);
    }
    else if(ui->rb_blue->isChecked())
    {
        scene->setColorMarker(Qt::blue);
    }
    else if(ui->rb_black->isChecked())
    {
        scene->setColorMarker(Qt::black);
    }
    else if(ui->rb_red->isChecked())
    {
        scene->setColorMarker(Qt::red);
    }
    else if(ui->rb_orange->isChecked())
    {
        scene->setColorMarker(QBrush(QColor(255,140,0)));
    }

}
void Paint::slotStiker()
{
    scene->setEnablePen(false);
    ui->pb_addNewStiker->setEnabled(true);
}

void Paint::slotClear()
{
    scene->clear();
}
void Paint::slotAddStiker()
{
    QBrush brush;
    QString text;
    bool ok;
    CreateNewStiker *cns = new CreateNewStiker(this);
    cns->Ok=&ok;
    cns->Brush=&brush;
    cns->Text=&text;

    cns->exec();


    if(ok)
    {
        scene->setColorStiker(brush);
        scene->setNewStiker(text);
    }
}
