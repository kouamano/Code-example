# include <opencv2/core/core.hpp>
# include <opencv2/highgui/highgui.hpp>
# include <iostream>

using namespace std;

void cvmat_style(cv::Mat m){
cout << "行数 rows:" << m.rows << "  列数 cols:" << m.cols << endl;
 cout << "次元数 dims:" << m.dims << "   サイズ（2次元の場合）size[]:" << m.size().width << "," << m.size().height << endl;
  cout << "ビット深度ID depth (ID):" << m.depth() << "(=" << CV_64F << ")" << endl;
   cout << "チャンネル数 channels:" << m.channels() << endl;
   cout << "（複数チャンネルから成る）1要素のサイズ [バイト単位] elemSize:" << m.elemSize() << "[byte]" << endl;
   cout << "1要素内の1チャンネル分のサイズ [バイト単位]  (elemSize/channels):" << m.elemSize1() << "[byte]" << endl;
   cout << "要素の総数 total:" << m.total() << endl;
   cout << "ステップ数 [バイト単位] step:" << m.step << "[byte]" << endl;
   cout << "1ステップ内のチャンネル総数 step1 (step/elemSize1):" << m.step1()  << endl;
 cout << "データは連続か？ isContinuous:" << (m.isContinuous()?"true":"false") << endl;
 cout << "部分行列か？ isSubmatrix:" << (m.isSubmatrix()?"true":"false") << endl;
 cout << "データは空か？ empty:" << (m.empty()?"true":"false") << endl;
}

int main(){
	cv::Mat image = cv::imread("tmp/2015_0622_1413_cimg3755.jpg");     // imreadはhighguiの関数
	cv::imshow("Look at me!", image);     // imshowはhighguiの関数
	cvmat_style(image);
	cv::waitKey(0);
}
