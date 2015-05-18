#include "orientationhist.h"

#include <iostream>

using namespace cimg_library;

OrientationHist::OrientationHist(CImg<float>& Im):
    nb_classes(12)
{
    CImg<float> I = Im;
//    if( Im.spectrum() >= 3 )
//        I = Im.RGBtoHSI().get_channel(2);

    CImg<float> sobHoriz(3,3,1,1,1,0,-1,2,0,-2,1,0,-1);
    CImg<float> sobVert = sobHoriz.get_transpose();

    CImg<float> gradVert = I.get_convolve(sobVert);
    CImg<float> gradHoriz = I.get_convolve(sobHoriz);

    CImg<float> gradOrientImg(I.width(),I.height(),1,1);
    CImg<float> gradNormImg(I.width(),I.height(),1,1);

    cimg_forXY(gradOrientImg,x,y) {
        gradNormImg(x,y) = sqrt( gradHoriz(x,y) * gradHoriz(x,y) + gradVert(x,y) * gradVert(x,y) );
        gradOrientImg(x,y) = atan( gradVert(x,y)/gradHoriz(x,y) );
    }

    std::cout << "Yo j'ai calc le gradient biatch\n";

    CImg<float> bin(I.width(),I.height(),nb_classes,1);
    CImg<float> img_integrale(I.width(),I.height(),nb_classes,1);
    bin.fill(0.0f);
    img_integrale.fill(0.0f);

    cimg_forXY(bin,x,y) {
        int interval = (int)floor( ((gradOrientImg(x,y) + M_PI/2) / M_PI) * nb_classes );
        interval = (interval >= 0 && interval < nb_classes)*interval + (interval>=nb_classes) * (nb_classes-1);
        bin(x,y,interval) = gradNormImg(x,y);
    }

//    CImg<float> test = bin.get_slice(5);
//    test.display();

    std::cout << "Yo j'ai calc les bins\n";


    cimg_forXYZ(img_integrale,x,y,z) {
        if( x == 0 ) {
            if( y == 0 ) {
                img_integrale(x,y,z) = bin(x,y,z);
            } else {
                img_integrale(x,y,z) = img_integrale(x,y-1,z) + bin(x,y,z);
            }
        } else {
            img_integrale(x,y,z) = img_integrale(x-1,y,z);
            for(int i = 0; i <= y ; ++ i )
            {
                img_integrale(x,y,z) += bin(x,i,z);
            }
        }
    }

    m_imgIntegrale = img_integrale;
}

CImg<float> OrientationHist::getHist(unsigned xupl, unsigned yupl, unsigned xlowr, unsigned ylowr)
{
    CImg<float> hist(nb_classes,1,1,1);

    cimg_forX(hist,i) {
        hist(i) = m_imgIntegrale(xlowr,ylowr,i) + m_imgIntegrale(xupl,yupl,i)
                  - (m_imgIntegrale(xupl,ylowr,i) + m_imgIntegrale(xlowr,yupl,i));
    }

    return hist;
}
