#ifndef MYDECCOMM_H
#define MYDECCOMM_H

#include "piggybutton.h"

class myDecComm : public QUndoCommand
{
public:
    myDecComm(piggyButton * PB);
    piggyButton * pigbutt;

signals:

public slots:
    void redo();
    void undo();
};

#endif // MYDECCOMM_H
