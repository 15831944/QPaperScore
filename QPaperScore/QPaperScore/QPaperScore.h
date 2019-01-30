#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QPaperScore.h"

class QPaperScore : public QMainWindow
{
	Q_OBJECT

public:
	QPaperScore(QWidget *parent = Q_NULLPTR);

private:
	Ui::QPaperScoreClass ui;

protected:
	void initUI();

public:
	
	void doAddTemplate();
	void doDelTemplate();
	void doClearTemplate();

	void doAddPaper();
	void doDelPaper();
	void doClearPaper();
	void doCal();
	void doExport();
};
