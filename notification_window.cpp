#include "notification_window.h"

#include "ui_notification_window.h"

static constexpr int kOneMilliSecond = 1000;
static constexpr int kLiveTimeSeconds = 5;

/************************************************************************/

NotificationWindow::NotificationWindow(QWidget *parent)
    : QDialog{parent},
      ui{new Ui::NotificationWindow},
      live_timer_{std::make_unique<QTimer>(this)},
      live_time_counter_{kLiveTimeSeconds} {
  ui->setupUi(this);

  connect(live_timer_.get(), &QTimer::timeout, this,
          &NotificationWindow::update_live_status);
  live_timer_->start(kOneMilliSecond);
}

/************************************************************************/

NotificationWindow::~NotificationWindow() { delete ui; }

/************************************************************************/

void NotificationWindow::set_notification_text(const std::string &text) {
  ui->info_lbl->setText(text.c_str());
}

/************************************************************************/

void NotificationWindow::on_pushButton_clicked() { close(); }

/************************************************************************/

void NotificationWindow::update_live_status() {
  ui->live_st_lbl->clear();
  if (live_time_counter_ > 0) {
    std::string updated_text = "Message will be closed in " +
                               std::to_string(live_time_counter_) +
                               " seconds...";
    ui->live_st_lbl->setText(updated_text.c_str());
    live_time_counter_--;
  } else {
    close();
  }
}

/************************************************************************/
