#include "DropWidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <qmath.h>
#include <QDebug>

DropWidget::DropWidget(QWidget *parent)
	: QDialog(parent), isMousePress_(false)
{
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
}

DropWidget::~DropWidget(void)
{
}

void DropWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		isMousePress_ = true;
	}
	movePoint_ = event->globalPos() - this->pos();
}

void DropWidget::mouseReleaseEvent(QMouseEvent *event)
{
	isMousePress_ = false;
}

void DropWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (isMousePress_) {
		this->move(event->globalPos() - movePoint_);
	}
}

void DropWidget::paintEvent(QPaintEvent *event)
{
	QPainterPath painterPath;
	painterPath.setFillRule(Qt::WindingFill);
	painterPath.addRect(10, 10, this->width()-20, this->height()-20);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(painterPath, QBrush(Qt::white));

	QColor color(0, 0, 0, 50);
	for (int i=0; i<10; i++) {
		color.setAlpha(150 - qSqrt(i) * 50);
		painter.setPen(color);
		painter.drawRect(10-i, 10-i, this->width()-(10-i)*2, this->height()-(10-i)*2);
	}

}
