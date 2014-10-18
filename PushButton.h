#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

#include <QPushButton>

class PushButton : public QPushButton
{
	Q_OBJECT
public:
	explicit PushButton(QWidget *parent = 0);
	void setPicName(const QStringList &pics); // NORMAL, ENTER, PRESS, RELEASE

protected:
	void enterEvent(QEvent *event);
	void leaveEvent(QEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);

private:
	enum Status { NORMAL, ENTER, PRESS, RELEASE };
	Status status_;
	QStringList pics_;
	bool isMousePressed_;
};

#endif // PUSHBUTTON_H_