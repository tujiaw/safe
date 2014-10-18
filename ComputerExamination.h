#ifndef COMPUTEREXAMINATION_H_
#define COMPUTEREXAMINATION_H_

#include <QtWidgets/QWidget>

class QSplitter;
class QLabel;
class QPushButton;
class ComputerExamination : public QWidget
{
	Q_OBJECT
public:
	explicit ComputerExamination(QWidget *parent = 0);

private:
	void initLeft();

private:
	QSplitter *mainSplitter_;

	QWidget *leftWidget_;
	QLabel *computerLabel_;
	QLabel *suggestLabel_;
	QPushButton *immediateMedicalBtn_;
};

#endif // COMPUTEREXAMINATION_H_