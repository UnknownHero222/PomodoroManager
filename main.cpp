#include "pomodoro_manager_wdg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PomodoroManagerWdg w;
    w.show();
    return a.exec();
}
