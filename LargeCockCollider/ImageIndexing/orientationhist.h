#ifndef ORIENTATIONHIST_H
#define ORIENTATIONHIST_H

#include <cmath>
#include "CImg.h"

class OrientationHist
{
private:
    cimg_library::CImg<float> m_imgIntegrale;
    static const unsigned nb_classes = 12; /* nombre d'images bin (cf papier tunisien) */

public:

    OrientationHist(cimg_library::CImg<float>& Im);
    cimg_library::CImg<float> getHist(unsigned lowlx , unsigned lowly , unsigned rupx , unsigned rupy);

    inline unsigned int width()  { return m_imgIntegrale.width();  }
    inline unsigned int height() { return m_imgIntegrale.height(); }

//    inline cimg_library::CImg<> getHog() { return m_hog; }
};

#endif // ORIENTATIONHIST_H
