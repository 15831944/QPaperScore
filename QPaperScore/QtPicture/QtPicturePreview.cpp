#include "QtPicturePreview.h"
#include <QPainter>
QtPicturePreview::QtPicturePreview(QWidget *parent, QString strPicPath)
	: QDialog(parent),m_strPicPath(strPicPath)
{
	
	pic.load(m_strPicPath);
	if ((pic.size().height() > 800) || (pic.size().width() > 1000))
		this->resize(QSize(1000, 800));
	else
	    this->resize(pic.size());
	
}

QtPicturePreview::~QtPicturePreview()
{
}

void QtPicturePreview::paintEvent(QPaintEvent *e)
{
	QPainter paint(this);
	paint.drawPixmap(this->rect(), pic);
}
