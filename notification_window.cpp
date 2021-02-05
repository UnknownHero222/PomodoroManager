#include "notification_window.h"
#include "ui_notification_window.h"

NotificationWindow::NotificationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotificationWindow)
{
    ui->setupUi(this);
}

NotificationWindow::~NotificationWindow()
{
    delete ui;
}
