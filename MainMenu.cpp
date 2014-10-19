#include "MainMenu.h"
#include <QUrl>
#include <QDesktopServices>

MainMenu::MainMenu(QWidget *parent)
	: QMenu(parent)
{
	QAction *settingAction = new QAction(tr("setting"), this);
	QAction *newCharacterAction = new QAction(tr("new character"), this);
	QAction *checkUpdateAction = new QAction(tr("check update"), this);
	QAction *toEnterpriseAction = new QAction(tr("to enterprise"), this);
	QAction *onlineHelpAction = new QAction(tr("online help"), this);
	QAction *forumHelpAction = new QAction(tr("forum help"), this);
	QAction *website360Action = new QAction(tr("360 website"), this);
	QAction *privacyProtectionAction = new QAction(tr("privacy protection"), this);
	QAction *aboutUsAction = new QAction(tr("about us"), this);

	this->addAction(settingAction);
	this->addAction(newCharacterAction);
	this->addAction(checkUpdateAction);
	this->addAction(toEnterpriseAction);
	this->addSeparator();
	this->addAction(onlineHelpAction);
	this->addAction(forumHelpAction);
	this->addAction(website360Action);
	this->addAction(privacyProtectionAction);
	this->addAction(aboutUsAction);

	connect(settingAction, SIGNAL(triggered()), this, SIGNAL(sigSetting()));
	connect(newCharacterAction, SIGNAL(triggered()), this, SIGNAL(sigNewCharacter()));
	connect(checkUpdateAction, SIGNAL(triggered()), this, SIGNAL(sigCheckUpdate()));
	connect(toEnterpriseAction, SIGNAL(triggered()), this, SIGNAL(sigToEnterprise()));
	connect(onlineHelpAction, SIGNAL(triggered()), this, SLOT(slotOnlineHelp()));
	connect(forumHelpAction, SIGNAL(triggered()), this, SLOT(slotForumHelp()));
	connect(website360Action, SIGNAL(triggered()), this, SLOT(slot360Website()));
	connect(privacyProtectionAction, SIGNAL(triggered()), this, SLOT(slotPrivacyProtection()));
	connect(aboutUsAction, SIGNAL(triggered()), this, SIGNAL(sigAboutUs()));

	this->setObjectName("menu");
}

void MainMenu::slotOnlineHelp()
{
	QDesktopServices::openUrl(QUrl("http://bbs.360.cn/cms/guide.html"));
}

void MainMenu::slotForumHelp()
{
	QDesktopServices::openUrl(QUrl("http://bbs.360safe.com/forum.php?mod=forumdisplay&fid=100"));
}

void MainMenu::slot360Website()
{
	QDesktopServices::openUrl(QUrl("http://www.360.cn/"));
}

void MainMenu::slotPrivacyProtection()
{
	QDesktopServices::openUrl(QUrl("http://www.360.cn/privacy/v2/index.html"));
}
