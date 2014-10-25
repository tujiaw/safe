#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "DropWidget.h"

class TitleWidget;
class StackedWidget;
class TiJianWidget;
class ChaShaWidget;
class MainMenu;

class MainWindow : public DropWidget
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void slotShowMainMenu();
	void slotShowSkin();
	void slotShowSettingDialog();
	void slotShowAbout();
	void slotTurnPage(int index);

protected:
	void paintEvent(QPaintEvent *event);

private:
	StackedWidget *stackedWidget_;
	TiJianWidget *tijianWidget_;
	ChaShaWidget *chashaWidget_;
	TitleWidget *titleWidget_;
	QString bgName_;
	MainMenu *mainMenu_;
};

#endif // MAINWINDOW_H_