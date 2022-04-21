#include "widget.h"
#include <QApplication>
#include <QLabel>
#include <QScreen>
#include <QSizePolicy>
#include <QVBoxLayout>

Widget::Widget(QString& host, QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowTransparentForInput);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);
    setFocusPolicy(Qt::NoFocus);

    QVBoxLayout* vBox { new QVBoxLayout(this) };
    QFont font;
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::transparent);
    palette.setColor(QPalette::WindowText, QColor(255, 255, 255, 200));

    QLabel* line1 { new QLabel("激活 " + host) };
    font = line1->font();
    font.setPixelSize(21);
    line1->setFont(font);
    line1->setPalette(palette);

    QString setting = "设置";
    if (host == "macOS") {
        setting = "系统偏好设置";
    }
    QLabel* line2 { new QLabel("转到“" + setting + "”以激活 " + host + "。") };
    font = line2->font();
    font.setPixelSize(15);
    line2->setFont(font);
    line2->setPalette(palette);

    vBox->addWidget(line1);
    vBox->addWidget(line2);

    line1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    line2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}

void Widget::resizeEvent(QResizeEvent *event)
{
    QScreen* screen { QGuiApplication::primaryScreen() };
    QRect geometry { screen->geometry() };

    move(geometry.width() - width() - 40, geometry.height() - height() - 40);

    QWidget::resizeEvent(event);
}

Widget::~Widget()
{
}

