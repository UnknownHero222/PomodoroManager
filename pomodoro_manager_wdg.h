#ifndef POMODOROMANAGERWDG_H
#define POMODOROMANAGERWDG_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class PomodoroManagerWdg;
}
QT_END_NAMESPACE

class PomodoroManagerWdg : public QMainWindow {
  Q_OBJECT

 public:
  PomodoroManagerWdg(QWidget *parent = nullptr);
  ~PomodoroManagerWdg();

 private slots:
  void on_start_btn_clicked();
  void on_stop_btn_clicked();

 private:
  void launch();

  void update_timer_status();
  void update_remaining_time_status();

 private:
  Ui::PomodoroManagerWdg *ui;

  std::unique_ptr<QTimer> timer_;

  uint8_t curr_mode_;
  uint64_t remaining_msecs_;
};
#endif  // POMODOROMANAGERWDG_H
