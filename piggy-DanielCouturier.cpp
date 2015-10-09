#include <QtGui>
#include <QtWidgets>
#include <QGridLayout>
#include "piggybutton.h"
#include "mymainwindow.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  myMainWindow *myMain = new myMainWindow();
  myMain->show();
  return app.exec();
}
