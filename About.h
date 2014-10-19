#pragma once

#include "DropWidget.h"

class About : public DropWidget
{
	Q_OBJECT
public:
	explicit About(QWidget *parent = 0);

protected:
	void paintEvent(QPaintEvent *event);
};