#include "myinccomm.h"

myIncComm::myIncComm(piggyButton * PB)
{
    pigbutt = PB;
}

void myIncComm::redo()
{
    pigbutt->increment();
}

void myIncComm::undo()
{
    pigbutt->decrement();
}

