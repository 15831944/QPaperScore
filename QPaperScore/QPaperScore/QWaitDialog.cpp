#include "stdafx.h"
#include "QWaitDialog.h"
QWaitDialog::QWaitDialog(QWidget *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
}