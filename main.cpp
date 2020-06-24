#include "pong.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(resource);
    QApplication a(argc, argv);

    PONG *game = new PONG();

    return a.exec();
}
