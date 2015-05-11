#ifndef ORIENTATIONHIST_H
#define ORIENTATIONHIST_H

#include <cmath>

#include "CImg.h"

class OrientationHist
{
private:
    cimg_library::CImg<cimg_library::CImg<float> > m_hog;
public:
    OrientationHist(cimg_library::CImg<float> &Im);

    inline cimg_library::CImg<> getHog() { return m_hog; }
};

#endif // ORIENTATIONHIST_H
