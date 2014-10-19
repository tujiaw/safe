#ifndef TITLE_WIDGET_H_
#define TITLE_WIDGET_H_

#include <QWidget>

class QLabel;
class PushButton;
class ToolButton;
class TitleWidget : public QWidget
{
	Q_OBJECT
public:
	explicit TitleWidget(QWidget *parent = 0);

signals:
	void showSkin();
	void showMin();
	void showMainMenu();
	void closeWidget();
	void turnPage(int currentPage);

public slots:
	void slotTurnPage(int index);

private:
	void initText();

private:
	QLabel *versionTitle_;
	PushButton *medalBtn_;
	PushButton *skinBtn_;
	PushButton *feedbackBtn_;
	PushButton *mainMenuBtn_;
	PushButton *minBtn_;
	PushButton *closeBtn_;
	QLabel *safe360Label_;
	QLabel *safeLabel_;
	QList<ToolButton*> btnList_;
};

#endif // TITLE_WIDGET_H_