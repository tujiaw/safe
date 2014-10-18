#include "TitleWidget.h"
#include "PushButton.h"
#include "ToolButton.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSignalMapper>

TitleWidget::TitleWidget(QWidget *parent)
	: QWidget(parent)
{
	versionTitle_ = new QLabel();
	skinBtn_ = new PushButton();
	mainMenuBtn_ = new PushButton();
	minBtn_ = new PushButton();
	feedbackBtn_ = new PushButton();
	closeBtn_ = new PushButton();
	medalBtn_ = new PushButton();

	medalBtn_->setPicName(QStringList() << ":/sysButton/medal" << ":/sysButton/medal_hover" << ":/sysButton/medal_pressed");
	skinBtn_->setPicName(QStringList() << ":/sysButton/skin" << ":/sysButton/skin_hover" << ":/sysButton/skin_pressed");
	minBtn_->setPicName(QStringList() << ":/sysButton/min" << ":/sysButton/min_hover" << ":/sysButton/min_pressed");
	closeBtn_->setPicName(QStringList() << ":/sysButton/close" << ":/sysButton/close_hover" << ":/sysButton/close_pressed");
	mainMenuBtn_->setPicName(QStringList() << ":/sysButton/menu" << ":/sysButton/menu_hover" << ":/sysButton/menu_pressed");
	feedbackBtn_->setPicName(QStringList() << ":/sysButton/feedback" << ":/sysButton/feedback_hover" << ":/sysButton/feedback_pressed");

	connect(skinBtn_, SIGNAL(clicked()), this, SIGNAL(showSkin()));
	connect(mainMenuBtn_,SIGNAL(clicked()), this, SIGNAL(showMainMenu()));
	connect(minBtn_, SIGNAL(clicked()), this, SIGNAL(showMin()));
	connect(closeBtn_, SIGNAL(clicked()), this, SIGNAL(closeWidget()));

	QHBoxLayout *titleLayout = new QHBoxLayout();
	titleLayout->addWidget(versionTitle_, 0, Qt::AlignVCenter);
	titleLayout->addStretch();
	titleLayout->addWidget(medalBtn_, 0, Qt::AlignTop);
	titleLayout->addWidget(skinBtn_, 0, Qt::AlignTop);
	titleLayout->addWidget(feedbackBtn_, 0, Qt::AlignTop);
	titleLayout->addWidget(mainMenuBtn_, 0, Qt::AlignTop);
	titleLayout->addWidget(minBtn_, 0, Qt::AlignTop);
	titleLayout->addWidget(closeBtn_, 0, Qt::AlignTop);
	titleLayout->addSpacing(0);
	//titleLayout->setContentsMargins(0, 0, 25, 0);
	versionTitle_->setContentsMargins(15, 0, 0, 0);
	//skinBtn_->setContentsMargins(0, 0, 10, 0);

	QStringList strList;
	strList << ":/toolWidget/tiJian"<<":/toolWidget/muMa"<<":/toolWidget/repair"<<":/toolWidget/qingLi"
		<<":/toolWidget/jiaSu"<<":/toolWidget/expert"<<":/toolWidget/menZhen"<<":/toolWidget/gongNeng";
	QHBoxLayout *buttonLayout = new QHBoxLayout();
	QSignalMapper *mapper = new QSignalMapper(this);
	for (int i=0; i<strList.size(); i++) {
		ToolButton *tb = new ToolButton(strList.at(i));
		btnList_.append(tb);
		connect(tb, SIGNAL(clicked()), mapper, SLOT(map()));
		buttonLayout->addWidget(tb, 0, Qt::AlignBottom);
	}
	connect(mapper, SIGNAL(mapped(QString)), this, SLOT(turnPage(QString)));

	safe360Label_ = new QLabel();
	safeLabel_ = new QLabel();
	QVBoxLayout *safeLayout = new QVBoxLayout();
	safeLayout->addWidget(safe360Label_);
	safeLayout->addWidget(safeLabel_);
	safeLayout->setSpacing(5);
	safeLayout->setContentsMargins(0, 0, 0, 0);

	QLabel *logoLabel = new QLabel();
	QPixmap logoPixmap(":/img/safe");
	logoLabel->setPixmap(logoPixmap);
	logoLabel->setFixedSize(logoPixmap.size());

	QFont safe360Font = safe360Label_->font();
	safe360Font.setPointSize(18);
	safe360Font.setBold(true);
	safe360Label_->setFont(safe360Font);

	safe360Label_->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	safeLabel_->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

	QFont safeFont = safeLabel_->font();
	safeFont.setPointSize(14);
	safeFont.setBold(true);
	safeLabel_->setFont(safeFont);

	buttonLayout->addStretch();
	buttonLayout->addLayout(safeLayout);
	buttonLayout->addWidget(logoLabel);
	buttonLayout->setSpacing(8);
	buttonLayout->setContentsMargins(15, 0, 15, 0);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addLayout(titleLayout);
	mainLayout->addLayout(buttonLayout);
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	initText();
	versionTitle_->setObjectName("whiteLabel");
	safe360Label_->setObjectName("whiteLabel");
	safeLabel_->setObjectName("whiteLabel");

	this->setLayout(mainLayout);
	this->setFixedHeight(110);
}


void TitleWidget::turnPage(const QString &currentPage)
{
	bool isOk;
	int index = currentPage.toInt(&isOk, 10);
	if (!isOk) {
		return;
	}

	for (int i=0; i<btnList_.count(); i++) {
		ToolButton *tb = btnList_.at(i);
		if (index == i) {
			tb->setMousePress(true);
		} else {
			tb->setMousePress(false);
		}
	}
	emit turnPage(index);
}

void TitleWidget::initText()
{
	versionTitle_->setText(tr("title") + QString("9.2"));
	skinBtn_->setToolTip(tr("change  skin"));
	mainMenuBtn_->setToolTip(tr("main menu"));
	minBtn_->setToolTip(tr("minimize"));
	feedbackBtn_->setToolTip(tr("feedback"));
	closeBtn_->setToolTip(tr("close"));

	if (btnList_.size() > 7) {
		btnList_[0]->setText(tr("power"));
		btnList_[1]->setText(tr("mummy"));
		btnList_[2]->setText(tr("repair"));
		btnList_[3]->setText(tr("clear"));
		btnList_[4]->setText(tr("optimize"));
		btnList_[5]->setText(tr("expert"));
		btnList_[6]->setText(tr("hole"));
		btnList_[7]->setText(tr("software"));
	}

	safe360Label_->setText(tr("360"));
	safeLabel_->setText(tr("safe"));
}