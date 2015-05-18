#include <QApplication>
#include "mainwindow.h"

#include "imageindexing.h"
#include "CImg.h"
#include "orientationhist.h"

using namespace cimg_library;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
//    return a.exec();
    CImg<float> img("/home/gkevin/Desktop/large_cock.jpeg");

//    img.display();

    OrientationHist hist(img);

    CImg<float> h = hist.getHist(0,0,img.width()-1,img.height()-1);
//    h.display();
    a.exec();

    return 0;
}

