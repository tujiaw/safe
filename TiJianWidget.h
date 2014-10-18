#pragma once

#include <QWidget>

class QSplitter;
class TiJianWidget : public QWidget
{
	Q_OBJECT
public:
	explicit TiJianWidget(QWidget *parent = 0);

private:
	void initLeft();
	void initRightTop();
	void initRightCenterFirst();
	void initRightCenterSecond();
	void initRightBottom();

private:
	QSplitter *mainSplitter_;
	QWidget *leftWidget_;
	QSplitter *rightSplitter_;

	QWidget *rightTopWidget_;
	QWidget *rightCenterFirstWidget_;
	QWidget *rightCenterSecondWidget_;
	QWidget *rightBottomWidget_;
};

