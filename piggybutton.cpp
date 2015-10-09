#include "piggybutton.h"

piggyButton::piggyButton(int num, QString title, QString message)
{
    yell = new QMessageBox();
    QString temp = "button ";
    temp += QString::number(num);
    temp += ": ";
    message = temp + message;
    yell->setText(message);
    this->setText(title);

    QObject::connect(this,SIGNAL(clicked()), this, SLOT(boxUp()));



}

void piggyButton::boxUp(void)
{
   yell->show();
}


