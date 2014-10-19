#include "ChaShaWidget.h"
#include <QLabel>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

QToolButton *createScanButton(const QString &text, const QString &iconPath)
{
	QSize iconSize(123, 115);
	QToolButton *btn = new QToolButton();
	btn->setText(text);
	btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	QPixmap pixmap(iconPath);
	btn->setIcon(pixmap);
	btn->setIconSize(iconSize);
	btn->setFixedSize(iconSize.width() + 25, iconSize.height() + 25);
	QFont font = btn->font();
	font.setBold(true);
	font.setPointSize(12);
	btn->setFont(font);
	btn->setObjectName("grayToolButton");
	return btn;
}

ChaShaWidget::ChaShaWidget(QWidget *parent)
	: QWidget(parent)
{
	QLabel *tipLabel = new QLabel();
	QPixmap tipPixmap(":/killMummyWidget/tip");
	tipLabel->setPixmap(tipPixmap);
	tipLabel->setScaledContents(true);
	tipLabel->setFixedSize(tipPixmap.size());

	QLabel *tipResultLabel = new QLabel();
	tipResultLabel->setText(tr("the last scanning") + QString::number(3) + tr("no threat found"));
	QFont tipResultFont = tipResultLabel->font();
	tipResultFont.setPointSize(12);
	tipResultFont.setBold(true);
	tipResultLabel->setFont(tipResultFont);
	tipResultLabel->setObjectName("grayLabel");

	QLabel *tipScanLabel = new QLabel();
	tipScanLabel->setText(tr("regular scanning"));
	tipScanLabel->setObjectName("grayLabel");

	QToolButton *fastScanButton = createScanButton(tr("fast scan"), ":/killMummyWidget/fast_scan");
	QToolButton *fullScanButton = createScanButton(tr("full scan"), ":/killMummyWidget/full_scan");
	QToolButton *customScanButton = createScanButton(tr("custom scan"), ":/killMummyWidget/custom_scan");

	QVBoxLayout *vLayout = new QVBoxLayout();
	vLayout->addWidget(tipResultLabel);
	vLayout->addWidget(tipScanLabel);
	vLayout->setSpacing(5);
	vLayout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout *hLayout = new QHBoxLayout();
	hLayout->addWidget(tipLabel);
	hLayout->addLayout(vLayout);
	hLayout->setSpacing(10);
	hLayout->setContentsMargins(20, 20, 0, 20);
	QWidget *topWidget = new QWidget();
	QPalette topPalette;
	topPalette.setBrush(QPalette::Window, QColor(245, 245, 245));
	topWidget->setPalette(topPalette);
	topWidget->setAutoFillBackground(true);
	topWidget->setLayout(hLayout);

	QHBoxLayout *scanBtnLayout = new QHBoxLayout();
	scanBtnLayout->addWidget(fastScanButton);
	scanBtnLayout->addWidget(fullScanButton);
	scanBtnLayout->addWidget(customScanButton);
	scanBtnLayout->setSpacing(0);
	scanBtnLayout->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addWidget(topWidget);
	mainLayout->addStretch();
	mainLayout->addLayout(scanBtnLayout);
	mainLayout->addStretch();
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	this->setLayout(mainLayout);
}