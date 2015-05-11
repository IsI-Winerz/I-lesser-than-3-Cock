#ifndef ORIENTATIONHIST_H
#define ORIENTATIONHIST_H

#include <cmath>

#include "CImg.h"

class OrientationHist
{
private:
    cimg_library::CImg<> m_hist;
public:
    OrientationHist(cimg_library::CImg<float> &Im);

    inline cimg_library::CImg<> getHist() { return m_hist; }
};

#endif // ORIENTATIONHIST_H
