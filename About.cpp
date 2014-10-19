#include "About.h"
#include <QLabel>
#include <QPushButton>
#include "PushButton.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include "Common.h"

About::About(QWidget *parent)
	: DropWidget(parent)
{
	this->setFixedSize(520, 290);

	QLabel *titleIconLabel = new QLabel();
	QPixmap titlePixmap(":/img/safe");
	titleIconLabel->setPixmap(titlePixmap);
	titleIconLabel->setFixedSize(16, 16);
	titleIconLabel->setScaledContents(true);

	QLabel *titleLabel = new QLabel(tr("title"));
	titleLabel->setFixedHeight(30);
	titleLabel->setObjectName("whiteLabel");

	PushButton *closeButton = new PushButton();
	closeButton->setPicName(QStringList() << ":/sysButton/close" << ":/sysButton/close_hover" << ":/sysButton/close_pressed");
	closeButton->setToolTip(tr("close"));
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	QLabel *titleInfoLabel = new QLabel(tr("360 safe"));
	QFont titleInfoFont(QStringLiteral("Î¢ÈíÑÅºÚ"), 14, QFont::Bold, false);
	titleInfoLabel->setFont(titleInfoFont);
	titleInfoLabel->setObjectName("infoLabel");

	QLabel *infoLabel = new QLabel(tr("infoLabel"));
	QFont infoFont = infoLabel->font();
	infoFont.setBold(true);
	infoLabel->setFont(infoFont);
	infoLabel->setObjectName("infoLabel");

	QLabel *versionLabel = new QLabel(tr("version") + QString("9.2.0.2001"));
	QLabel *mummyLabel = new QLabel(tr("mummy") + QString("2014-10-19"));
	QLabel *copyrightLabel = new QLabel(tr("copyright"));
	copyrightLabel->setObjectName("grayLabel");

	QLabel *bigIconLabel = new QLabel();
	QPixmap bigPixmap(":/img/360safe");
	bigIconLabel->setPixmap(bigPixmap);
	bigIconLabel->setFixedSize(bigPixmap.size());

	QPushButton *okButton = new QPushButton(tr("ok"));
	connect(okButton, SIGNAL(clicked()), this, SLOT(close()));
	okButton->setFixedSize(75, 25);
	okButton->setObjectName("okButton");

	QHBoxLayout *titleLayout = new QHBoxLayout();
	titleLayout->addWidget(titleIconLabel, 0, Qt::AlignVCenter);
	titleLayout->addWidget(titleLabel, 0, Qt::AlignVCenter);
	titleLayout->addStretch();
	titleLayout->addWidget(closeButton, 0, Qt::AlignTop);
	titleLayout->setSpacing(5);
	titleLayout->setContentsMargins(10, 0, 5, 0);

	QVBoxLayout *contentLeftLayout = new QVBoxLayout();
	contentLeftLayout->addWidget(titleInfoLabel);
	contentLeftLayout->addWidget(infoLabel);
	contentLeftLayout->addWidget(versionLabel);
	contentLeftLayout->addWidget(mummyLabel);
	contentLeftLayout->addWidget(copyrightLabel);
	contentLeftLayout->addStretch();
	contentLeftLayout->setSpacing(5);
	contentLeftLayout->setContentsMargins(0, 15, 0, 0);
	infoLabel->setContentsMargins(0, 0, 0, 40);

	QHBoxLayout *contentLayout = new QHBoxLayout();
	contentLayout->addLayout(contentLeftLayout);
	contentLayout->addWidget(bigIconLabel);
	contentLayout->setSpacing(5);
	contentLayout->setContentsMargins(40, 0, 20, 10);

	QHBoxLayout *bottomLayout = new QHBoxLayout();
	bottomLayout->addStretch();
	bottomLayout->addWidget(okButton);
	bottomLayout->setSpacing(0);
	bottomLayout->setContentsMargins(0, 0, 30, 20);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addLayout(titleLayout);
	mainLayout->addStretch();
	mainLayout->addLayout(contentLayout);
	mainLayout->addLayout(bottomLayout);
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);

	this->setLayout(mainLayout);
}

void About::paintEvent(QPaintEvent *event)
{
	DropWidget::paintEvent(event);
	int titleHeight = 35;
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH), QPixmap(DEFAULT_SKIN));
	painter.drawRect(QRect(SHADOW_WIDTH, titleHeight, this->width()-2*SHADOW_WIDTH, this->height()-titleHeight-SHADOW_WIDTH));
}