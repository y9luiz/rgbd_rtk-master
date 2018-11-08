#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include <vector>


using namespace cv;
using namespace cv::xfeatures2d;


class SurfDetector{
    protected:
    
    Ptr<SURF> detector_;

    //data struct who stores many type of KP such as Harris corner detector, cv::FAST, cv::StarDetector, cv::SURF, cv::SIFT, cv::LDetector etc.
    
    Mat curr_frame_gray_;

    Mat prev_frame_gray_;

    double minHessian_;


    public:
        std::vector<KeyPoint> curr_KPs_;
         std::vector <KeyPoint> prev_KPs_;



        SurfDetector();
        SurfDetector(double minHessian);

        void Detect(Mat curr_frame);

    


};