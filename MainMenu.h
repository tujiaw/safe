#pragma once

#include <QMenu>

class MainMenu : public QMenu
{
	Q_OBJECT
public:
	explicit MainMenu(QWidget *parent = 0);

signals:
	void sigSetting();
	void sigNewCharacter();
	void sigCheckUpdate();
	void sigToEnterprise();
	void sigAboutUs();

private slots:
	void slotOnlineHelp();
	void slotForumHelp();
	void slot360Website();
	void slotPrivacyProtection();
};