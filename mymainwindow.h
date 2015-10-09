#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include "piggybutton.h"
#include "myinccomm.h"
#include "mydeccomm.h"
class myMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit myMainWindow();
    QButtonGroup *buttongroup;
    QMenuBar *menubar;
    QMenu *actions;
    QMenu *file;
    QMenu *edit;
    QAction *inc;
    QAction *dec;
    QAction *undo;
    QAction *redo;
    QAction *open;
    QAction *save;
    QAction *saveas;
    QAction *quitMenu;
    QAction *printMenu;
    QUndoStack *myStack; // current list of actions done
    QUndoStack *myBackStack; // list of actions that have been undone, taken off stack

signals:

public slots:
    void assign(void);
    void setup(void);
    void makeMenus(void);
    void addIncToStack(void);
    void addDecToStack(void);
    void undoMystack(void);
    void redoMystack(void);
};

#endif // MYMAINWINDOW_H
