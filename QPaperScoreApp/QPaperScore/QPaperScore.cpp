#include "stdafx.h"
#include "QPaperScore.h"
#include <memory>
#include "../PaperScoreAlgorithm/ScoreDll.h"
#include "../QtPicture/QtPicture.h"
#include <QProgressDialog>
#include "QWaitDialog.h"
#include <direct.h> 
#include "PublicFunction.h"
QPaperScore::QPaperScore(QWidget *parent)
	: QMainWindow(parent), m_IsSet(true)
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
	connect(ui.tableWidget_Paper, &QTableWidget::cellClicked, this, &QPaperScore::doPreview);
	connect(ui.pushButton_reset, &QPushButton::clicked, this, &QPaperScore::settoSetMode);
	setmode();
}
QPaperScore::~QPaperScore()
{
	removeResult();
}
void QPaperScore::settoSetMode()
{
	m_IsSet = true;
	setmode();
	ui.tabWidget_Result->clear();
}
void QPaperScore::settoPreviewMode()
{
	m_IsSet = false;
	setmode();
}
void QPaperScore::setmode()
{
	ui.groupBox_ReulstPreview->setEnabled(!m_IsSet);
	ui.groupBox->setEnabled(m_IsSet);
	ui.pushButton_AddPaper->setEnabled(m_IsSet);
	ui.pushButton_ClearPaper->setEnabled(m_IsSet);
	ui.pushButton_DelPaper->setEnabled(m_IsSet);
	
}
void QPaperScore::removeResult()
{
	DelDir("temp");

}

void QPaperScore::initUI()
{
	this->setWindowTitle("图纸打分Demo");
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
	ui.comboBox_Algorithm->addItem("余弦算法");
	//ui.comboBox_Algorithm->setCurrentIndex(2);
}

void QPaperScore::doCal()
{
	removeResult();
	if ((ui.tableWidget_Template->rowCount() < 1) || (ui.tableWidget_Paper->rowCount() < 1))
	{
		QMessageBox a(QMessageBox::Warning,"提示","未选择模板或图纸");
		a.exec();
		return;
	}
	QWaitDialog dlg;
	dlg.show();
	QCoreApplication::processEvents();
	std::vector<std::string> aszTemplate;
	for (auto i = 0; i < ui.tableWidget_Template->rowCount(); i++)
	{
		aszTemplate.push_back((const char *)ui.tableWidget_Template->item(i, 0)->text().toLocal8Bit());
	}
	//aszTemplate.push_back("f:\\testpng\\tt.png");
	std::vector<stPaper> aszPaper;
	for (auto i = 0; i < ui.tableWidget_Paper->rowCount(); i++)
	{
		aszPaper.push_back(stPaper((const char *)ui.tableWidget_Paper->item(i, 0)->text().toLocal8Bit(),0.0));
	}
	//aszPaper.push_back("f:\\testpng\\allstar.jpg");
	auto p = std::make_unique<CPaperScoreMatchAndHash>(aszTemplate, aszPaper, "",ui.comboBox_Algorithm->currentIndex()+2);
	auto res = p->doIt();
	auto arrPaper = p->GetPaperInfo();
	auto index = 0;
	for (auto paper : arrPaper)
	{
		QString str;
		str.sprintf("%.2f", paper.dScore);
		ui.tableWidget_Paper->setItem(index, 1, new QTableWidgetItem(str));
		index++;
	}
	//p->doWrite();
	settoPreviewMode();
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

void QPaperScore::doPreview(int nRow)
{
	if (m_IsSet)
		return;
	ui.tabWidget_Result->clear();
	for (auto i = 0; i < ui.tableWidget_Template->rowCount(); i++)
	{
		QString str;
		str.sprintf("模板%d匹配结果", i+1);
		auto pw = new QWidget();
		ui.tabWidget_Result->addTab(pw, str);
		auto p = new QtPicture(this, ui.tableWidget_Template->item(i, 0)->text());
		auto layout = new QGridLayout(pw);
		auto gp1 = new QGroupBox("模板");
		layout->addWidget(gp1, 0, 0);
		auto gp1layout = new QGridLayout(gp1);
		gp1layout->addWidget(p, 0, 0);
		str.sprintf("temp\\%d_%d.png", nRow, i);
		QDir dir;
		if (dir.exists(str))
		{
			auto gp2 = new QGroupBox("结果");
			layout->addWidget(gp2, 0, 1);
			auto gp2layout = new QGridLayout(gp2);
			
			auto r = new QtPicture(this, str);
			gp2layout->addWidget(r, 0, 0);
		}
		
	}
}
