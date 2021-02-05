#ifndef NOTIFICATION_WINDOW_H
#define NOTIFICATION_WINDOW_H

#include <QDialog>

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
  Ui::NotificationWindow *ui;
};

#endif  // NOTIFICATION_WINDOW_H
