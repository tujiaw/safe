#include <QApplication>
#include <QTextCodec>
#include <QTranslator>
#include <QFile>
#include <QMessageBox>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec *codec = QTextCodec::codecForName("System");
	QTextCodec::setCodecForLocale(codec);

	bool first = false;
	QTranslator translator;
	if (translator.load(QString(":/qm/qt_zh_CN"))) {
		if (a.installTranslator(&translator)) {
			first = true;
		}
	}

	bool second = false;
	QTranslator chTranslator;
	if (chTranslator.load(":/qm/safe_ch")) {
		if (a.installTranslator(&chTranslator)) {
			second = true;
		}
	}

	bool third = false;
	QFile qss(":/qss/safe_style");
	if (qss.open(QFile::ReadOnly)) {
		qApp->setStyleSheet(qss.readAll());
		qss.close();
		third = true;
	}

	if (first && second && third) {
		MainWindow mainWindow;
		mainWindow.show();
		return a.exec();
	} else {
		QMessageBox::information(NULL, "error", "init failed");
	}

	return 0;
}
