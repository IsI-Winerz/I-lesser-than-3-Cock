#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QLabel>

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
