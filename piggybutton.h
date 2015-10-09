#ifndef PIGGYBUTTON_H
#define PIGGYBUTTON_H

#include <QWidget>
#include <QtGui>
#include <QtWidgets>
#include <QGridLayout>

class piggyButton : public QPushButton
{
    Q_OBJECT
public:
   explicit piggyButton( int num=0, QString title = "title", QString message = "message");
    QMessageBox *yell;

public slots:
    void boxUp(void);

signals:

};


#endif // PIGGYBUTTON_H
