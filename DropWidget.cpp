#include "DropWidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <qmath.h>
#include <QDebug>
#include <qt_windows.h>
#include <QDesktopWidget>
#include <QApplication>

DropWidget::DropWidget(QWidget *parent, bool canStretch)
	: QDialog(parent), isMousePress_(false), canStretch_(canStretch)
{
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);

	//QDesktopWidget *desktop = QApplication::desktop();
	//this->setGeometry(desktop->availableGeometry());
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

void DropWidget::mouseReleaseEvent(QMouseEvent *)
{
	isMousePress_ = false;
}

void DropWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (isMousePress_) {
		this->move(event->globalPos() - movePoint_);
	}
}

void DropWidget::paintEvent(QPaintEvent *)
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

bool DropWidget::nativeEvent(const QByteArray & eventType, void * message, long * result)
{
	if (!canStretch_) {
		return false;
	}

	Q_UNUSED(eventType);
    const int HIT_BORDER = 15;
    const MSG *msg=static_cast<MSG*>(message);
    if(msg->message == WM_NCHITTEST) {
        int xPos = ((int)(short)LOWORD(msg->lParam)) - this->frameGeometry().x();
        int yPos = ((int)(short)HIWORD(msg->lParam)) - this->frameGeometry().y();
        if(this->childAt(xPos,yPos) == 0) {
            *result = HTCAPTION;
        } else {
            return false;
        }
        if(xPos > 0 && xPos < HIT_BORDER) {
            *result = HTLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0)) {
            *result = HTRIGHT;
        }
        if(yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOP;
        }
        if(yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOM;
        }
        if(xPos > 0 && xPos < HIT_BORDER && yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOPLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0) && yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOPRIGHT;
        }
        if(xPos > 0 && xPos < HIT_BORDER && yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOMLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0) && yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOMRIGHT;
        }
        return true;
    }
    return false;
}