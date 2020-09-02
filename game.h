#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>

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

    int gridW;  //棋盘水平方向一个格子宽度
    int gridH;  //棋盘水平方向一个格子高度
    int startX; //棋盘起点x坐标
    int startY; //棋盘起点y坐标

    int chessX,chessY;  //棋盘下标

protected:
    //重写绘图事件
    void paintEvent(QPaintEvent *);
    //重写鼠标按下事件
    //void mousePressEvent(QMouseEvent *e);

};

#endif // GAME_H
