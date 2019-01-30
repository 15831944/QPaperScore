#include "stdafx.h"
#include "QPaperScore.h"
#include <memory>
#include "../PaperScoreAlgorithm/ScoreDll.h"
QPaperScore::QPaperScore(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initUI();
	connect(ui.pushButton_Goal, &QPushButton::clicked, this, &QPaperScore::doCal);
	connect(ui.pushButton_AddTemplate, &QPushButton::clicked, this, &QPaperScore::doAddTemplate);
	connect(ui.pushButton_DelTemplate, &QPushButton::clicked, this, &QPaperScore::doDelTemplate);
	connect(ui.pushButton_ClearTemplate, &QPushButton::clicked, this, &QPaperScore::doClearTemplate);
	connect(ui.pushButton_AddPaper, &QPushButton::clicked, this, &QPaperScore::doAddPaper);
	connect(ui.pushButton_DelPaper, &QPushButton::clicked, this, &QPaperScore::doDelPaper);
	connect(ui.pushButton_ClearPaper, &QPushButton::clicked, this, &QPaperScore::doClearPaper);
	connect(ui.pushButton_Export, &QPushButton::clicked, this, &QPaperScore::doExport);
}

void QPaperScore::initUI()
{
	ui.tableWidget_Template->setColumnCount(1);
	QStringList headlist;
	headlist << "路径";
	ui.tableWidget_Template->setHorizontalHeaderLabels(headlist);
	//ui.tableWidget_Template->setColumnWidth(0, 30);
	ui.tableWidget_Template->setColumnWidth(0, 250);

	ui.tableWidget_Paper->setColumnCount(2);
	QStringList paperlist;
	paperlist << "路径" << "分数";
	ui.tableWidget_Paper->setHorizontalHeaderLabels(paperlist);
	ui.tableWidget_Paper->setColumnWidth(0, 250);
	ui.tableWidget_Paper->setColumnWidth(1, 100);
	
	//ui.comboBox_Algorithm->addItem("平均哈希算法");
	//ui.comboBox_Algorithm->addItem("感知哈希算法");
	ui.comboBox_Algorithm->addItem("指纹算法");
	//ui.comboBox_Algorithm->setCurrentIndex(2);
}

void QPaperScore::doCal()
{
	std::vector<std::string> aszTemplate;
	for (auto i = 0; i < ui.tableWidget_Template->rowCount(); i++)
	{
		aszTemplate.push_back((const char *)ui.tableWidget_Template->item(i, 0)->text().toLocal8Bit());
	}
	//aszTemplate.push_back("f:\\testpng\\tt.png");
	std::vector<std::string> aszPaper;
	for (auto i = 0; i < ui.tableWidget_Paper->rowCount(); i++)
	{
		aszPaper.push_back((const char *)ui.tableWidget_Paper->item(i, 0)->text().toLocal8Bit());
	}
	//aszPaper.push_back("f:\\testpng\\allstar.jpg");
	auto p = std::make_unique<CPaperScoreMatchAndHash>(aszTemplate, aszPaper, "",2);
	auto res = p->doIt();
	auto adScore = p->GetScore();
	auto index = 0;
	for (auto score : adScore)
	{
		QString str;
		str.sprintf("%.2f", score);
		ui.tableWidget_Paper->setItem(index, 1, new QTableWidgetItem(str));
		index++;
	}
	//p->doWrite();
}

void QPaperScore::doAddTemplate()
{
	auto filelist = QFileDialog::getOpenFileNames(this, "请选择模板", "", "Image Files(*.jpg *.png)");
	for (auto file : filelist)
	{
		ui.tableWidget_Template->setRowCount(ui.tableWidget_Template->rowCount() + 1);
		ui.tableWidget_Template->setItem(ui.tableWidget_Template->rowCount() - 1, 0, new QTableWidgetItem(file));
	}

}
void QPaperScore::doDelTemplate()
{
	auto index = ui.tableWidget_Template->currentRow();
	ui.tableWidget_Template->removeRow(index);

}
void QPaperScore::doClearTemplate()
{
	ui.tableWidget_Template->setRowCount(0);
}

void QPaperScore::doAddPaper()
{
	auto filelist = QFileDialog::getOpenFileNames(this, "请选择打分图纸", "", "Image Files(*.jpg *.png)");
	for (auto file : filelist)
	{
		ui.tableWidget_Paper->setRowCount(ui.tableWidget_Paper->rowCount() + 1);
		ui.tableWidget_Paper->setItem(ui.tableWidget_Paper->rowCount() - 1, 0, new QTableWidgetItem(file));
	}

}
void QPaperScore::doDelPaper()
{
	auto index = ui.tableWidget_Paper->currentRow();
	ui.tableWidget_Paper->removeRow(index);
}
void QPaperScore::doClearPaper()
{
	ui.tableWidget_Paper->setRowCount(0);
}

void QPaperScore::doExport()
{
	auto filepath = QFileDialog::getSaveFileName(this, "选择保存路径", "", "CSV Files(*.CSV)");
	if (filepath.length() <= 0)
		return;
	QFile f(filepath);
	if (f.open(QFile::OpenModeFlag::ReadWrite | QFile::OpenModeFlag::Text))
	{
		f.write((const char *)QString("序号,图纸,分数\n").toLocal8Bit());
		for (auto i = 0; i < ui.tableWidget_Paper->rowCount(); i++)
		{
			char str[1024] = { 0 };
			if (ui.tableWidget_Paper->item(i, 1))
			    sprintf_s(str, 1024, "%d,%s,%s\n", i+1,(const char *)ui.tableWidget_Paper->item(i, 0)->text().toLocal8Bit(), (const char *)ui.tableWidget_Paper->item(i, 1)->text().toLocal8Bit());
			else
				sprintf_s(str, 1024, "%d,%s,0\n", i + 1, (const char *)ui.tableWidget_Paper->item(i, 0)->text().toLocal8Bit());
			
			f.write(str);
		}
		f.close();
	}
}
