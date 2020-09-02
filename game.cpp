#include "game.h"
#include <QPainter>
#include <QPen>
#include <QMouseEvent>

game::game(QWidget *parent) : QWidget(parent)
{
    resize(700,700);
    this->setWindowTitle("游戏界面");
    b.setParent(this);
    b.setText("返回");

    connect(&b, &QPushButton::released, this, &game::sendSlot1);
}

void game::sendSlot1()
{
    emit Signal1();
}

void game::paintEvent(QPaintEvent *)
{
    gridW = width()/20; //窗口分20份
    gridH = height()/20;
    //棋盘起点坐标
    startX = gridW;
    startY = gridH;

    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/棋盘.png"));   //背景
    QPen pen;
    pen.setWidth(2);    //线宽
    p.setPen(pen);

    for(int i = 0; i <= 18; i++)
    {
        p.drawLine(startX, startY+i*gridH, startX+18*gridW, startY+i*gridH);
        p.drawLine(startX+i*gridW, startY, startX+i*gridW, startY+18*gridH);
    }
}
