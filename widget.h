#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QString& host, QWidget *parent = nullptr);
    ~Widget();

protected:
    virtual void resizeEvent(QResizeEvent *event);
};
#endif // WIDGET_H
