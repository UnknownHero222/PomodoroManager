#include "notification_window.h"

#include "ui_notification_window.h"

/************************************************************************/

NotificationWindow::NotificationWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::NotificationWindow) {
  ui->setupUi(this);
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
