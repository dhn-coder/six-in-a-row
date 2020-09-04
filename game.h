#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>

class game : public QWidget
{
    Q_OBJECT
public:
    explicit game(QWidget *parent = nullptr);

    void sendSlot1();

signals:
    void Signal1();

public slots:

private:
    QPushButton b;

    int gridW;
    int gridH;

    int a[20][20];
    int isWin(int x, int y);
    int f1(int x, int y);
    int f2(int x, int y);
    int f3(int x, int y);
    int f4(int x, int y);
    int player;


protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

};

#endif // GAME_H
