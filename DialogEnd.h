#ifndef DIALOGEND_H
#define DIALOGEND_H
#include <QDialog>
#include "Game.h"
#include <QGraphicsScene>
namespace Ui {
class DialogEnd;
}

class DialogEnd : public QDialog, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit DialogEnd(QWidget *parent = nullptr);
    ~DialogEnd();

private slots:
    void on_newGame_clicked();

    void on_Exit_clicked();

private:
    Ui::DialogEnd *ui;
};

#endif // DIALOGEND_H
