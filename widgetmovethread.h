#ifndef WIDGETMOVETHREAD_H
#define WIDGETMOVETHREAD_H

#include <QThread>
#include <ctime>

class widgetmovethread: public QThread
{
     Q_OBJECT
public:
    widgetmovethread();
    ~widgetmovethread();

protected:
    void run();

signals:
    void moveToPos(int,int);
};

#endif // WIDGETMOVETHREAD_H
