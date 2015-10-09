#include <QtGui>
#include <QtWidgets>
#include <QGridLayout>


int main(int argc, char **argv)
{

  QApplication app(argc, argv);

  QWidget *outer = new QWidget();
  QPushButton *marketPiggy = new QPushButton("market piggy");
  QPushButton *gluttonPiggy = new QPushButton("glutton piggy");
  QPushButton *whinyPiggy = new QPushButton("whiny piggy");
  QPushButton *homePiggy = new QPushButton("home piggy");
  QPushButton *dietingPiggy = new QPushButton("dieting piggy");
  QPushButton *wolverinePiggy = new QPushButton("wolverine piggy");
  QPushButton *quit = new QPushButton("quit");



  QGridLayout *gridlayout = new QGridLayout;
  gridlayout->addWidget(marketPiggy, 0, 0);
  gridlayout->addWidget(gluttonPiggy, 1, 0);
  gridlayout->addWidget(whinyPiggy, 2, 0);
  gridlayout->addWidget(homePiggy, 0, 1);
  gridlayout->addWidget(dietingPiggy, 1, 1);
  gridlayout->addWidget(wolverinePiggy, 2, 2);
  gridlayout->addWidget(quit, 3, 1);


  outer->setLayout(gridlayout);



  outer->show();

  return app.exec();
}
