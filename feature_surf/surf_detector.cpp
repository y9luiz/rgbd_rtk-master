#include "surf_detector.h"
#include "opencv2/imgproc.hpp"

SurfDetector::SurfDetector(){
    this->minHessian_ = 400;
    detector_ = SURF::create(this->minHessian_);


}
SurfDetector::SurfDetector(double minHessian){
    this->minHessian_ = minHessian;

    detector_ = SURF::create(this->minHessian_);


}
void SurfDetector::Detect(Mat curr_frame ){

        cvtColor(curr_frame, this->curr_frame_gray_, cv::COLOR_RGB2GRAY);

        if(this->detector_!= NULL){
            this->detector_->detect(curr_frame_gray_,curr_KPs_);


            curr_KPs_.swap(prev_KPs_);
            cv::swap(curr_frame,prev_frame_gray_);
        }


}
