#include "/lustre/apps/opencv/4.1.2/managenode/noGPU/include/opencv4/opencv2/opencv.hpp"
int main(){
	cv::Mat M = cv::Mat::eye(3, 3, CV_8U);
	std::cout << M << std::endl;
}
