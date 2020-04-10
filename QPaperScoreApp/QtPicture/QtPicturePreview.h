#pragma once

#include <QWidget>
#include <QDialog>

class QtPicturePreview : public QDialog
{
	Q_OBJECT

public:
	QtPicturePreview(QWidget *parent=NULL,QString strPicPath="");
	virtual ~QtPicturePreview();

protected:
	QString m_strPicPath;

	virtual void paintEvent(QPaintEvent *e);
	QPixmap pic;
};
