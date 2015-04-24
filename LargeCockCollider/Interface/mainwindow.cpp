#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAdmin, SIGNAL(triggered()), SLOT(popAdminDialog()));
    //m_adminDialog = ui("admin.ui", ui->TYPEDIALOG);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::popAdminDialog()
{
    //m_adminDialog->show(1);
}
