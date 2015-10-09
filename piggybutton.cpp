#include "piggybutton.h"

piggyButton::piggyButton(QString inTitle)
{
    this->num = 0;
    title = inTitle;
    this->setText(QString::number(num) +  " " + title);

    this->setCheckable(true);
    this->setChecked(false);

    QObject::connect(this,SIGNAL(clicked()), this, SLOT(boxUp()));

}

void piggyButton::boxUp(void)
{
   this->setCheckable(true);
   this->setChecked(true);
}

void piggyButton::increment()
{
    this->num++;
    this->setText(QString::number(num) +  " " + title);

//    cout<< this->num << " :  ";
//    cout << this->text().toStdString() << endl;
    this->setChecked(true);

}

void piggyButton::decrement(void)
{
    this->num--;
    this->setText(QString::number(num) +  " " + title);

//    cout<< this->num << " :  ";
//    cout << this->text().toStdString() << endl;
    this->setChecked(true);

}

void piggyButton::printOut(void)
{
    cout << this->text().toStdString() << endl;
}
