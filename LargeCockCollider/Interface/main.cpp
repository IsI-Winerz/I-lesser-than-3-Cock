#include <QApplication>
#include <fstream>
#include "mainwindow.h"

#include "imageindexing.h"
#include "CImg.h"
#include "chickenrecognizer.h"

using namespace cimg_library;
using namespace std;

vector<OrientationHist> getAllFiles( const char *const filename )
{
    ifstream file(filename);
    vector<OrientationHist> res;
    std::string line;

    while( getline(file,line) )
    {
        CImg<float> img(line.c_str());

        res.push_back( OrientationHist(img));

        cout << line << endl;
    }
    return res;
}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    
//    return a.exec();
    CImg<float> chicken("/home/gkevin/Desktop/a_chicken.jpeg");
//    CImg<float> not_a_chicken("/home/gkevin/Desktop/not_a_chicken.jpeg");

    std::vector<OrientationHist> chickens_or, not_chickens; /* That's the question */

    chickens_or  = getAllFiles("/home/gkevin/Desktop/BasseCour/chickenlist.txt");
    not_chickens = getAllFiles("/home/gkevin/Desktop/HauteCour/notchickenlist.txt");
    ChickenRecognizer IKnowWhatAChickenLooksLikeSherlock(chickens_or,not_chickens); /* Again, that is still the question */
    IKnowWhatAChickenLooksLikeSherlock.save();

    OrientationHist testChicken = OrientationHist(chicken);

    Rectangle r = IKnowWhatAChickenLooksLikeSherlock.findChicken(testChicken); /* O rly ? */

    std::cout << r.lowlx << " " << r.lowly << " " << r.rupx << " " << r.rupy << std::endl;

//    img.display();

//    OrientationHist hist(img);

//    CImg<float> h = hist.getHist(0,0,img.width()-1,img.height()-1);
//    h.display();

    return 0;
}

