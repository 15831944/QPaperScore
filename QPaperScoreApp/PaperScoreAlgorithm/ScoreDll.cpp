
#include "ScoreDll.h"
#include <direct.h>
#include "cvAlgorithm.h"
using namespace cvAlgorithm;

CPaperScoreBase::CPaperScoreBase(std::vector<stPaper> aszPaper, std::string filename)
	:m_aszPaper(aszPaper), m_filename(filename)
{

}

CPaperScoreBase::~CPaperScoreBase()
{

}

CPaperScoreMatchAndHash::CPaperScoreMatchAndHash(std::vector<std::string> aszTemplate, std::vector<stPaper> aszPaper, std::string filename, int nMethod)
	:CPaperScoreBase(aszPaper,filename),m_nMethod(nMethod),m_aszTemplate(aszTemplate)
{

}

CPaperScoreMatchAndHash::~CPaperScoreMatchAndHash()
{

}

int CPaperScoreMatchAndHash::doIt()
{
	_mkdir("temp");
	auto p = 0;
	for (auto &paper : m_aszPaper)
	{
		auto nScore = 0.0;
		auto matpaper = cv::imread(paper.szPaper.c_str());
		auto t = 0;
		for (auto &templatepath : m_aszTemplate)
		{
			Mat matresult,matpresult;
			auto mattemplate = cv::imread(templatepath.c_str());
			matchmethod(matpaper, mattemplate, matresult, matpresult, CV_TM_SQDIFF);
			
			char s[1024] = { 0 };
			sprintf_s(s, 1024, "temp\\%d_%d.png", p, t);
			cv::imwrite(s, matpresult);
			switch (m_nMethod)
			{
			case 0:
				nScore += aHash(mattemplate, matresult, matresult.rows, matresult.cols);
				break;
			case 1:
				nScore += pHash(mattemplate, matresult, matresult.rows, matresult.cols);
				break;
			case 2:
				nScore += finger(mattemplate, matresult, matresult.rows, matresult.cols);
				break;
			case 3:
				nScore += cossimilar(mattemplate, matresult, matresult.rows, matresult.cols);
				break;
			default:
				break;
			}
			t++;
			
		}
		paper.dScore = nScore / m_aszTemplate.size();
		p++;
	}	    
	return 0;
}

int CPaperScoreMatchAndHash::doWrite()
{
	FILE* f;
	auto res = fopen_s(&f,m_filename.c_str(), "w");
	if (f)
	{
		for ( auto &paper : m_aszPaper )
		{
			char str[1024] = { 0 };
			sprintf_s(str, 1024,"%s,%.2f\n", paper.szPaper.c_str(), paper.dScore);
			fwrite(str, sizeof(char), strlen(str) + 1, f);
		}
		fclose(f);
	}
	return res;
}

