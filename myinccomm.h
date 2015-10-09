#ifndef MYINCCOMM_H
#define MYINCCOMM_H

#include "piggybutton.h"

class myIncComm : public QUndoCommand
{
public:
    myIncComm(piggyButton * PB);
    piggyButton * pigbutt;

signals:

public slots:
    void redo();
    void undo();
};

#endif // MYINCCOMM_H
