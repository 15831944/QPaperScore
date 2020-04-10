#ifndef CVALGORITHM_H
#define CVALGORITHM_H
#include <opencv2\opencv.hpp>
using namespace cv;
namespace cvAlgorithm
{
	int matchmethod(Mat &img, Mat &templ, Mat &result, Mat &presult, int match_method);
	//平均哈希
	double aHash(Mat matSrc1, Mat matSrc2, int nRow, int nCol);
	//感知哈希
	double pHash(Mat matSrc1, Mat matSrc2, int nRow, int nCol);
	//指纹比对
	double finger(Mat matSrc1, Mat matSrc2, int nRow, int nCol);
	//余弦比对
	double cossimilar(Mat matSrc1, Mat matSrc2, int nRow, int nCol);
}
#endif
