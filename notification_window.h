#ifndef NOTIFICATION_WINDOW_H
#define NOTIFICATION_WINDOW_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class NotificationWindow;
}

class NotificationWindow : public QDialog {
  Q_OBJECT

 public:
  explicit NotificationWindow(QWidget *parent = nullptr);
  ~NotificationWindow();

  void set_notification_text(const std::string &text);

 private slots:
  void on_pushButton_clicked();

 private:
  void update_live_status();

 private:
  Ui::NotificationWindow *ui;

  std::unique_ptr<QTimer> live_timer_;

  uint8_t live_time_counter_;
};

#endif  // NOTIFICATION_WINDOW_H
