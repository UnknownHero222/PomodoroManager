#include "pomodoro_manager_wdg.h"

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
  uint64_t remaining_msecs{0};
  switch (curr_mode_) {
    case kWorkMode:
      remaining_msecs = kDefaultWorkMinute;
      curr_mode_ = kShortBreakMode;
      break;
    case kShortBreakMode:
      remaining_msecs = kWorkMode;
      curr_mode_ = kShortBreakMode;
      break;
    case kLongBreakMode:
      remaining_msecs = kDefaultLongBreakMinute;
      break;
  }
  timer_->start(kOneMillisecond);
}

/************************************************************************/

void PomodoroManagerWdg::update_timer_status() {}

/************************************************************************/
