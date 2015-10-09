#include "mymainwindow.h"

myMainWindow::myMainWindow()
{
    setup();

//    This initializes the menu actions
    assign();

//    Assign functionality to each of the buttons
    for(int i = 0; i < 6; i++) {
        QObject::connect(buttongroup->button(i),SIGNAL(clicked(bool)),
                this, SLOT(assign()));
    }

    this->show();
}

void myMainWindow::setup(void){
    QWidget *outer = new QWidget();

    this->setCentralWidget(outer);
    buttongroup = new QButtonGroup(this);

    makeMenus();

  //  make the piggy buttons
    piggyButton *marketPiggy = new piggyButton("market piggy");
    piggyButton *homePiggy = new piggyButton("home piggy");
    piggyButton *gluttonPiggy = new piggyButton("glutton piggy");
    piggyButton *dietingPiggy = new piggyButton("dieting piggy");
    piggyButton *whinyPiggy = new piggyButton("whiny piggy");
    piggyButton *wolverinePiggy = new piggyButton("wolverine piggy");

    marketPiggy->setCheckable(true);
    marketPiggy->setChecked(true);



  //  make the quit button with functionality
    QPushButton *quit = new QPushButton("quit");
    QObject::connect(quit,SIGNAL(clicked()), this, SLOT(close()));

    QGridLayout *gridlayout = new QGridLayout;
    buttongroup->addButton(marketPiggy, 0);
    buttongroup->addButton(gluttonPiggy, 1);
    buttongroup->addButton(whinyPiggy, 2);
    buttongroup->addButton(homePiggy, 3);
    buttongroup->addButton(dietingPiggy, 4);
    buttongroup->addButton(wolverinePiggy, 5);
    buttongroup->addButton(quit, 6);

    buttongroup->setExclusive(true);

    gridlayout->addWidget(quit, 3, 0, 1, 2, Qt::AlignCenter);
    quit->setMinimumWidth(150);

    gridlayout->addWidget(buttongroup->button(0), 0, 0);
    gridlayout->addWidget(buttongroup->button(1), 1, 0);
    gridlayout->addWidget(buttongroup->button(2), 2, 0);
    gridlayout->addWidget(buttongroup->button(3), 0, 1);
    gridlayout->addWidget(buttongroup->button(4), 1, 1);
    gridlayout->addWidget(buttongroup->button(5), 2, 1);
    outer->setLayout(gridlayout);


    //    Make the undo/redo stack!
     myStack = new QUndoStack();
     myBackStack = new QUndoStack();


}

void myMainWindow::makeMenus() {
    menubar = new QMenuBar();

//    Actions Menu Bar
    actions = new QMenu("Actions");

    inc = new QAction(menubar);
    dec = new QAction(menubar);
    printMenu = new QAction(menubar);
    inc->setText("Increment");
    dec->setText("Decrement");
    printMenu->setText("Print Amount");
    inc->setShortcut(Qt::CTRL + Qt::Key_I);
    dec->setShortcut(Qt::CTRL + Qt::Key_D);
    printMenu->setShortcut(Qt::CTRL + Qt::Key_P);
    actions->addAction(inc);
    actions->addAction(dec);
    actions->addAction(printMenu);

//    Edit Menu Bar
    edit = new QMenu("Edit");

    undo = new QAction(menubar);
    redo = new QAction(menubar);
    undo->setText("Undo");
    redo->setText("Redo");
    undo->setDisabled(true);
    redo->setDisabled(true);
    undo->setShortcut(Qt::CTRL + Qt::Key_Z);
    redo->setShortcut(Qt::CTRL + Qt::Key_Y);
    edit->addAction(undo);
    edit->addAction(redo);

//    File Menu Bar
    file = new QMenu(" File");

    open = new QAction(menubar);
    save = new QAction(menubar);
    saveas = new QAction(menubar);
    quitMenu = new QAction(menubar);

    open->setText(" Open");
    save->setText(" Save");
    saveas->setText(" Save As");
    quitMenu->setText(" Quit"); // need to override this

    open->setDisabled(true);
    save->setDisabled(true);
    saveas->setDisabled(true);

    file->addAction(open);
    file->addAction(save);
    file->addAction(saveas);
    file->addAction(quitMenu);

    QObject::connect(quitMenu,SIGNAL(triggered()),
                     this, SLOT(close()));

//    Add menues to head menu bar
    menubar->addMenu(file);
    menubar->addMenu(edit);
    menubar->addMenu(actions);

    this->setMenuBar(menubar);

}

void myMainWindow::assign(){

    inc->disconnect();
    dec->disconnect();
    printMenu->disconnect();
    undo->disconnect();
    redo->disconnect();

//    Connect inc and dec to addingToStack functions
    QObject::connect(inc,SIGNAL(triggered()),
                     this, SLOT(addIncToStack()));
    QObject::connect(dec,SIGNAL(triggered()),
                     this, SLOT(addDecToStack()));

//    Connet print directly to piggyButton
    QObject::connect(printMenu,SIGNAL(triggered()),
                     qobject_cast<piggyButton *>( buttongroup->checkedButton()), SLOT(printOut()));


//    Connect undo/redo actions to this window functions? idk
    QObject::connect(undo,SIGNAL(triggered()),
                     this, SLOT(undoMystack()));
    QObject::connect(redo,SIGNAL(triggered()),
                     this, SLOT(redoMystack()));



}

void myMainWindow::addIncToStack() {
    myBackStack->clear();
    myIncComm * myInc = new myIncComm(qobject_cast<piggyButton *>( buttongroup->checkedButton()));
    myStack->push(myInc);
    undo->setEnabled(true);
    redo->setEnabled(false);



}

void myMainWindow::addDecToStack() {
    myBackStack->clear();
    myDecComm * myDec = new myDecComm(qobject_cast<piggyButton *>( buttongroup->checkedButton()));
    myStack->push(myDec);
    undo->setEnabled(true);
    redo->setEnabled(false);
}

void myMainWindow::undoMystack() {
//    qobject_cast<piggyButton *>(myStack->command(myStack->index()))->setChecked(true);

//    myStack->command(myStack->index())->
    myStack->undo();
    redo->setEnabled(true);

    if(!myStack->canUndo())
    {
        undo->setDisabled(true);
    }



}

void myMainWindow::redoMystack() {
    myStack->redo();

    undo->setEnabled(true);

    if(!myStack->canRedo())
    {
        redo->setDisabled(true);
    }

}
