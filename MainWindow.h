#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "DropWidget.h"

class TitleWidget;
class StackedWidget;
class TiJianWidget;
class ChaShaWidget;

class MainWindow : public DropWidget
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void paintEvent(QPaintEvent *event);

private:
	StackedWidget *stackedWidget_;
	TiJianWidget *tijianWidget_;
	ChaShaWidget *chashaWidget_;
	TitleWidget *titleWidget_;
	QString bgName_;
};

#endif // MAINWINDOW_H_