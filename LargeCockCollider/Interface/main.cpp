#include <QtGui/QApplication>
#include <iostream>
#include "mainwindow.h"
#include "imageindexing.h"
using namespace cimg_library;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    CImg<unsigned char> image(argv[1]), visual_hist(500,400,1,3,0);
    CImg<unsigned char> red(image.width(),image.height(),1,3,0);
    CImg<unsigned char> green(image.width(),image.height(),1,3,0);
    CImg<unsigned char> blue(image.width(),image.height(),1,3,0);
    int x, y;
    cimg_forXY(image,x,y) {
           red(x,y,0,0) = image(x,y,0,0);
           green(x,y,0,1) = image(x,y,0,1);
           blue(x,y,0,2) = image(x,y,0,2);
    }

    const unsigned char redb[] = { 255,0,0 }, greenb[] = {0,255,0 }, blueb[] = { 0,0,255 };


    CImg<> hist_red = red.get_histogram(256);
    CImg<> hist_blue = blue.get_histogram(256);
    CImg<> hist_green = green.get_histogram(256);

    CImgDisplay main_disp(image, "Image_initiale");
    CImgDisplay red_sip(red,"Red");
    CImgDisplay green_disp(green,"Green");
    CImgDisplay blue_disp(blue,"Blue");
//    visual_hist.fill(0).draw_graph(hist_red,redb,1,1,0,255,0);
//    visual_hist.draw_graph(hist_green, greenb, 1,1,0,255,0);
//    visual_hist.draw_graph(hist_blue,blueb, 1, 1 ,0, 255,0).display("Red Histogram");


    return a.exec();
}
