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

    const unsigned w = 5;

    CImg<float> V(I.width()/w,I.height()/w,1,1);

    unsigned i,j,k,l,x,y;
    for(x = 0, i = w/2 ; i < gradVert.width() - w/2 ; x ++ , i += w)
        for( y = 0, j = w/2 ; j < gradVert.height() - w/2 ; y ++ , j += w )
        {
            float vx = 0,vy = 0,ve = 0;
            float c,o;

            for( k = i - w/2 ; k <= i + w/2 ; k ++ )
                for( l = j - w/2 ; l <= j + w/2 ; l ++ )
                {
                    vx += gradHoriz(k,l)*gradHoriz(k,l) - gradVert(k,l)*gradVert(k,l);
                    vy += 2*gradHoriz(k,l) * gradVert(k,l);
                    ve += gradHoriz(k,l)*gradHoriz(k,l) + gradVert(k,l)*gradVert(k,l);
                }

            c = sqrt( 1/(w*w) * ((vx*vx + vy*vy)/ ve) );
            o = 1/2 * atan( vy / vx );

            if(o>1.0f) o = 0.0f;

            V(x,y) = o;
        }

    V.display("COUCOU");

    m_hist = V.get_histogram(180);
}
