#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QRandomGenerator64>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QString>
#include "Game.h"
#include <QMediaPlayer>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QKeyEvent *event;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool w,a,s,d,space;
    QGraphicsLineItem *WallL;
    QGraphicsLineItem *WallR;
    Bullet *bullet;
    Player *player;







};
#endif // MAINWINDOW_H
