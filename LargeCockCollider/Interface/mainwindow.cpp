/** Author : Beretz Emile, Gaudet Kevin, Schimchowitsch Raphal
  * Project : I <3 Cock
  * File : mainwindow.cpp
  * Brief : It's the interface we could have use if we could have finish the projet.
  * Brief : It works, and there is a little KonamiCode in there
  */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdio.h"
#include "QDialog"
#include "QFileDialog"
#include "iostream"
#include "QWidget"
#include <QGridLayout>
#include <QLabel>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAdmin, SIGNAL(triggered()), SLOT(popAdminDialog()));
    //m_adminDialog = ui("admin.ui", ui->TYPEDIALOG);.
    layout = new QVBoxLayout;
    image = new QLabel();
    nomDuPoulet = "coq+d'alsace";
    konam = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::popAdminDialog()
{
    //m_adminDialog->show(1);
}

void MainWindow::on_object_path_button_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
         tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp)"));
    image->setPixmap(QPixmap(fileName.toUtf8().constData()));
    layout->addWidget(image);
    ui->object_image->setLayout(layout);
    ui->object_path->setText(fileName.toUtf8().constData());
}


void MainWindow::on_pushButton_clicked()
{
   fileName = ui->object_path->text();
   image->setPixmap(QPixmap(fileName.toUtf8().constData()));
   layout->addWidget(image);
   ui->object_image->setLayout(layout);
   ui->object_path->setText(fileName.toUtf8().constData());
}

void MainWindow::on_Refresh_button_clicked()
{
    fileName = ("");
    image->setPixmap(QPixmap(fileName.toUtf8().constData()));
    layout->addWidget(image);
    ui->object_image->setLayout(layout);
    ui->object_path->setText(fileName.toUtf8().constData());
}

void MainWindow::on_object_name_textChanged(const QString &arg1)
{

}

void MainWindow::on_tveuxdotrespoulet_clicked()
{
    QString link = "https://www.google.fr/search?hl=fr&site=&tbm=isch&source=hp&biw=1615&bih=955&q="
   + nomDuPoulet
   + "&oq="
   + nomDuPoulet
   + "&gs_l=img.3..0l10.7113.7662.0.8171.6.5.0.0.0.0.71.247.5.5.0.msedr...0...1ac.1.64.img..1.5.246.hP-0t4CIKpE&gws_rd=cr&ei=1s9QVZTIBqrC7Abe9IHgAw";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_R:
        if (konam == 0)
            konam++;
        else
            konam = 0;
    break;
    case Qt::Key_E:
        if (konam == 1 || konam == 3)
            konam++;
        else if (konam == 6){
            QString link = "http://www.marmiton.org/recettes/recherche.aspx?aqt=coq&st=1";
            QDesktopServices::openUrl(QUrl(link));
            konam = 0;
        }
        else
            konam = 0;
    break;
    case Qt::Key_C:
        if (konam == 2)
            konam++;
        else
            konam = 0;
    break;
    case Qt::Key_T:
        if (konam == 4 || konam == 5)
            konam++;
        else
            konam = 0;
    break;
    default:
        konam = 0;
    break;
    }
    QWidget::keyPressEvent(event);
}
