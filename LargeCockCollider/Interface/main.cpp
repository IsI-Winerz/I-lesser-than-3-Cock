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
        cout << line << endl;
        res.push_back( OrientationHist(img));


    }
    return res;
}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    
//    return a.exec();
    CImg<float> chicken("/adhome/s/sc/schimchowitsch/Desktop/test.jpg");
//    CImg<float> not_a_chicken("/home/gkevin/Desktop/not_a_chicken.jpeg");

    std::vector<OrientationHist> chickens_or, not_chickens; /* That's the question */

    chickens_or  = getAllFiles("/adhome/s/sc/schimchowitsch/Desktop/BasseCour/chickenlist.txt");
    not_chickens = getAllFiles("/adhome/s/sc/schimchowitsch/Desktop/HauteCour/notchickenlist.txt");
    ChickenRecognizer IKnowWhatAChickenLooksLikeSherlock(chickens_or,not_chickens); /* Again, that is still the question */
    IKnowWhatAChickenLooksLikeSherlock.save();



//    ChickenRecognizer IKnowWhatAChickenLooksLikeSherlock("chicken_svm.dat");


    OrientationHist testChicken = OrientationHist(chicken);

    Rectangle r = IKnowWhatAChickenLooksLikeSherlock.findChicken(testChicken); /* O rly ? */

    std::cout << r.lowlx << " " << r.lowly << " " << r.rupx << " " << r.rupy << std::endl;

    CImg<float> img = chicken.crop(r.lowlx, r.lowly, r.rupx, r.rupy);
    img.display();

    return 0;
}

