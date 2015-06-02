/** Author : Beretz Emile, Gaudet Kevin, Schimchowitsch Raphal
  * Project : I <3 Cock
  * File : chickenrecognizer.h
  * Brief : Find the cock in the image using SVM
  */

#ifndef CHICKENRECOGNIZER_H
#define CHICKENRECOGNIZER_H

#include "dlib/svm.h"
#include "imageindexing.h"

struct Rectangle {
    Rectangle(unsigned llx,unsigned lly,unsigned rux, unsigned ruy) : lowlx(llx), lowly(lly), rupx(rux), rupy(ruy) {}
    unsigned lowlx, lowly, rupx, rupy;
};

class ChickenRecognizer
{
private:
    typedef dlib::matrix<float,12,1> kfcBucket;
    typedef dlib::linear_kernel<kfcBucket> kernel_t;

    dlib::decision_function<kernel_t> m_rank;
    dlib::matrix<float,12,1> histToKFC(OrientationHist& h, unsigned lowlx, unsigned lowly, unsigned rupx, unsigned rupy);

public:
    /**
      * Create the chicken recognizer using chicken's HOG and not chicken's HOG
      */
    ChickenRecognizer(std::vector<OrientationHist>& chickenHogs, std::vector<OrientationHist>& notChickenHogs);

    /**
      * Load a SVM
      */
    ChickenRecognizer(std::string fname) { dlib::deserialize(fname) >> m_rank; }

    /**
      * Know if you're facing an angry chicken, or if it's just a fake call
      */
    bool isChicken(OrientationHist &h, unsigned lowlx, unsigned lowly, unsigned rupx, unsigned rupy);

    /**
      * But, where is the chicken on the image? Use this function, you'll see
      */
    Rectangle findChicken(OrientationHist& h);

    /**
      * Save a SVM
      */
    inline void save() { dlib::serialize("chicken_svm.dat") << m_rank; }
};

#endif // CHICKENRECOGNIZER_H
