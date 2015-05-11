#include "orientationhist.h"

#include <iostream>

using namespace cimg_library;

OrientationHist::OrientationHist(CImg<float>& Im)
{
    CImg<float> I = Im.RGBtoHSI().get_channel(2);
    CImg<float> sobHoriz(3,3,1,1,1,0,-1,2,0,-2,1,0,-1);
    CImg<float> sobVert = sobHoriz.get_transpose();

    CImg<float> gradVert = I.get_convolve(sobVert);
    CImg<float> gradHoriz = I.get_convolve(sobHoriz);

    CImg<float> gradOrientImg(I.width(),I.height(),1,1);
    CImg<float> gradNormImg(I.width(),I.height(),1,1);


    const unsigned w = 9;
    const unsigned nb_classes = 12;

//    CImg<float> V(I.width()/w,I.height()/w,1,1);

    cimg_forXY(gradOrientImg,x,y) {
        gradNormImg(x,y) = sqrt( gradHoriz(x,y) * gradHoriz(x,y) + gradVert(x,y) * gradVert(x,y) );
        gradOrientImg(x,y) = atan( gradVert(x,y)/gradHoriz(x,y) );
    }

    CImg<CImg<float> > hog(I.width()/w,I.height()/w,1,1);

    unsigned i,j,k,l,x,y;
    for(x = 0, i = 0 ; i < gradVert.width() ; x ++ , i += w)
        for( y = 0, j = 0 ; j < gradVert.height() ; y ++ , j += w )
        {

            CImg<float> orientHist(nb_classes,1,1,1);
            cimg_forX(orientHist,x0) {
                orientHist(x0) = 0.0f;
            }

            for( k = i ; k < i + w && gradVert.width() ; k ++ )
                for( l = j ; l < j + w  && gradVert.height() ; l ++ )
                {
                    unsigned int interval = (unsigned int)floor( (gradOrientImg(k,l) / 2*M_PI) * nb_classes );
                    orientHist(interval) += gradNormImg(k,l);
                }
        }

//    hog.display("COUCOU");
}
