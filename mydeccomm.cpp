#include "mydeccomm.h"

myDecComm::myDecComm(piggyButton * PB)
{
    pigbutt = PB;
}

void myDecComm::redo()
{
    pigbutt->decrement();
}

void myDecComm::undo()
{
    pigbutt->increment();
}

