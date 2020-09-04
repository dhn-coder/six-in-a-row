#ifndef CHESSWIDGET_H
#define CHESSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "game.h"

namespace Ui {
class chessWidget;
}

class chessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit chessWidget(QWidget *parent = 0);
    ~chessWidget();

    void changeWin1();
    void deal1();

private:
    Ui::chessWidget *ui;
    QPushButton b3;
    QPushButton b4;

    game w;

protected:
    void paintEvent(QPaintEvent *);

};

#endif // CHESSWIDGET_H
