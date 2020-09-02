#include "chesswidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chessWidget w;
    w.show();
    w.setWindowTitle("南理六子棋2.0plus");

    return a.exec();
}
