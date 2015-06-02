/** Author : Beretz Emile, Gaudet Kevin, Schimchowitsch Raphal
  * Project : I <3 Cock
  * File : mainwindow.h
  * Brief : It's the interface we could have use if we could have finish the projet.
  * Brief : It works, and there is a little KonamiCode in there
  */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QLabel>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString fileName;
    QString nomDuPoulet;

private:
    Ui::MainWindow *ui;
    QDialog* m_adminDialog;
    QVBoxLayout* layout;
    QLabel *image;
    void keyPressEvent(QKeyEvent *event);
    int konam;

public slots:
    void popAdminDialog();
private slots:
    void on_object_path_button_clicked();

    void on_pushButton_clicked();
    void on_Refresh_button_clicked();
    void on_object_name_textChanged(const QString &arg1);
    void on_tveuxdotrespoulet_clicked();
};

#endif // MAINWINDOW_H
