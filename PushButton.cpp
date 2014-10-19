#include "PushButton.h"
#include <QMouseEvent>
#include <QPainter>

PushButton::PushButton(QWidget *parent)
	: QPushButton(parent), status_(NORMAL)
{

}
void PushButton::setPicName(const QStringList &pics)
{
	Q_ASSERT(pics.size() > 0);
	pics_ = pics;
	this->setFixedSize(QPixmap(pics_[0]).size());
}

void PushButton::enterEvent(QEvent *)
{
	status_ = ENTER;
	update();
}

void PushButton::leaveEvent(QEvent *)
{
	status_ = NORMAL;
	update();
}

void PushButton::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		status_ = PRESS;
		update();
	}
}

void PushButton::mouseReleaseEvent(QMouseEvent *event)
{
	if (status_ == PRESS && event->button() == Qt::LeftButton) {
		status_ = RELEASE;
		update();
	}

	if (status_ == RELEASE && this->rect().contains(event->pos())) {
		emit clicked();
	} 
}

void PushButton::paintEvent(QPaintEvent *)
{
	if (pics_.size() == 0) {
		return;
	}

	QPainter painter(this);
	QPixmap pixmap;
	switch (status_) {
	case NORMAL:
		pixmap.load(pics_[0]);
		break;

	case ENTER:
		if (pics_.size() > 1) {
			pixmap.load(pics_[1]);
		}
		break;

	case PRESS:
		if (pics_.size() > 2) {
			pixmap.load(pics_[2]);
		}
		break;

	case RELEASE:
		if (pics_.size() > 3) {
			pixmap.load(pics_[3]);
		} else if (pics_.size() > 1) {
			pixmap.load(pics_[1]);
		}
		break;

	default:
		pixmap.load(pics_[0]);
		break;
	}

	if (pixmap.isNull()) {
		pixmap.load(pics_[0]);
	}
	painter.drawPixmap(this->rect(), pixmap);
}