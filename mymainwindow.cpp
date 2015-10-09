#include "mymainwindow.h"

myMainWindow::myMainWindow()
{
//    QMainWindow *mainwindow = new QMainWindow();
    QWidget *outer = new QWidget();

    this->setCentralWidget(outer);


  //  make the piggy buttons
    piggyButton *marketPiggy = new piggyButton( 1, "market piggy", "this little piggy went to market");
    piggyButton *homePiggy = new piggyButton(2, "home piggy", "this little piggy stayed home");
    piggyButton *gluttonPiggy = new piggyButton(3, "glutton piggy", "this little piggy ate roast beef");
    piggyButton *dietingPiggy = new piggyButton(4, "dieting piggy", "this little piggy ate none");
    piggyButton *whinyPiggy = new piggyButton(5, "whiny piggy", "this little piggy cried wee wee wee");
    piggyButton *wolverinePiggy = new piggyButton(6, "wolverine piggy", "this little piggy has health issues");

  //  make the quit button with functionality
    QPushButton *quit = new QPushButton("quit");
    QObject::connect(quit,SIGNAL(clicked()), this, SLOT(close()));


    QGridLayout *gridlayout = new QGridLayout;
    gridlayout->addWidget(marketPiggy, 0, 0);
    gridlayout->addWidget(gluttonPiggy, 1, 0);
    gridlayout->addWidget(whinyPiggy, 2, 0);
    gridlayout->addWidget(homePiggy, 0, 1);
    gridlayout->addWidget(dietingPiggy, 1, 1);
    gridlayout->addWidget(wolverinePiggy, 2, 1);
    gridlayout->addWidget(quit, 3, 0, 1, 2, Qt::AlignCenter);

    quit->setMinimumWidth(150);


    outer->setLayout(gridlayout);
//    mainwindow->show();
}

