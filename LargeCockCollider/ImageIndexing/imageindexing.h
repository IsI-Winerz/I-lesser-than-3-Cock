#ifndef IMAGEINDEXING_H
#define IMAGEINDEXING_H

#include "ImageIndexing_global.h"
#include "CImg.h"


class IMAGEINDEXINGSHARED_EXPORT ImageIndexing {
public:
    ImageIndexing();
    ImageIndexing(const char *const filename);

    int _width;
    int _height;

private:
    cimg_library::CImg<unsigned char> *Img;
};

#endif // IMAGEINDEXING_H
