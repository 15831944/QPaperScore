#ifndef _QWAITDIALOG_H
#define _QWAITDIALOG_H

#include <QtWidgets/QMainWindow>
#include "ui_WaitDialog.h"

class QWaitDialog : public QDialog
{
	Q_OBJECT

public:
	QWaitDialog(QWidget *parent = Q_NULLPTR);

private:
	Ui::Dialog ui;
};

#endif
