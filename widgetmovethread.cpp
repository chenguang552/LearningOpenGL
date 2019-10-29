#include "widgetmovethread.h"

widgetmovethread::widgetmovethread(){}

widgetmovethread::~widgetmovethread(){}

void widgetmovethread::run()
{
    while(1)
    {
        qsrand(time(NULL));
        sleep(qrand()%20+5);

        int x = qrand();
        int y = qrand();
        emit moveToPos(x,y);
    }
}
