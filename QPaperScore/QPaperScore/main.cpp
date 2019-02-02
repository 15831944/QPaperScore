#include "stdafx.h"
#include "QPaperScore.h"
#include <QtWidgets/QApplication>
#include "../PaperScoreAlgorithm/ScoreDll.h"
#include "../QtPicture/QtPicture.h"
int main(int argc, char *argv[])
{
	
	QApplication a(argc, argv);
	QPaperScore w;
	w.show();
	//QtPicture w(NULL, "F:\\testpng\\papertemplate\\QQ½ØÍ¼20190130143414.png");
	//w.show();
	return a.exec();
	/*
	std::vector<std::string> aszTemplate;
	aszTemplate.push_back("f:\\testpng\\tt.png");
	std::vector<std::string> aszPaper;
	aszPaper.push_back("f:\\testpng\\allstar.jpg");
	auto p = std::make_unique<CPaperScoreMatchAndHash>(aszTemplate, aszPaper,"f:\\testpng\\result.csv");
	auto res = p->doIt();
	p->doWrite();*/
}
