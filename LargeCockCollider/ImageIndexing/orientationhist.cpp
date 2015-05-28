#include "orientationhist.h"

#include <iostream>

using namespace cimg_library;

OrientationHist::OrientationHist(CImg<float>& Im)
{
    CImg<float> I = Im.get_blur_median(15);
    if( Im.spectrum() >= 3 )
        I = I.RGBtoHSI().get_channel(2);

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

    CImg<float> bin(I.width(),I.height(),nb_classes,1);
    CImg<float> img_integrale(I.width(),I.height(),nb_classes,1);
    bin.fill(0.0f);
    img_integrale.fill(0.0f);

    cimg_forXY(bin,x,y) {
        int interval = (int)floor( ((gradOrientImg(x,y) + M_PI/2) / M_PI) * nb_classes );
        interval = (interval >= 0 && interval < (int)nb_classes)*interval + (interval>=(int)nb_classes) * ((int)nb_classes-1);
        bin(x,y,interval) = gradNormImg(x,y);
    }

    for(int z = 0; z < img_integrale.depth(); ++ z)
    {
        cimg_forXY(img_integrale,x,y) {
            for(int i = 0; i <= y; ++i)
                img_integrale(x,y,z) += bin(x,i,z);
            if(x != 0)
                img_integrale(x,y,z) += img_integrale(x-1,y,z);
        }
    }
    m_imgIntegrale = img_integrale;
}

CImg<float> OrientationHist::getHist(unsigned lowlx, unsigned lowly, unsigned rupx, unsigned rupy)
{
    CImg<float> hist(nb_classes,1,1,1);

    cimg_forX(hist,i) {
        hist(i) = m_imgIntegrale(lowlx,lowly,i) + m_imgIntegrale(rupx,rupy,i)
                  - (m_imgIntegrale(lowlx,rupy,i) + m_imgIntegrale(rupx,lowly,i));
    }

    return hist.normalize(0.0f,1.0f);
}
