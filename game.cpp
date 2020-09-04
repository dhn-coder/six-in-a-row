#include "game.h"
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QBrush>
#include <QMessageBox>
//#include <QPushButton>


game::game(QWidget *parent) : QWidget(parent)
{
    resize(700,700);
    this->setWindowTitle("游戏界面");
    b.setParent(this);
    b.setText("返回");
    b.move(width()/22,0);

    connect(&b, &QPushButton::released, this, &game::sendSlot1);

    gridW = width()/24;
    gridH = height()/22;

    memset(a, 0, sizeof(a));
    player=0;
}

void game::sendSlot1()
{
    emit Signal1();
}

void game::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing,true);
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/棋盘.png"));
    QPen pen;
    pen.setWidth(2);
    p.setPen(pen);

    for(int i = 0; i <= 20; i++)
    {
        p.drawLine(gridW, gridH+i*gridH, gridW+20*gridW, gridH+i*gridH);
        p.drawLine(gridW+i*gridW, gridH, gridW+i*gridW, gridH+20*gridH);
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    int i, j;
    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 20; j++)
        {
            if(a[i][j] == 1)
            {
                brush.setColor(Qt::black);
                p.setBrush(brush);
                p.drawEllipse(QPoint((i+1)*gridW,(j+1)*gridH),gridW*0.4, gridH*0.4);
            }
            else if(a[i][j] == 2)
            {
                brush.setColor(Qt::white);
                p.setBrush(brush);
                p.drawEllipse(QPoint((i+1)*gridW,(j+1)*gridH),gridW*0.4, gridH*0.4);
            }
        }
    }
}


void game::mousePressEvent(QMouseEvent *e)
{   int x,y;
    if(e->x() >= gridW && e->x() <= gridW*21 && e->y() >= gridH && e->y() <= gridH*21)
    {
        x = e->x()/gridW - 1;
        y = e->y()/gridH - 1;
        if(!a[x][y])
        {
            a[x][y] = player++ % 2 + 1;
        }
        if(isWin(x,y))
        {
            if(a[x][y] == 1)
            {
                QMessageBox::information(this,"南理六子棋Gameover","Blackchess Win!!",QMessageBox::Ok);
            }
            if(a[x][y] == 2)
            {
                QMessageBox::information(this,"南理六子棋Gameover","Whitechess Win!!",QMessageBox::Ok);
            }
            memset(a, 0, sizeof(a));
            update();
        }
    }
    update();
}

int game::isWin(int x, int y)
{
    return f1(x,y) || f2(x,y) || f3(x,y) || f4(x,y);
}

int game::f1(int x, int y)
{
    int i;
    for(i = 0; i < 6; i++)
    {
        if(y - i >= 0 &&
           y + 5 - i <= 20 &&
           a[x][y-i] == a[x][y+1-i] &&
           a[x][y-i] == a[x][y+2-i] &&
           a[x][y-i] == a[x][y+3-i] &&
           a[x][y-i] == a[x][y+4-i] &&
           a[x][y-i] == a[x][y+5-i]  )
         return 1;
    }
    return 0;
}

int game::f2(int x, int y)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        if(x - i >= 0 &&
           x + 5 - i <= 20 &&
           a[x - i][y] == a[x + 1 - i][y] &&
           a[x - i][y] == a[x + 2 - i][y] &&
           a[x - i][y] == a[x + 3 - i][y] &&
           a[x - i][y] == a[x + 4 - i][y] &&
           a[x - i][y] == a[x + 5 - i][y])
           return 1;
    }
    return 0;
}

int game::f3(int x, int y)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        if(x - i >= 0 &&
           y - i >= 0 &&
           x + 5 - i <= 20 &&
           y + 5 - i <= 20 &&
           a[x - i][y - i] == a[x + 1 - i][y + 1 - i] &&
           a[x - i][y - i] == a[x + 2 - i][y + 2 - i] &&
           a[x - i][y - i] == a[x + 3 - i][y + 3 - i] &&
           a[x - i][y - i] == a[x + 4 - i][y + 4 - i] &&
           a[x - i][y - i] == a[x + 5 - i][y + 5 - i])
           return 1;
    }
    return 0;
}

int game::f4(int x, int y)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        if(x + i <= 20 &&
           y - i >= 0 &&
           x - 5 + i >= 0 &&
           y + 5 - i <= 20 &&
           a[x + i][y - i] == a[x - 1 + i][y + 1 - i] &&
           a[x + i][y - i] == a[x - 2 + i][y + 2 - i] &&
           a[x + i][y - i] == a[x - 3 + i][y + 3 - i] &&
           a[x + i][y - i] == a[x - 4 + i][y + 4 - i] &&
           a[x + i][y - i] == a[x - 5 + i][y + 5 - i])
           return 1;
    }
    return 0;
}









