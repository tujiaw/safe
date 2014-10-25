#pragma once

#include <QFrame>

class CustomFrame : public QFrame
{
	Q_OBJECT
public:
	explicit CustomFrame(QWidget *contentWidget, const QString &title);

public slots:
	void slotShowSmall();
	void slotShowMaxRestore();

protected:
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
	bool nativeEvent(const QByteArray & eventType, void * message, long * result);
	void paintEvent(QPaintEvent *);

private:
	bool isMax_;
	bool isPress_;
	QPoint startPos_;
	QPoint clickPos_;
	QWidget *contentWidget_;
};