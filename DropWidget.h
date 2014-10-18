#ifndef DROPWIDGET_H_
#define DROPWIDGET_H_

#include <QDialog>

class DropWidget : public QDialog
{
	Q_OBJECT

public:
	explicit DropWidget(QWidget *parent = 0);
	virtual ~DropWidget(void);

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);

private:
	QPoint movePoint_;
	bool isMousePress_;
};

#endif // DROPWIDGET_H_