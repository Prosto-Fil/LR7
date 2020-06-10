#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private slots:
    void on_pushButton_clicked();
    void closeEvent(QCloseEvent*);
    void on_comboBox_activated(const QString &arg1);

private:
    QPushButton* pushbtn;
    QComboBox* combo;
    QLineEdit* input;
};
