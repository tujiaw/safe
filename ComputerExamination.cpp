#include "ComputerExamination.h"
#include <QSplitter>
#include <QLabel>
#include <QPushButton>

ComputerExamination::ComputerExamination(QWidget *parent)
	: QWidget(parent)
{

}

void ComputerExamination::initLeft()
{
	leftWidget_ = new QWidget();
	computerLabel_ = new QLabel();
	suggestLabel_ = new QLabel();
	immediateMedicalBtn_ = new QPushButton();
	leftWidget_->resize(650, 500);

	QPixmap computerPixmap(":/contentWidget/computer");
	computerLabel_->setPixmap(computerPixmap);
}