#pragma once
#include <QWidget>
#include <qevent.h>

#include "qtpicture_global.h"

class QTPICTURE_EXPORT QtPicture
	:public QWidget
{
	Q_OBJECT
public:
	QtPicture(QWidget *parent = NULL, QString strPicPath = "");
	virtual ~QtPicture();

protected:
	virtual void mouseDoubleClickEvent(QMouseEvent *e);

protected:
	QString m_strPicPath;
	virtual void paintEvent(QPaintEvent *e);
};
