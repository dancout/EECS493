#ifndef PIGGYBUTTON_H
#define PIGGYBUTTON_H

#include <QWidget>
#include <QtGui>
#include <QtWidgets>
#include <QGridLayout>
#include <iostream>

using namespace std;

class piggyButton : public QPushButton
{
    Q_OBJECT
public:
   explicit piggyButton( QString inTitle = "title");
    int num;
    QString title;

public slots:
    void boxUp(void);
    void increment(void);
    void decrement(void);
    void printOut(void);

signals:

};


#endif // PIGGYBUTTON_H
