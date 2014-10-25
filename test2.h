#ifndef TEST2_H
#define TEST2_H

#include <QWidget>
#include "ui_test2.h"

class test2 : public QWidget
{
	Q_OBJECT

public:
	test2(QWidget *parent = 0);
	~test2();

private:
	Ui::test2 ui;
};

#endif // TEST2_H
