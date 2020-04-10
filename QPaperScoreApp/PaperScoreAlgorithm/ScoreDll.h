#ifndef SCOREDLL_H
#define SCOREDLL_H

#ifdef _MSC_VER
    #ifdef PAPERSCOREALGORITHM_EXPORTS
        #define DLL_IMOREX _declspec(dllexport)
    #else
        #define DLL_IMOREX _declspec(dllimport)
    #endif
#else
    #ifdef __GNUC__ >= 4
        #ifdef PAPERSCOREALGORITHM_EXPORTS
            #define DLL_IMOREX __attribute__((visibility("default")))
        #else
            #define DLL_IMOREX __attribute__((visibility("hidden")))
        #endif
    #else
        #define DLL_IMOREX
    #endif
#endif

#include <vector>
#include <string>
using namespace std;

#include <opencv2\opencv.hpp>
using namespace cv;
struct stPaper
{
	stPaper()
	{
		szPaper = "";
		dScore = 0.0;
	}
	stPaper(std::string str, double d)
		:szPaper(str),dScore(d)
	{

	}
	std::string szPaper;
	double dScore;
};
class DLL_IMOREX CPaperScoreBase
{
protected:
	CPaperScoreBase(std::vector<stPaper> aszPaper,std::string filename) ;
public:
	virtual ~CPaperScoreBase() ;
protected:
	std::string m_filename;
	std::vector<stPaper> m_aszPaper;
public:
	virtual int doIt() = 0;
	virtual int doWrite() = 0;
public:
	std::vector<stPaper> &GetPaperInfo()
	{
		return m_aszPaper;
	}


};

//模板匹配实现打分
class DLL_IMOREX CPaperScoreMatchAndHash:public CPaperScoreBase
{
public:
	CPaperScoreMatchAndHash(std::vector<std::string> aszTemplate, std::vector<stPaper> aszPaper, std::string filename,int nMethod);
	~CPaperScoreMatchAndHash();

protected:
	std::vector<std::string> m_aszTemplate;
	
public:
	virtual int doIt() override;
	virtual int doWrite() override;
	

protected:
	int m_nMethod;
};

#endif
