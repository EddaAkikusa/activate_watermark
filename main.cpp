#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString host;
    if (argc > 1) {
        host = argv[1];
    } else {
        host = "Ubuntu";
    }
    Widget w(host);
    w.show();
    return a.exec();
}
