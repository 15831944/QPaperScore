#ifndef SCOREDLL_H
#define SCOREDLL_H

#ifdef PAPERSCOREALGORITHM_EXPORTS
#define DLL_IMOREX __declspec(dllexport)
#else
#define DLL_IMOREX __declspec(dllimport)
#endif

#include <vector>
#include <string>
using namespace std;

#include <opencv2\opencv.hpp>
using namespace cv;
class DLL_IMOREX CPaperScoreBase
{
protected:
	CPaperScoreBase(std::vector<std::string> aszTemplate,std::vector<std::string> aszPaper,std::string filename) ;
public:
	virtual ~CPaperScoreBase() ;

protected:
	std::vector<std::string> m_aszTemplate;
	std::vector<std::string> m_aszPaper;
	std::vector<double> m_adScore;
	std::string m_filename;

public:
	virtual int doIt() = 0;
	virtual int doWrite() = 0;
	std::vector<double> &GetScore()
	{
		return m_adScore;
	}

};

//模板匹配和余弦实现打分
class DLL_IMOREX CPaperScoreMatchAndHash:public CPaperScoreBase
{
public:
	CPaperScoreMatchAndHash(std::vector<std::string> aszTemplate, std::vector<std::string> aszPaper, std::string filename,int nMethod);
	~CPaperScoreMatchAndHash();
public:
	virtual int doIt() override;
	virtual int doWrite() override;
	

protected:
	int m_nMethod;
};
int matchmethod(Mat &img, Mat &templ, Mat &result, int match_method);
//平均哈希
double aHash(Mat matSrc1, Mat matSrc2,int nRow, int nCol);
//感知哈希
double pHash(Mat matSrc1, Mat matSrc2, int nRow, int nCol);
//指纹比对
double finger(Mat matSrc1, Mat matSrc2, int nRow, int nCol);
#endif