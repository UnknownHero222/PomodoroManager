#include "pomodoro_manager_wdg.h"
#include "./ui_pomodoro_manager_wdg.h"

PomodoroManagerWdg::PomodoroManagerWdg(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PomodoroManagerWdg)
{
    ui->setupUi(this);
}

PomodoroManagerWdg::~PomodoroManagerWdg()
{
    delete ui;
}

