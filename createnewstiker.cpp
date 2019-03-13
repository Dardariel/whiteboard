#include "createnewstiker.h"
#include "ui_createnewstiker.h"

CreateNewStiker::CreateNewStiker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateNewStiker)
{
    Brush = new QBrush;
    Text = new QString;
    Ok = new bool;

    ui->setupUi(this);

    setWindowTitle("Create new stiker");

    connect(ui->pb_create, SIGNAL(clicked()), SLOT(slotCreate()));
    connect(ui->pb_cancel, SIGNAL(clicked()), SLOT(slotCancel()));
}

CreateNewStiker::~CreateNewStiker()
{
    delete ui;
}
void CreateNewStiker::slotCreate()
{
    *Text=ui->te_text->toPlainText();

    if(ui->rb_yellow->isChecked())
    {
        *Brush=Qt::yellow;
    }
    else if(ui->rb_blue->isChecked())
    {
        *Brush=QBrush(QColor(0, 191, 255));
    }
    else if(ui->rb_lime->isChecked())
    {
        *Brush=QBrush(QColor(153, 255, 153));
    }
    else if(ui->rb_pink->isChecked())
    {
        *Brush=QBrush(QColor(255, 203, 219));
    }
    else if(ui->rb_orange->isChecked())
    {
        *Brush=QBrush(QColor(255,140,0));
    }

    if(Text->length())
    {
        *Ok=true;
        close();
    }

}
void CreateNewStiker::slotCancel()
{
    *Ok=false;
    close();
}
