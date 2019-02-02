#ifndef CVALGORITHM_H
#define CVALGORITHM_H
#include <opencv2\opencv.hpp>
using namespace cv;
namespace cvAlgorithm
{
	int matchmethod(Mat &img, Mat &templ, Mat &result, Mat &presult, int match_method);
	//ƽ����ϣ
	double aHash(Mat matSrc1, Mat matSrc2, int nRow, int nCol);
	//��֪��ϣ
	double pHash(Mat matSrc1, Mat matSrc2, int nRow, int nCol);
	//ָ�Ʊȶ�
	double finger(Mat matSrc1, Mat matSrc2, int nRow, int nCol);
	//���ұȶ�
	double cossimilar(Mat matSrc1, Mat matSrc2, int nRow, int nCol);
}
#endif
