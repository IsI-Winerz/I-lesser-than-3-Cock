#include <QApplication>
#include "mainwindow.h"

#include "imageindexing.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
/*
//    return a.exec();
    CImg<float> img("/home/gkevin/Desktop/bigO.png");

//    img.display();

    OrientationHist hist(img);

    CImg<float> h = hist.getHist(0,0,img.width(),img.height());
    h.display();
*/

    return 0;
}

