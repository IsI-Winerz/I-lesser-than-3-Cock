/** Author : Beretz Emile, Gaudet Kevin, Schimchowitsch Raphal
  * Project : I <3 Cock
  * File : orientationhist.h
  * Brief : create the orientation histogram of an image (HOG)
  */

#ifndef ORIENTATIONHIST_H
#define ORIENTATIONHIST_H

#include "CImg.h"

#include <cmath>

class OrientationHist
{
private:
    cimg_library::CImg<float> m_imgIntegrale;
    static const unsigned nb_classes = 12; /* nombre d'images bin (cf papier tunisien) */

public:
    OrientationHist(cimg_library::CImg<float>& Im);

    /**
      * Create the orientation histogram from a rectangle in a image
      */
    cimg_library::CImg<float> getHist(unsigned lowlx , unsigned lowly , unsigned rupx , unsigned rupy);

    inline unsigned int width()  { return m_imgIntegrale.width();  }
    inline unsigned int height() { return m_imgIntegrale.height(); }

};

#endif // ORIENTATIONHIST_H
