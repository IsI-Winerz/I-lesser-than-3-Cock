#ifndef ORIENTATIONHIST_H
#define ORIENTATIONHIST_H

#include <cmath>

#include "CImg.h"

class OrientationHist
{
private:
    cimg_library::CImg<float> m_imgIntegrale;
    const unsigned nb_classes = 12; /* nombre d'images bin (cf papier tunisien) */

public:
    OrientationHist(cimg_library::CImg<float> &Im);

    cimg_library::CImg<float> getHist(unsigned xupl , unsigned yupl , unsigned xlowr , unsigned ylowr);

//    inline cimg_library::CImg<> getHog() { return m_hog; }
};

#endif // ORIENTATIONHIST_H
