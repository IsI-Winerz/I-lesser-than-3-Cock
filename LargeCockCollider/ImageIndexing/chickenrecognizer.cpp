#include "chickenrecognizer.h"

dlib::matrix<float,12,1> ChickenRecognizer::histToKFC(OrientationHist& h, unsigned lowlx, unsigned lowly, unsigned rupx, unsigned rupy )
{
    kfcBucket res;

    cimg_library::CImg<float> hist = h.getHist(lowlx,lowly,rupx,rupy);
    cimg_forX(hist,x) {
        res(x,0) = hist(x);
    }

    return res;
}

ChickenRecognizer::ChickenRecognizer(std::vector<OrientationHist> &chickenHogs, std::vector<OrientationHist> &notChickenHogs )
{
    dlib::ranking_pair<kfcBucket> data;
    kfcBucket tmp;

    for( std::vector<OrientationHist>::iterator it = chickenHogs.begin(); it != chickenHogs.end(); ++ it )
    {
        data.relevant.push_back( histToKFC(*it, 0, 0, it->width()-1, it->height()-1) );
    }

    for( std::vector<OrientationHist>::iterator it = notChickenHogs.begin(); it != notChickenHogs.end(); ++ it )
    {
        data.nonrelevant.push_back( histToKFC(*it, 0, 0, it->width()-1, it->height()-1) );
    }

    dlib::svm_rank_trainer<kernel_t> trainer;
    m_rank = trainer.train(data);
}

bool ChickenRecognizer::isChicken(OrientationHist& h, unsigned lowlx, unsigned lowly, unsigned rupx, unsigned rupy)
{
    cimg_library::CImg<float> hist = h.getHist(lowlx,lowly,rupx,rupy);

    float rank = m_rank( histToKFC( h, lowlx, lowly, rupx, rupy ) );

    return ( rank >= 0.0f );
}

Rectangle ChickenRecognizer::findChicken(OrientationHist &h)
{
    const unsigned init_window_size = 48;
    Rectangle window(0,0,init_window_size,init_window_size);

    float currentRank = m_rank( histToKFC(h,window.lowlx,window.lowly,window.rupx,window.rupy) );

    for( unsigned c = init_window_size; c < h.width() && c < h.height(); c += c/4 )
    {
        for( unsigned i = 0; i < h.width() - c; ++ i )
            for( unsigned j = 0; j < h.height() - c; ++ j )
            {
                float rank = m_rank( histToKFC(h,i,j,i+c,j+c) );

                if( rank > currentRank )
                {
                    currentRank = rank;
                    window = Rectangle(i,j,i+c,j+c);
                }
            }
    }

    return window;
}


