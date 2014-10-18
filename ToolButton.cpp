#include "ToolButton.h"
#include <QMouseEvent>
#include <QPainter>

ToolButton::ToolButton(const QString &pic, QWidget *parent)
	: QToolButton(parent)
{
	QPalette myPalette = this->palette();
	myPalette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
	this->setPalette(myPalette);

	QFont &myFont = const_cast<QFont&>(this->font());
	myFont.setWeight(QFont::Bold);

	this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	QPixmap pixmap(pic);
	this->setIcon(pixmap);
	this->setIconSize(pixmap.size());

	this->setFixedSize(pixmap.width() + 25, pixmap.height() + 25);
	
	this->setAutoRaise(true);
	this->setObjectName("transparentToolButton");

	isMouseHover_ = false;
	isMousePress_ = false;
}

void ToolButton::setMousePress(bool val)
{
	isMousePress_ = val;
	update();
}

void ToolButton::enterEvent(QEvent *)
{
	isMouseHover_ = true;
}

void ToolButton::leaveEvent(QEvent *)
{
	isMouseHover_ = false;
}

void ToolButton::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		emit clicked();
	}
}

void ToolButton::paintEvent(QPaintEvent *event)
{
	if (isMouseHover_ || isMousePress_) {
		QPainter painter(this);
		QPen pen(Qt::NoBrush, 1);
		painter.setPen(pen);
		QLinearGradient linear(this->rect().topLeft(), this->rect().bottomLeft());
		QColor color(230, 230, 230, 0);
		linear.setColorAt(0, color);
		color.setAlpha(100);
		linear.setColorAt(0.5, color);
		color.setAlpha(150);
		linear.setColorAt(1, color);
		painter.setBrush(linear);
		painter.drawRect(this->rect());
	}
	QToolButton::paintEvent(event);
}