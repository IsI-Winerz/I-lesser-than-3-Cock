#include <QtGui/QApplication>
#include "mainwindow.h"
#include "imageindexing.h"
using namespace cimg_library;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

  /*
    CImg<unsigned char> img(argv[1]);
    CImgDisplay main_disp(img,"Image");
    CImg<> hist = img.get_histogram(256);
    CImg<unsigned char> visu(500,400,1,3,0);
    unsigned char red[3]={255,0,0};
    unsigned char green[3]={0,255,0};
    unsigned char blue[3]={0,0,255};
    while (!main_disp.is_closed() && !visu.is_closed()) {
        main_disp.wait();
        if (main_disp.button() && main_disp.mouse_y()>=0) {
            visu.fill(0).draw_graph(img.get_crop(0,y,0,0,img.width()-1,y,0,0),red,1,1,0,255,0);
            visu.draw_graph(img.get_crop(0,y,0,1,img.width()-1,y,0,1),green,1,1,0,255,0);
            visu.draw_graph(img.get_crop(0,y,0,2,img.width()-1,y,0,2),blue,1,1,0,255,0).display(visu);
        }
    }

CImg<> img("image.jpg");
CImg<> hist = img.get_histogram(256);

CImg<unsigned char> visu(500,400,1,3,0);
unsigned char color[3]={255,255,255};
visu.draw_graph(hist,color,1).display("histogram");
*/
    CImg<unsigned char> image(argv[1]), visu_red(500,400,1,3,0), visu_green(500,400,1,1,0), visu_blue(500,400,1,1,0);
    CImg<unsigned char> red = image.get_crop(0,0,0,0,image.width()-1,256,0,0);
    CImg<unsigned char> green = image.get_crop(0,0,0,0,image.width()-1,256,0,1);
    CImg<unsigned char> blue = image.get_crop(0,0,0,0,image.width()-1,256,0,2);
    const unsigned char redb[] = { 255,0,0 }, greenb[] = { 255,255,0 }, blueb[] = { 0,0,255 };


    CImg<> hist_red = red.get_histogram(256);
    CImg<> hist_blue = blue.get_histogram(256);
    CImg<> hist_green = green.get_histogram(256);

    CImgDisplay main_disp(image, "Image_initiale");
    visu_red.fill(0).draw_graph(hist_red,redb,1,1,0,255,0);
    visu_red.draw_graph(hist_green, greenb, 1,1,0,255,0).display("Red Histogram");
    //visu_red.draw_graph(hist_blue,blueb, 1);


    //visu_green.draw_graph(hist_green,greenb,1).display("Green Histogram");
    //visu_blue.draw_graph(hist_blue,blueb,1).display("Blue Histogram");
   // CImgDisplay visu_disp_red(visu_red, "Red Histogram");
    //CImgDisplay visu_disp_blue(visu_blue,"Blue Histogram");
    //CImgDisplay visu_disp_green(visu_green, "Green Histogram");

/*    CImgDisplay main_disp(image,"Click a point"), draw_disp(visu,"Intensity profile");
    while (!main_disp.is_closed() && !draw_disp.is_closed()) {
    main_disp.wait();
    if (main_disp.button() && main_disp.mouse_y()>=0) {
    const int y = main_disp.mouse_y();
   // visu.fill(0).draw_graph(image.get_crop(0,y,0,0,image.width()-1,y,0,0),red,1,1,0,255,0);
    //visu.draw_graph(image.get_crop(0,y,0,1,image.width()-1,y,0,1),green,1,1,0,255,0);
    //visu.draw_graph(image.get_crop(0,y,0,2,image.width()-1,y,0,2),blue,1,1,0,255,0).display(draw_disp);
    }
    }*/
    return a.exec();
}
