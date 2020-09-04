#include "chesswidget.h"
#include "ui_chesswidget.h"
#include <QPainter>
#include <QPen>
//#include <QMouseEvent>

chessWidget::chessWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chessWidget)
{
    ui->setupUi(this);

    resize(700,700);
    //setWindowTitle("六子棋");
    b3.setParent(this);
    b3.setText("开始游戏");
    b3.move(50,50);
    b4.setParent(this);
    b4.setText("退出游戏");
    b4.move(50,100);

    connect(&b3, &QPushButton::released, this, &chessWidget::changeWin1);
    connect(&b4, &QPushButton::released, this, &chessWidget::close);
    connect(&w, &game::Signal1, this, &chessWidget::deal1);
}

void chessWidget::changeWin1()
{
    w.show();
    this->hide();
}

void chessWidget::deal1()
{
    w.hide();
    this->show();
}

chessWidget::~chessWidget()
{
    delete ui;
}

void chessWidget::paintEvent(QPaintEvent *)
{
    QPainter q(this);
    q.drawPixmap(0, 0, width(), height(), QPixmap(":/六子棋.png"));
}
