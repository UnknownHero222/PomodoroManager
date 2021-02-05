#include "pomodoro_manager_wdg.h"

#include <QTime>

#include "./ui_pomodoro_manager_wdg.h"
#include "notification_window.h"

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
  uint8_t minute_secs = 60;
  switch (curr_mode_) {
    case kWorkMode:
      remaining_msecs_ = kDefaultWorkMinute * minute_secs;
      curr_mode_ = kShortBreakMode;
      break;
    case kShortBreakMode:
      remaining_msecs_ = kDefaultShortBreakMinute * minute_secs;
      curr_mode_ = kShortBreakMode;
      break;
    case kLongBreakMode:
      remaining_msecs_ = kDefaultLongBreakMinute * minute_secs;
      break;
  }
  timer_->start(kOneMillisecond);
}

/************************************************************************/

void PomodoroManagerWdg::update_timer_status() {
  remaining_msecs_--;
  update_remaining_time_status();

  if (remaining_msecs_ == 0) {
    show_notification();
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

void PomodoroManagerWdg::show_notification() {
  auto notification_wnd = NotificationWindow(this);
  notification_wnd.set_notification_text("It's time to take a break!");
  notification_wnd.exec();
}

/************************************************************************/
