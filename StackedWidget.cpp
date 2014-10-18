#include "stackedwidget.h"

StackedWidget::StackedWidget(QWidget *parent)
	: QStackedWidget(parent)
{
	QPalette palette;
	palette.setBrush(QPalette::Window, QBrush(Qt::white));
	this->setPalette(palette);
	this->setAutoFillBackground(true);
}

StackedWidget::~StackedWidget()
{

}
