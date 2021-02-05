#include "pomodoro_manager_wdg.h"

#include <QTime>

#include "./ui_pomodoro_manager_wdg.h"

static constexpr int kOneMillisecond = 1000;
static constexpr int kSecondsInMinute = 60;

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
      timer_{std::make_unique<QTimer>(this)},
      curr_mode_{kWorkMode} {
  ui->setupUi(this);

  connect(timer_.get(), &QTimer::timeout, this,
          &PomodoroManagerWdg::update_timer_status);
}

/************************************************************************/

PomodoroManagerWdg::~PomodoroManagerWdg() { delete ui; }

/************************************************************************/

void PomodoroManagerWdg::on_start_btn_clicked() { launch(); }

/************************************************************************/

void PomodoroManagerWdg::on_stop_btn_clicked() {
  timer_->stop();
  ui->timer_label->setText("25:00");
}

/************************************************************************/

void PomodoroManagerWdg::launch() {
  int minute_millisecs = kSecondsInMinute * kOneMillisecond;
  switch (curr_mode_) {
    case kWorkMode:
      remaining_msecs_ = kDefaultWorkMinute * 60;
      curr_mode_ = kShortBreakMode;
      break;
    case kShortBreakMode:
      remaining_msecs_ = kDefaultShortBreakMinute * 60;
      curr_mode_ = kShortBreakMode;
      break;
    case kLongBreakMode:
      remaining_msecs_ = kDefaultLongBreakMinute * 60;
      break;
  }
  timer_->start(kOneMillisecond);
}

/************************************************************************/

void PomodoroManagerWdg::update_timer_status() {
  remaining_msecs_--;
  update_remaining_time_status();

  if (remaining_msecs_ == 0) {
    launch();
  }
}

/************************************************************************/

void PomodoroManagerWdg::update_remaining_time_status() {
  QTime zero_time(0, 0, 0);
  QTime process_time = zero_time.addSecs(remaining_msecs_);

  QString remaining_time_text =
      process_time.toString("mm") + ":" + process_time.toString("ss");

  ui->timer_label->setText(remaining_time_text);
}

/************************************************************************/
