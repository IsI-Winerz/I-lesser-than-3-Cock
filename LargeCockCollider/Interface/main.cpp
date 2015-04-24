#include <QApplication>
#include "mainwindow.h"

#include "imageindexing.h"

using namespace cimg_library;

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    
//    return a.exec();
    CImg<unsigned char> img("~/Desktop/large_cock.jpeg");

    OrientationHist h(img);

   unsigned char red[] = { 255 , 0 ,0 };

//    CImgDisplay main_disp(img,"COUCOU");
    CImg<unsigned char>visu(500,400,1,1,0);

    visu.draw_graph(h.getHist(),red,1,1,0,255,0).display("Hist Orientation");

    return 0;
}
