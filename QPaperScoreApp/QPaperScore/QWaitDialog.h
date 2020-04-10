#pragma once

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
