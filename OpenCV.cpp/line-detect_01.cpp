#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#pragma comment( lib, "opencv_world300d.lib" )

int main(int argc, const char* argv[])
{
   int hr = -1;

   try
   {
      cv::Mat src, edge, dst;
      std::vector<cv::Vec4i> lines;

      // 画像読み込み
      src = cv::imread("D:/TEMP/MaverickProj/Image/OpenCV/45/building.jpg", cv::IMREAD_GRAYSCALE);
      //
      cv::namedWindow("src", 1);
      imshow("src", src);
      //
      //                         // 輪郭抽出
      cv::Canny(src, edge, 50, 200, 3);
      //
      //                                     // 画像領域確保
      dst = cv::Mat::zeros(src.rows, src.cols, CV_8UC3);
      //
      //                                                 // src[0] -> dst[2], src[0] -> dst[1], src[0] -> dst[0]
      //                                                       // て感じでコピー元インデックスとコピー先インデックスを指定する
      int fromTo[] = { 0, 2, 0, 1, 0, 0 };
      //
      //                                                                   // シングルチャンネルを３チャンネルに増やして、コピーする
      cv::mixChannels(&src, 1, &dst, 1, fromTo, 3);
      //
      // 線分検出
      cv::HoughLinesP(
        edge,           // 8ビット，シングルチャンネルの2値入力画像．この画像は関数により書き換えられる可能性があり.
        lines,          // 検出された線分が出力されるベクトル
        1,              // ピクセル単位での距離分解能.
        CV_PI / 180.0,  // ラジアン単位での角度分解能
        80,             // 閾値.thresholdを十分に超えている直線のみが出力対象.
        30,             // 最小の線分長
        10              // 2点が同一線分上にあると見なす場合に許容される最大距離
      );
      //
      //                                                                                                                                                                   // 線分描画
      for (auto line : lines)
      {
        cv::line(dst, cv::Point(line[0], line[1]), cv::Point(line[2], line[3]), cv::Scalar(0, 0, 255), 1);
      }
      //
      cv::namedWindow("dst", 1);
      cv::imshow("dst", dst);
      //
      cv::waitKey(0);
      //
      hr = 0;
    }
      //
      catch (cv::Exception ex)
      {
        std::cout << ex.err << std::endl;
      }
      //
      //                                                                                                                                                                                                                                           // ウィンドウの破棄
      cv::destroyAllWindows();
      //
      return hr;
}
