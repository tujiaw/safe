#ifndef DROPWIDGET_H_
#define DROPWIDGET_H_

#include <QDialog>

class DropWidget : public QDialog
{
	Q_OBJECT

public:
	explicit DropWidget(QWidget *parent = 0, bool canStretch = false);
	virtual ~DropWidget(void);

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);
	bool nativeEvent(const QByteArray & eventType, void * message, long * result);

private:
	QPoint movePoint_;
	bool isMousePress_;
	bool canStretch_;
};

#endif // DROPWIDGET_H_