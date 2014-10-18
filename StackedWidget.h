#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QStackedWidget>

class StackedWidget : public QStackedWidget
{
	Q_OBJECT

public:
	explicit StackedWidget(QWidget *parent=0);
	~StackedWidget();

private:
	
};

#endif // STACKEDWIDGET_H
