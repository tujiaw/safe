#include "SettingDialog.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPainter>
#include "Common.h"
#include "PushButton.h"

SettingDialog::SettingDialog(QWidget *parent)
	: DropWidget(parent)
{
	this->resize(560, 400);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addLayout(createTitleLayout());
	mainLayout->addWidget(createContentWidget());
	mainLayout->addLayout(createBottomLayout());
	mainLayout->setSpacing(5);
	mainLayout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(mainLayout);
}

void SettingDialog::paintEvent(QPaintEvent *event)
{
	DropWidget::paintEvent(event);
	int height = 65;
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
	painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH), QPixmap(DEFAULT_SKIN));
	painter.drawRect(QRect(SHADOW_WIDTH, height, this->width()-2*SHADOW_WIDTH, this->height()-height-SHADOW_WIDTH));
}

QHBoxLayout *SettingDialog::createTitleLayout()
{
	QLabel *titleIconLabel = new QLabel();
	QPixmap titlePixmap(":/img/safe");
	titleIconLabel->setPixmap(titlePixmap);
	titleIconLabel->setFixedSize(16, 16);
	titleIconLabel->setScaledContents(true);

	QLabel *titleLabel = new QLabel(tr("360 safe setting"));
	titleLabel->setObjectName("whiteLabel");

	PushButton *closeButton = new PushButton();
	closeButton->setPicName(QStringList() << ":/sysButton/close" << ":/sysButton/close_hover" << ":/sysButton/close_pressed");
	closeButton->setToolTip(tr("close"));
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout *layout = new QHBoxLayout();
	layout->addWidget(titleIconLabel, 0, Qt::AlignVCenter);
	layout->addWidget(titleLabel, 0, Qt::AlignVCenter);
	layout->addStretch();
	layout->addWidget(closeButton, 0, Qt::AlignTop);
	layout->setSpacing(5);
	layout->setContentsMargins(10, 5, 5, 10);

	return layout;
}

QTabWidget *SettingDialog::createContentWidget()
{
	QTabWidget *tabWidget = new QTabWidget();
	return tabWidget;
}

QHBoxLayout *SettingDialog::createBottomLayout()
{
	QHBoxLayout *layout = new QHBoxLayout();
	return layout;
}
