#include "pomodoro_manager_wdg.h"

#include <QTime>

#include "./ui_pomodoro_manager_wdg.h"

static constexpr int kOneMillisecond = 1000;

static constexpr int kDefaultWorkMinute = 25;
static constexpr int kDefaultShortBreakMinute = 5;
static constexpr int kDefaultLongBreakMinute = 15;

static constexpr int kWorkMode = 0;
static constexpr int kShortBreakMode = 1;
static constexpr int kLongBreakMode = 2;

/************************************************************************/

PomodoroManagerWdg::PomodoroManagerWdg(QWidget *parent)
    : QMainWindow{parent},
      ui{new Ui::PomodoroManagerWdg},
      timer_{std::make_unique<QTimer>(this)} {
  ui->setupUi(this);

  connect(timer_.get(), &QTimer::timeout, this,
          &PomodoroManagerWdg::update_timer_status);
}

/************************************************************************/

PomodoroManagerWdg::~PomodoroManagerWdg() { delete ui; }

/************************************************************************/

void PomodoroManagerWdg::on_start_btn_clicked() {
  switch (curr_mode_) {
    case kWorkMode:
      remaining_msecs_ = kDefaultWorkMinute;
      curr_mode_ = kShortBreakMode;
      break;
    case kShortBreakMode:
      remaining_msecs_ = kWorkMode;
      curr_mode_ = kShortBreakMode;
      break;
    case kLongBreakMode:
      remaining_msecs_ = kDefaultLongBreakMinute;
      break;
  }
  timer_->start(kOneMillisecond);
}

/************************************************************************/

void PomodoroManagerWdg::on_stop_btn_clicked() { timer_->stop(); }

/************************************************************************/

void PomodoroManagerWdg::update_timer_status() {
  remaining_msecs_--;
  update_remaining_time_status();
}

/************************************************************************/

void PomodoroManagerWdg::update_remaining_time_status() {
  QTime zero_time(0, 0, 0);
  QTime process_time = zero_time.addMSecs(remaining_msecs_);

  auto remaining_time_text =
      process_time.toString("mm") + ":" + process_time.toString("ss");

  ui->timer_label->setText(remaining_time_text);
}

/************************************************************************/
