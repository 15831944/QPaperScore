#ifndef _QPAPERSCORE_H
#define _QPAPERSCORE_H
#include <QtWidgets>
#include <QtWidgets/QMainWindow>
#include "ui_QPaperScore.h"

class QPaperScore : public QMainWindow
{
	Q_OBJECT

public:
	QPaperScore(QWidget *parent = Q_NULLPTR);
	virtual ~QPaperScore();
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

	void doPreview(int nRow);

protected:
	bool m_IsSet;//设置模式还是预览模式
	void setmode();
	void settoSetMode();
	void settoPreviewMode();
	void removeResult();
};

#endif
