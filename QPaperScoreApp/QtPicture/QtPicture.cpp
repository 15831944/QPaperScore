#include "QtPicture.h"
#include "QtPicturePreview.h"
#include <QPainter>
QtPicture::QtPicture(QWidget *parent,QString strPicPath)
	:QWidget(parent), m_strPicPath(strPicPath)
{
}

QtPicture::~QtPicture()
{
}

void QtPicture::mouseDoubleClickEvent(QMouseEvent *e)
{
	auto b = e->button();
	if (b == Qt::LeftButton)
	{
		QtPicturePreview *dlg = new QtPicturePreview(this,m_strPicPath);
		dlg->setWindowModality(Qt::WindowModal);
		dlg->show();
	}
	//return QWidget::mouseDoubleClickEvent(e);
}

void QtPicture::paintEvent(QPaintEvent *e)
{
	QPainter paint(this);
	QPixmap pic;
	if (pic.load(m_strPicPath))
	{
		paint.drawPixmap(this->rect(), pic);
	}
}