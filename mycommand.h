#ifndef MYCOMMAND_H
#define MYCOMMAND_H

#include <QWidget>
#include <QtGui>
#include <QtWidgets>
#include <QGridLayout>
#include <iostream>
#include "piggybutton.h"


class myCommand : public QUndoCommand
{
public:
    myCommand(QUndoStack * inStack, QString command, piggyButton * pb);
    piggyButton * pigbutt;
    QUndoStack * myStack;

signals:

public slots:
    void myredo(void);
    void myundo(void);
};

#endif // MYCOMMAND_H
