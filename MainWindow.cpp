#include "MainWindow.h"
#include <QIcon>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QPainter>
#include "TitleWidget.h"
#include "StackedWidget.h"
#include "TiJianWidget.h"
#include "ChaShaWidget.h"
#include "MainMenu.h"
#include "About.h"
#include "Common.h"

MainWindow::MainWindow(QWidget *parent)
	: DropWidget(parent)
{
	this->setMinimumSize(900, 600);
	this->setWindowIcon(QIcon(":/img/safe"));

	stackedWidget_ = new StackedWidget();
	tijianWidget_ = new TiJianWidget();
	chashaWidget_ = new ChaShaWidget();
	stackedWidget_->addWidget(tijianWidget_);
	stackedWidget_->addWidget(chashaWidget_);

	titleWidget_ = new TitleWidget();
	mainMenu_ = new MainMenu(this);

	QVBoxLayout *centerLayout = new QVBoxLayout();
	centerLayout->addWidget(stackedWidget_);
	centerLayout->setSpacing(0);
	centerLayout->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addWidget(titleWidget_);
	mainLayout->addLayout(centerLayout);
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);
	this->setLayout(mainLayout);

	connect(titleWidget_, SIGNAL(showMainMenu()), this, SLOT(slotShowMainMenu()));
	connect(titleWidget_, SIGNAL(closeWidget()), this, SLOT(close()));
	connect(titleWidget_, SIGNAL(turnPage(int)), this, SLOT(slotTurnPage(int)));

	connect(mainMenu_, SIGNAL(sigAboutUs()), this, SLOT(slotShowAbout()));

	titleWidget_->slotTurnPage(0);
	slotTurnPage(0);
	bgName_ = DEFAULT_SKIN;
}

MainWindow::~MainWindow()
{

}

void MainWindow::slotShowMainMenu()
{
	QPoint point = this->rect().topRight();
	point.setX(point.x() - 84);
	point.setY(point.y() + 25);
	mainMenu_->exec(this->mapToGlobal(point));
}

void MainWindow::slotShowAbout()
{
	About about(this);
	about.exec();
}

void MainWindow::slotTurnPage(int index)
{
	if (index < stackedWidget_->count()) {
		stackedWidget_->setCurrentIndex(index);
	}
}

void MainWindow::paintEvent(QPaintEvent *event)
{
	DropWidget::paintEvent(event);
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH), QPixmap(bgName_));
}