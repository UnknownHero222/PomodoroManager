#include "pomodoro_manager_wdg.h"

#include "./ui_pomodoro_manager_wdg.h"

static constexpr int kOneMillisecond = 1000;

static constexpr int kWorkMode = 0;
static constexpr int kShortBreakMode = 1;
static constexpr int kLongBreakMode = 2;

/************************************************************************/

PomodoroManagerWdg::PomodoroManagerWdg(QWidget *parent)
    : QMainWindow{parent},
      ui{new Ui::PomodoroManagerWdg},
      timer_{std::make_unique<QTimer>(this)} {
  ui->setupUi(this);
}

/************************************************************************/

PomodoroManagerWdg::~PomodoroManagerWdg() { delete ui; }

/************************************************************************/

void PomodoroManagerWdg::launch() {}

/************************************************************************/

void PomodoroManagerWdg::stop() {}

/************************************************************************/

void PomodoroManagerWdg::on_start_btn_clicked() { launch(); }

/************************************************************************/

void PomodoroManagerWdg::on_stop_btn_clicked() { stop(); }

/************************************************************************/
