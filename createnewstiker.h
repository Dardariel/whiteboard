#ifndef CREATENEWSTIKER_H
#define CREATENEWSTIKER_H

#include <QDialog>

namespace Ui {
class CreateNewStiker;
}

class CreateNewStiker : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewStiker(QWidget *parent = nullptr);
    ~CreateNewStiker();


    QBrush *Brush;
    QString *Text;
    bool *Ok;


public slots:
    void slotCreate();
    void slotCancel();

private:
    Ui::CreateNewStiker *ui;
};

#endif // CREATENEWSTIKER_H
