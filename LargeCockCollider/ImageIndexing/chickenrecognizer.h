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
    ChickenRecognizer(std::vector<OrientationHist>& chickenHogs, std::vector<OrientationHist>& notChickenHogs);
    ChickenRecognizer(std::string fname) { dlib::deserialize(fname) >> m_rank; }
    bool isChicken(OrientationHist &h, unsigned lowlx, unsigned lowly, unsigned rupx, unsigned rupy);
    Rectangle findChicken(OrientationHist& h);

    inline void save() { dlib::serialize("chicken_svm.dat") << m_rank; }
};

#endif // CHICKENRECOGNIZER_H
