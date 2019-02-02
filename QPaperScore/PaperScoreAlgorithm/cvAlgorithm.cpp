#include "cvAlgorithm.h"
namespace cvAlgorithm
{
	int matchmethod(Mat &img, Mat &templ, Mat &result, Mat &presult ,int match_method)
	{
		/// 将被显示的原图像
		Mat img_display;
		img.copyTo(img_display);

		/// 创建输出结果的矩阵
		int result_cols = img.cols - templ.cols + 1;
		int result_rows = img.rows - templ.rows + 1;

		result.create(result_cols, result_rows, CV_32FC1);

		/// 进行匹配和标准化
		matchTemplate(img, templ, result, match_method);
		normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

		/// 通过函数 minMaxLoc 定位最匹配的位置
		double minVal; double maxVal; Point minLoc; Point maxLoc;
		Point matchLoc;

		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

		/// 对于方法 SQDIFF 和 SQDIFF_NORMED, 越小的数值代表更高的匹配结果. 而对于其他方法, 数值越大匹配越好
		if (match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED)
		{
			matchLoc = minLoc;
		}
		else
		{
			matchLoc = maxLoc;
		}

		/// 最终结果
		rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar(255,0,0,0), 2, 8, 0);
		//rectangle(result, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);
		img_display.copyTo(presult);
		//imshow("1", img_display);
		//imshow("2", result);
		//waitKey(0);
		result = img_display(Rect(matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows)));
		//imwrite("f:\\testpng\\roi.png", result);
		return 0;
	}

	double aHash(Mat matSrc1, Mat matSrc2, int nRow, int nCol)
	{
		Mat matDst1, matDst2;
		//cv::resize(matSrc1, matDst1, cv::Size(24, 24), 0, 0, cv::INTER_CUBIC);
		//cv::resize(matSrc2, matDst2, cv::Size(24, 24), 0, 0, cv::INTER_CUBIC);

		cv::cvtColor(matSrc1, matDst1, CV_BGR2GRAY);
		cv::cvtColor(matSrc2, matDst2, CV_BGR2GRAY);

		int iAvg1 = 0, iAvg2 = 0;
		int *arr1 = new int[nRow*nCol];
		int *arr2 = new int[nRow*nCol];

		for (int i = 0; i < nRow; i++)
		{
			uchar* data1 = matDst1.ptr<uchar>(i);
			uchar* data2 = matDst2.ptr<uchar>(i);

			int tmp = i * nCol;

			for (int j = 0; j < nCol; j++)
			{
				int tmp1 = tmp + j;

				arr1[tmp1] = data1[j] / 4 * 4;
				arr2[tmp1] = data2[j] / 4 * 4;

				iAvg1 += arr1[tmp1];
				iAvg2 += arr2[tmp1];
			}
		}

		iAvg1 /= (nRow*nCol);
		iAvg2 /= (nRow*nCol);

		for (int i = 0; i < nRow*nCol; i++)
		{
			arr1[i] = (arr1[i] >= iAvg1) ? 1 : 0;
			arr2[i] = (arr2[i] >= iAvg2) ? 1 : 0;
		}

		int iSameNum = 0;

		for (int i = 0; i < nRow*nCol; i++)
		{
			if (arr1[i] == arr2[i])
				++iSameNum;
		}
		delete[]arr1;
		delete[]arr2;
		return double(iSameNum) / (nRow*nCol)*100.0;
	}

	double finger(Mat matSrc1, Mat matSrc2, int nRow, int nCol)
	{
		Mat matDst1, matDst2;
		//cv::resize(matSrc1, matDst1, cv::Size(32, 32), 0, 0, cv::INTER_CUBIC);
		//cv::resize(matSrc2, matDst2, cv::Size(32, 32), 0, 0, cv::INTER_CUBIC);

		cv::cvtColor(matSrc1, matDst1, CV_BGR2GRAY);
		cv::cvtColor(matSrc2, matDst2, CV_BGR2GRAY);


		//int iAvg1 = 0, iAvg2 = 0;
		//int *arr1 = new int[nRow*nCol];
		//int *arr2 = new int[nRow*nCol];
		int iSameNum = 0;
		int iNum = 0;
		for (int i = 0; i < nRow; i++)
		{
			uchar* data1 = matDst1.ptr<uchar>(i);
			uchar* data2 = matDst2.ptr<uchar>(i);

			//int tmp = i * nCol;

			for (int j = 0; j < nCol; j++)
			{
				int a1 = data1[j];
				int a2 = data2[j];
				//图纸大部分都是白底，所以设置个阈值，白的不比对了
				if (a1 <= 128)
				{
					iNum++;
					if (a1 == a2)
						++iSameNum;
				}
				//int tmp1 = tmp + j;

				//arr1[tmp1] = data1[j];
				//arr2[tmp1] = data2[j];

				//iAvg1 += arr1[tmp1];
				//iAvg2 += arr2[tmp1];
			}
		}
		if (iNum)
			return double(iSameNum) / double(iNum)*100.0;
		else
			return 0.0;
	}

	double pHash(Mat matSrc1, Mat matSrc2, int nRow, int nCol)
	{
		Mat matDst1, matDst2;
		//cv::resize(matSrc1, matDst1, cv::Size(32, 32), 0, 0, cv::INTER_CUBIC);
		//cv::resize(matSrc2, matDst2, cv::Size(32, 32), 0, 0, cv::INTER_CUBIC);

		cv::cvtColor(matSrc1, matDst1, CV_BGR2GRAY);
		cv::cvtColor(matSrc2, matDst2, CV_BGR2GRAY);

		matDst1.convertTo(matDst1, CV_32F);
		matDst2.convertTo(matDst2, CV_32F);
		dct(matDst1, matDst1);
		dct(matDst2, matDst2);

		int iAvg1 = 0, iAvg2 = 0;
		int *arr1 = new int[nRow*nCol];
		int *arr2 = new int[nRow*nCol];

		for (int i = 0; i < nRow; i++)
		{
			uchar* data1 = matDst1.ptr<uchar>(i);
			uchar* data2 = matDst2.ptr<uchar>(i);

			int tmp = i * nCol;

			for (int j = 0; j < nCol; j++)
			{
				int tmp1 = tmp + j;

				arr1[tmp1] = data1[j];
				arr2[tmp1] = data2[j];

				iAvg1 += arr1[tmp1];
				iAvg2 += arr2[tmp1];
			}
		}

		iAvg1 /= (nRow*nCol);
		iAvg2 /= (nRow*nCol);

		for (int i = 0; i < nRow*nCol; i++)
		{
			arr1[i] = (arr1[i] >= iAvg1) ? 1 : 0;
			arr2[i] = (arr2[i] >= iAvg2) ? 1 : 0;
		}

		int iSameNum = 0;

		for (int i = 0; i < nRow*nCol; i++)
			if (arr1[i] == arr2[i])
				++iSameNum;
		delete[]arr1;
		delete[]arr2;
		return double(iSameNum) / (nRow*nCol)*100.0;
	}

	double cossimilar(Mat matSrc1, Mat matSrc2, int nRow, int nCol)
	{
		Mat matDst1, matDst2;
		//cv::resize(matSrc1, matDst1, cv::Size(32, 32), 0, 0, cv::INTER_CUBIC);
		//cv::resize(matSrc2, matDst2, cv::Size(32, 32), 0, 0, cv::INTER_CUBIC);

		cv::cvtColor(matSrc1, matDst1, CV_BGR2GRAY);
		cv::cvtColor(matSrc2, matDst2, CV_BGR2GRAY);


		//int iAvg1 = 0, iAvg2 = 0;
		//int *arr1 = new int[nRow*nCol];
		//int *arr2 = new int[nRow*nCol];
		//int iSameNum = 0;
		//int iNum = 0;
		double ijj = 0.0;
		double im1 = 0.0;
		double im2 = 0.0;
		for (int i = 0; i < nRow; i++)
		{
			uchar* data1 = matDst1.ptr<uchar>(i);
			uchar* data2 = matDst2.ptr<uchar>(i);

			//int tmp = i * nCol;

			for (int j = 0; j < nCol; j++)
			{
				int a1 = data1[j];
				int a2 = data2[j];
				//图纸大部分都是白底，所以设置个阈值，白的不比对了
				if (a1 <= 128)
				{
					ijj += a1*a2;
					im1 += a1*a1;
					im2 += a2*a2;
					//iNum++;
					//if (a1 == a2)
						//++iSameNum;
				}
				//int tmp1 = tmp + j;

				//arr1[tmp1] = data1[j];
				//arr2[tmp1] = data2[j];

				//iAvg1 += arr1[tmp1];
				//iAvg2 += arr2[tmp1];
			}
		}
		double im = sqrt(im1)*sqrt(im2);
		if (im)
			return fabs(ijj/im)*100;
		else
			return 0.0;
	}
}