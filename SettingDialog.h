#pragma once

#include "DropWidget.h"

class QTabWidget;
class QHBoxLayout;
class QTabWidget;
class SettingDialog : public DropWidget
{
	Q_OBJECT
public:
	explicit SettingDialog(QWidget *parent = 0);

protected:
	void paintEvent(QPaintEvent *event);

private:
	QHBoxLayout *createTitleLayout();
	QTabWidget *createContentWidget();
	QHBoxLayout *createBottomLayout();
};
