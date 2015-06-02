/** Author : Beretz Emile, Gaudet Kevin, Schimchowitsch Raphal
  * Project : I <3 Cock
  * File : colorhisto.h
  * Brief : Create color histograms of images
  * (non-finished file)
  */

#ifndef COLORHISTO_H
#define COLORHISTO_H

#include "CImg.h"

class ColorHisto
{
private:
    cimg_library::CImg<float> m_img;
    cimg_library::CImg<float> m_red;
    cimg_library::CImg<float> m_green;
    cimg_library::CImg<float> m_blue;

public:
    ColorHisto(cimg_library::CImg<float>& Im);

    /**
      Get histogram of
      0 : red comp
      1 : blue comp
      2 : green comp
      with n number of bins
      */
    cimg_library::CImg<float> getHist(int c, int n);

    /**
      Get image of
      0 : red comp
      1 : blue comp
      2 : green comp
      */
    cimg_library::CImg<float> getIm(int c);


};

#endif // COLORHISTO_H
