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
    ifstream file;
    try{
        file.open(filename);
    } catch (ifstream::failure e) {
        cout << "Exception" << endl;
        exit(-1);
    }

    vector<OrientationHist> res;

    #pragma omp parallel shared(file,res)
    {
        std::string line;
        bool readSuccess;

        #pragma omp critical
        {
             readSuccess = getline(file,line);
        }

        while(readSuccess)
        {
            CImg<float> img(line.c_str());
            cout << line << endl;
            OrientationHist ohist(img);

            #pragma omp critical
            {
                res.push_back(ohist);
                readSuccess = getline(file,line);
            }
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    
//    return a.exec();
    CImg<float> chicken("/adhome/g/ga/gaudet/Desktop/boby.jpg");
//    CImg<float> not_a_chicken("/home/gkevin/Desktop/not_a_chicken.jpeg");

//    std::vector<OrientationHist> chickens_or, not_chickens; /* That's the question */

//    chickens_or  = getAllFiles("/adhome/g/ga/gaudet/Desktop/BasseCour/chickenlist.txt");
//    not_chickens = getAllFiles("/adhome/g/ga/gaudet/Desktop/HauteCour/notchickenlist.txt");
//    ChickenRecognizer IKnowWhatAChickenLooksLikeSherlock(chickens_or,not_chickens); /* Again, that is still the question */
//    IKnowWhatAChickenLooksLikeSherlock.save();

    ChickenRecognizer IKnowWhatAChickenLooksLikeSherlock("chicken_svm.dat");

    OrientationHist testChicken = OrientationHist(chicken);

    Rectangle r = IKnowWhatAChickenLooksLikeSherlock.findChicken(testChicken); /* O rly ? */

    std::cout << r.lowlx << " " << r.lowly << " " << r.rupx << " " << r.rupy << std::endl;

    CImg<float> img = chicken.crop(r.lowlx, r.lowly, r.rupx, r.rupy);
    img.display();

    return 0;
}

