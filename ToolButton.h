#ifndef TOOLBUTTON_H_
#define TOOLBUTTON_H_

#include <QToolButton>

class ToolButton : public QToolButton
{
	Q_OBJECT
public:
	explicit ToolButton(const QString &pic, QWidget *parent=0);
	void setMousePress(bool val);

protected:
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
	void mousePressEvent(QMouseEvent *);
	void paintEvent(QPaintEvent *);

private:
	bool isMouseHover_;
	bool isMousePress_;
};

#endif // TOOLBUTTON_H_