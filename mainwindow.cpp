#include "mainwindow.h"
#include <QLabel>
#include <QFrame>
#include <QStatusBar>
#include <QGridLayout>
#include <QLineEdit>
#include <QCloseEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QFrame *fr = new QFrame(this);
    fr->setMinimumSize(200, 200);
    setCentralWidget(fr);

    QGridLayout *grid = new QGridLayout(fr);
    input = new QLineEdit(fr);
    pushbtn = new QPushButton("Push", fr);
    combo = new QComboBox();
    QLabel* label1 = new QLabel("Type your text in the form below:", fr);
    QLabel* label2 = new QLabel("If you want to add text, click Push:", fr);
    statusBar();

    grid->setHorizontalSpacing(10);
    grid->setVerticalSpacing(10);

    grid->addWidget(pushbtn, 4, 0);
    grid->addWidget(combo, 0, 0);
    grid->addWidget(input, 2, 0);
    grid->addWidget(label2, 3, 0);
    grid->addWidget(label1, 1, 0);

    connect(pushbtn, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(combo, &QComboBox::textActivated, this, &MainWindow::on_comboBox_activated);
}

void MainWindow::on_pushButton_clicked()
{
    combo->addItem(input->text());
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    statusBar()->showMessage("In use: "+ arg1);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    QMessageBox::StandardButton button = QMessageBox::question(this, "Warning", "Do you want to close this window ?", QMessageBox::Yes|QMessageBox::No);
    if (button == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}
