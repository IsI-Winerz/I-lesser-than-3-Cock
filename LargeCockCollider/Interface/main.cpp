#include <QApplication>
#include <fstream>
#include "mainwindow.h"

#include "imageindexing.h"
#include "CImg.h"
#include "chickenrecognizer.h"
#include "colorhisto.h"

using namespace cimg_library;
using namespace std;

/**
  * Read a file in order to create a parralelized task
  * Here, it's to create HOG
  */
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
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
//    return a.exec(); //if we want to use interface
    CImg<float> chicken("../../Tests/test.jpg"); //chicken Try

    std::vector<OrientationHist> chickens_or, not_chickens; /* That's the question */

    chickens_or  = getAllFiles("../../BasseCour/chickenlist.txt");
    not_chickens = getAllFiles("../../HauteCour/notchickenlist.txt");

    /* ----------- Create the SVM and save it  ------------ */
//  ChickenRecognizer IKnowWhatAChickenLooksLikeSherlock(chickens_or,not_chickens); /* Again, that is still the question */
//  IKnowWhatAChickenLooksLikeSherlock.save();
    /* ---------------------------------------------------- */

    /* ----------- Load the SVM already create ------------ */
    ChickenRecognizer IKnowWhatAChickenLooksLikeSherlock("chicken_svm.dat"); //load the SVM using chicken_svm.dat file
    /* ---------------------------------------------------- */

    OrientationHist testChicken = OrientationHist(chicken);

    Rectangle r = IKnowWhatAChickenLooksLikeSherlock.findChicken(testChicken); /* O rly ? */

    const float color[3] = { 1.0f, 1.0f, 1.0f };

    chicken.draw_rectangle<float>((int)r.lowlx, (int)r.lowly, (int)r.rupx, (int)r.rupy, color, 1).display(); // the rectangle our program find after using SVM. (not really efficient)

    return 0;
}

