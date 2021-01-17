#ifndef POMODOROMANAGERWDG_H
#define POMODOROMANAGERWDG_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PomodoroManagerWdg; }
QT_END_NAMESPACE

class PomodoroManagerWdg : public QMainWindow
{
    Q_OBJECT

public:
    PomodoroManagerWdg(QWidget *parent = nullptr);
    ~PomodoroManagerWdg();

private:
    Ui::PomodoroManagerWdg *ui;
};
#endif // POMODOROMANAGERWDG_H
