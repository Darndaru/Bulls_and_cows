#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotShortrcutEnter();
    void on_input_user_number_button_clicked();

private:
    Ui::MainWindow *ui;

    QShortcut *keyEnter;


    QString user_number;
    std::string pc_number;
    std::string number_for_check;

    bool is_number(QString);
};
#endif // MAINWINDOW_H
