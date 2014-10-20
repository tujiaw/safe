#include "SettingDialog.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>
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
	mainLayout->addStretch();
	mainLayout->addLayout(createBottomLayout());
	mainLayout->addStretch();
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);
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
	layout->setContentsMargins(10, 0, 0, 10);

	return layout;
}

QTabWidget *SettingDialog::createContentWidget()
{
	QTabWidget *tabWidget = new QTabWidget();
	tabWidget->setFixedSize(this->width(), 320);

	QWidget *upgradePathTab = new QWidget();
	QWidget *advanceSettingTab = new QWidget();
	QWidget *experienceSettingTab = new QWidget();
	QWidget *userSettingTab = new QWidget();
	QWidget *improvePlanTab = new QWidget();
	QWidget *cloudSafePlanTab = new QWidget();

	QGroupBox *upgradePathGroupBox = new QGroupBox();
	upgradePathGroupBox->setTitle(tr("rise style title"));
	QFont upgradePathFont = upgradePathGroupBox->font();
	upgradePathFont.setBold(true);
	upgradePathGroupBox->setFont(upgradePathFont);
	upgradePathGroupBox->setFixedSize(480, 250);

	QRadioButton *autoRiseRadioButton = new QRadioButton(tr("auto rise"));
	QRadioButton *noAutoRiseRadioButton = new QRadioButton(tr("not auto rise"));
	QCheckBox *riseMummyCheckBox = new QCheckBox(tr("rise mummy"));
	QCheckBox *gameCheckBox = new QCheckBox(tr("game"));
	QCheckBox *g3CheckBox = new QCheckBox(tr("3g"));
	QCheckBox *p2pCheckBox = new QCheckBox(tr("p2p"));
	QCheckBox *bakMummyCheckBox = new QCheckBox(tr("mymmy"));

	QHBoxLayout *riseMummyLayout = new QHBoxLayout();
	riseMummyLayout->addWidget(riseMummyCheckBox);
	riseMummyLayout->setSpacing(0);
	riseMummyLayout->setContentsMargins(20, 0, 0, 0);

	QVBoxLayout *groupLayout = new QVBoxLayout();
	groupLayout->addWidget(autoRiseRadioButton);
	groupLayout->addWidget(noAutoRiseRadioButton);
	groupLayout->addLayout(riseMummyLayout);
	groupLayout->addWidget(gameCheckBox);
	groupLayout->addWidget(g3CheckBox);
	groupLayout->addWidget(p2pCheckBox);
	groupLayout->addWidget(bakMummyCheckBox);
	groupLayout->setSpacing(0);
	groupLayout->setContentsMargins(30, 0, 0, 0);
	upgradePathGroupBox->setLayout(groupLayout);
	
	QHBoxLayout *mainLayout = new QHBoxLayout();
	mainLayout->addWidget(upgradePathGroupBox);
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0, 0, 0, 0);
	upgradePathTab->setLayout(mainLayout);

	tabWidget->addTab(upgradePathTab, tr("rise style"));
	tabWidget->addTab(advanceSettingTab, tr("advanced setting"));
	tabWidget->addTab(experienceSettingTab, tr("physical setting"));
	tabWidget->addTab(userSettingTab, tr("user setting"));
	tabWidget->addTab(improvePlanTab, tr("improve program"));
	tabWidget->addTab(cloudSafePlanTab, tr("secure program"));
	return tabWidget;
}

QHBoxLayout *SettingDialog::createBottomLayout()
{
	QPushButton *okButton = new QPushButton(tr("ok"));
	okButton->setObjectName("okButton");
	okButton->setFixedSize(75, 25);

	QPushButton *cancelButton = new QPushButton(tr("cancel"));
	cancelButton->setObjectName("okButton");
	cancelButton->setFixedSize(75, 25);

	QHBoxLayout *mainLayout = new QHBoxLayout();
	mainLayout->addStretch();
	mainLayout->addWidget(okButton);
	mainLayout->addWidget(cancelButton);
	mainLayout->setSpacing(20);
	mainLayout->setContentsMargins(0, 10, 20, 20);

	connect(okButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

	return mainLayout;
}
