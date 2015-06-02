/** Author : Beretz Emile, Gaudet Kevin, Schimchowitsch Raphal
  * Project : I <3 Cock
  * File : colorhisto.cpp
  */

#include "colorhisto.h"

#include <iostream>

using namespace cimg_library;

ColorHisto::ColorHisto(cimg_library::CImg<float>& Im)
{
    m_img = Im.get_crop(0,0,Im.width(),Im.height());
    m_red = m_img.get_channel(0);
    m_green = m_img.get_channel(1);
    m_blue = m_img.get_channel(2);
}

CImg<float> ColorHisto::getHist(int c, int n)
{
    switch(c)
    {
    case 0:
        return m_red.histogram(n);
    case 1:
        return m_blue.histogram(n);
    case 2:
        return m_green.histogram(n);
    }
    return m_img.display();
}

CImg<float> ColorHisto::getIm(int c)
{
    switch(c)
    {
    case 0:
        return m_red;
    case 1:
        return m_blue;
    case 2:
        return m_green;
    }
    return m_img;
}

