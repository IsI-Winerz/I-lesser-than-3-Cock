#ifndef INTER_H
#define INTER_H

#include <QDialog>

namespace Ui {
class Inter;
}

class Inter : public QDialog
{
    Q_OBJECT
    
public:
    explicit Inter(QWidget *parent = 0);
    ~Inter();
    
private:
    Ui::Inter *ui;
};

#endif // INTER_H
