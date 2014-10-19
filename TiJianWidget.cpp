#include "TiJianWidget.h"
#include <QSplitter>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

TiJianWidget::TiJianWidget(QWidget *parent)
	: QWidget(parent)
{
	mainSplitter_ = new QSplitter();
	leftWidget_ = new QWidget();
	rightSplitter_ = new QSplitter();
	rightTopWidget_ = new QWidget();
	rightCenterFirstWidget_ = new QWidget();
	rightCenterSecondWidget_ = new QWidget();
	rightBottomWidget_ = new QWidget();

	initLeft();
	initRightTop();
	initRightCenterFirst();
	initRightCenterSecond();
	initRightBottom();

	rightTopWidget_->setFixedSize(250, 130);
	rightCenterFirstWidget_->setFixedSize(250, 90);
	rightBottomWidget_->setFixedSize(250, 30);

	rightSplitter_->addWidget(rightTopWidget_);
	rightSplitter_->addWidget(rightCenterFirstWidget_);
	rightSplitter_->addWidget(rightCenterSecondWidget_);
	rightSplitter_->addWidget(rightBottomWidget_);
	rightSplitter_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	rightSplitter_->setOrientation(Qt::Vertical);
	rightSplitter_->setHandleWidth(1);

	mainSplitter_->addWidget(leftWidget_);
	mainSplitter_->addWidget(rightSplitter_);
	mainSplitter_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	mainSplitter_->setOrientation(Qt::Horizontal);
	mainSplitter_->setHandleWidth(1);

	QHBoxLayout *mainLayout = new QHBoxLayout();
	mainLayout->addWidget(mainSplitter_);
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(mainLayout);
}

void TiJianWidget::initLeft()
{
	QLabel *computerLabel = new QLabel();
	QPixmap computerPixmap(":/contentWidget/computer");
	computerLabel->setPixmap(computerPixmap);
	computerLabel->setFixedSize(computerPixmap.size());

	QLabel *suggestLabel = new QLabel();
	suggestLabel->setText(tr("suggest"));
	QFont suggestFont = suggestLabel->font();
	suggestFont.setPointSize(12);
	suggestFont.setBold(true);
	suggestLabel->setFont(suggestFont);
	suggestLabel->setObjectName("grayLabel");

	QLabel *lastResultLabel = new QLabel();
	lastResultLabel->setText(tr("system safe"));
	QFont lastResultFont = lastResultLabel->font();
	lastResultFont.setBold(true);
	lastResultLabel->setFont(lastResultFont);
	lastResultLabel->setObjectName("grayLabel");

	QPushButton *powerButton = new QPushButton();
	powerButton->setText(tr("power"));
	QPixmap powerPixmap(":/contentWidget/power");
	powerButton->setIcon(powerPixmap);
	powerButton->setIconSize(powerPixmap.size());
	powerButton->setFixedSize(180, 70);
	QFont powerFont = powerButton->font();
	powerFont.setPointSize(16);
	powerButton->setFont(powerFont);
	powerButton->setObjectName("greenButton");

	QVBoxLayout *vLayout = new QVBoxLayout();
	vLayout->addWidget(suggestLabel);
	vLayout->addWidget(lastResultLabel);
	vLayout->addStretch();
	vLayout->setSpacing(15);
	vLayout->setContentsMargins(0, 20, 0, 0);

	QHBoxLayout *hLayout = new QHBoxLayout();
	hLayout->addWidget(computerLabel, 0, Qt::AlignTop);
	hLayout->addLayout(vLayout);
	hLayout->addStretch();
	hLayout->setSpacing(20);
	hLayout->setContentsMargins(30, 20, 0, 0);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addLayout(hLayout);
	mainLayout->addWidget(powerButton, 0, Qt::AlignCenter);
	mainLayout->addStretch();
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	leftWidget_->setLayout(mainLayout);
}

QPushButton *createPrivButton(const QString &pixmapPath)
{
	QPushButton *btn = new QPushButton();
	QPixmap pixmap(pixmapPath);
	btn->setIcon(pixmap);
	btn->setFixedSize(pixmap.size());
	btn->setCursor(Qt::PointingHandCursor);
	return btn;
}

void TiJianWidget::initRightTop()
{
	QPushButton *loginButton = new QPushButton();
	loginButton->setText(tr("login home"));
	loginButton->setFixedSize(240, 60);
	QFont loginFont = loginButton->font();
	loginFont.setBold(true);
	loginFont.setPointSize(12);
	loginButton->setFont(loginFont);
	loginButton->setObjectName("loginButton");

	QLabel *privLabel = new QLabel();
	privLabel->setPixmap(QPixmap(":/contentWidget/priv"));

	QLabel *infoLabel = new QLabel();
	infoLabel->setText(tr("show beautifull icon"));

	QPushButton *registerButton = new QPushButton();
	registerButton->setText(tr("register"));
	registerButton->setCursor(Qt::PointingHandCursor);
	registerButton->setObjectName("blueButton");

	QLabel *privilegeLabel = new QLabel();
	privilegeLabel->setText(tr("privilege power"));

	QPushButton *safeButton = createPrivButton(":/contentWidget/360");
	QPushButton *tabButton = createPrivButton(":/contentWidget/tab");
	QPushButton *petButton = createPrivButton(":/contentWidget/pet");
	QPushButton *lotteryButton = createPrivButton(":/contentWidget/lottery");
	QPushButton *cloudButton = createPrivButton(":/contentWidget/cloud_five");
	QPushButton *caipiaoButton = createPrivButton(":/contentWidget/caipiao");

	QHBoxLayout *loginLayout = new QHBoxLayout();
	loginLayout->addWidget(loginButton);
	loginLayout->addStretch();
	loginLayout->setContentsMargins(15, 0, 0, 0);

	QHBoxLayout *privLayout = new QHBoxLayout();
	privLayout->addWidget(privLabel);
	privLayout->addWidget(infoLabel);
	privLayout->addWidget(registerButton);
	privLayout->addStretch();
	privLayout->setSpacing(5);
	privLayout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout *privilegeLayout = new QHBoxLayout();
	privilegeLayout->addWidget(privilegeLabel);
	privilegeLayout->addWidget(safeButton);
	privilegeLayout->addWidget(tabButton);
	privilegeLayout->addWidget(petButton);
	privilegeLayout->addWidget(lotteryButton);
	privilegeLayout->addWidget(cloudButton);
	privilegeLayout->addWidget(caipiaoButton);
	privilegeLayout->addStretch();
	privilegeLayout->setSpacing(8);
	privilegeLayout->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addLayout(loginLayout);
	mainLayout->addLayout(privLayout);
	mainLayout->addLayout(privilegeLayout);
	mainLayout->addStretch();
	mainLayout->setSpacing(5);
	mainLayout->setContentsMargins(10, 10, 10, 10);

	rightTopWidget_->setLayout(mainLayout);
}

QToolButton* createRightCenterFirstButton(const QString &text, const QString &pixmapPath)
{
	QToolButton *btn = new QToolButton();
	btn->setText(text);
	btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	QPixmap pixmap(pixmapPath);
	btn->setIcon(pixmap);
	btn->setIconSize(pixmap.size());
	btn->setFixedSize(pixmap.width() + 25, pixmap.height() + 25);
	btn->setObjectName("transparentToolButton");
	return btn;
}

void TiJianWidget::initRightCenterFirst()
{
	QToolButton *fireproofButton = createRightCenterFirstButton(tr("fireproof"), ":/contentWidget/fireproof");
	QToolButton *triggermanButton = createRightCenterFirstButton(tr("triggerman"), ":/contentWidget/triggerman");
	QToolButton *netShopButton = createRightCenterFirstButton(tr("net shop"), ":/contentWidget/net_shop");

	QHBoxLayout *mainLayout = new QHBoxLayout();
	mainLayout->addWidget(fireproofButton);
	mainLayout->addWidget(triggermanButton);
	mainLayout->addWidget(netShopButton);
	rightCenterFirstWidget_->setLayout(mainLayout);
}

void TiJianWidget::initRightCenterSecond()
{
	QLabel *functionLabel = new QLabel();
	functionLabel->setText(tr("function"));
	QFont functionFont = functionLabel->font();
	functionFont.setBold(true);
	functionLabel->setFont(functionFont);
	functionLabel->setObjectName("infoLabel");

	QPushButton *moreButton = new QPushButton();
	moreButton->setText(tr("more"));
	moreButton->setFixedSize(50, 25);
	moreButton->setCursor(Qt::PointingHandCursor);
	moreButton->setObjectName("blueButton");

	QList<QPair<QString, QString>> funcList;
	funcList.append(QPair<QString, QString>(tr("recovery"), ":/contentWidget/recovery"));
	funcList.append(QPair<QString, QString>(tr("mobile"), ":/contentWidget/mobile"));
	funcList.append(QPair<QString, QString>(tr("game box"), ":/contentWidget/game_box"));
	funcList.append(QPair<QString, QString>(tr("desktop"), ":/contentWidget/desktop"));
	funcList.append(QPair<QString, QString>(tr("net repair"), ":/contentWidget/net_repair"));
	funcList.append(QPair<QString, QString>(tr("auto run"), ":/contentWidget/auto_run"));
	funcList.append(QPair<QString, QString>(tr("net speed"), ":/contentWidget/net_speed"));
	funcList.append(QPair<QString, QString>(tr("net pretext"), ":/contentWidget/net_pretext"));
	funcList.append(QPair<QString, QString>(tr("first add"), ":/contentWidget/first_add"));

	QHBoxLayout *hLayout = new QHBoxLayout();
	hLayout->addWidget(functionLabel);
	hLayout->addWidget(moreButton);
	hLayout->addStretch();
	hLayout->addWidget(moreButton);
	hLayout->setSpacing(0);
	hLayout->setContentsMargins(10, 5, 0, 0);

	QGridLayout *gLayout = new QGridLayout();
	for (int i=0; i<funcList.size(); i++) {
		QToolButton *funcButton = new QToolButton();
		funcButton->setText(funcList[i].first);
		funcButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
		QPixmap pixmap(funcList[i].second);
		funcButton->setIcon(pixmap);
		funcButton->setIconSize(pixmap.size());
		funcButton->setFixedSize(pixmap.width() + 50, pixmap.height() + 35);
		funcButton->setObjectName("functionButton");
		gLayout->addWidget(funcButton, i/3, i%3);
	}
	gLayout->setSpacing(0);
	gLayout->setContentsMargins(5, 0, 5, 5);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addLayout(hLayout);
	mainLayout->addLayout(gLayout);
	mainLayout->addStretch();
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	rightCenterSecondWidget_->setLayout(mainLayout);
}

void TiJianWidget::initRightBottom()
{
	QLabel *iconLabel = new QLabel();
	QPixmap iconPixmap(":/contentWidget/cloud");
	iconLabel->setPixmap(iconPixmap);
	iconLabel->setFixedSize(iconPixmap.size());

	QLabel *connectLabel = new QLabel();
	connectLabel->setText(tr("connect success"));

	QLabel *versionLabel = new QLabel();
	versionLabel->setText(tr("version"));
	
	QPushButton *upgradeButton = new QPushButton();
	QPixmap upgradePixmap(":/contentWidget/version");
	upgradeButton->setIcon(upgradePixmap);
	upgradeButton->setIconSize(upgradePixmap.size());
	upgradeButton->setFixedSize(20, 20);
	upgradeButton->setObjectName("transparentButton");

	QHBoxLayout *mainLayout = new QHBoxLayout();
	mainLayout->addWidget(iconLabel);
	mainLayout->addWidget(connectLabel);
	mainLayout->addStretch();
	mainLayout->addWidget(versionLabel);
	mainLayout->addWidget(upgradeButton);
	mainLayout->setSpacing(5);
	mainLayout->setContentsMargins(10, 0, 10, 0);

	rightBottomWidget_->setLayout(mainLayout);
}