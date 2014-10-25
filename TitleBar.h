#pragma once

#include <QtWidgets>
#include <QDebug>
#include "Common.h"
#include "PushButton.h"

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    TitleBar(QWidget *parent)
    {
        //setAutoFillBackground(true);
        //setBackgroundRole(QPalette::Highlight);

        minimize = new PushButton(this);
        maximize = new PushButton(this);
        close= new PushButton(this);
		
		maximize->setPicName(QStringList() << ":/sysButton/skin" << ":/sysButton/skin_hover" << ":/sysButton/skin_pressed");
		minimize->setPicName(QStringList() << ":/sysButton/min" << ":/sysButton/min_hover" << ":/sysButton/min_pressed");
		close->setPicName(QStringList() << ":/sysButton/close" << ":/sysButton/close_hover" << ":/sysButton/close_pressed");

		QLabel *logo = new QLabel(this);
		QPixmap logoPixmap(":/img/safe");
		logo->setPixmap(logoPixmap);
		logo->setFixedSize(16, 16);
		logo->setScaledContents(true);

        QLabel *label = new QLabel(this);
		QFont labelFont = label->font();
		labelFont.setBold(true);
		label->setFont(labelFont);
        label->setText("Window Title");
		label->setObjectName("whiteLabel");
		label->setText(QStringLiteral("ÎÒÃÇµÄ¸è"));

        QHBoxLayout *hbox = new QHBoxLayout(this);

		hbox->addWidget(logo);
		hbox->addWidget(label);
		label->setContentsMargins(5, 0, 0, 0);
		hbox->addStretch();
		hbox->addWidget(minimize, 0, Qt::AlignTop);
		hbox->addWidget(maximize, 0, Qt::AlignTop);
		hbox->addWidget(close, Qt::AlignTop);
        hbox->setSpacing(0);
		hbox->setContentsMargins(5, 0, 0, 0);
		
		this->setLayout(hbox);

        maxNormal = false;
        titleBarPress = false;

		connect(close, SIGNAL( clicked() ), parent, SLOT(close() ) );
        connect(minimize, SIGNAL( clicked() ), this, SLOT(showSmall() ) );
        connect(maximize, SIGNAL( clicked() ), this, SLOT(showMaxRestore() ) );
    }

public slots:
    void showSmall()
    {
        parentWidget()->showMinimized();
    }

    void showMaxRestore()
    {
        if (maxNormal) {
            parentWidget()->showNormal();
            maxNormal = !maxNormal;
            maximize->setIcon(maxPix);
        } else {
            parentWidget()->showMaximized();
            maxNormal = !maxNormal;
            maximize->setIcon(restorePix);
        }
    }
protected:
    void mousePressEvent(QMouseEvent *me)
    {
        startPos = me->globalPos();
        clickPos = mapToParent(me->pos());
        titleBarPress = true;
    }
    void mouseMoveEvent(QMouseEvent *me)
    {
        if (maxNormal || !titleBarPress)
            return;
        parentWidget()->move(me->globalPos() - clickPos);
    }

    void mouseReleaseEvent(QMouseEvent *)
	{
		titleBarPress = false;
	}

	void mouseDoubleClickEvent(QMouseEvent *e)
	{
		if (e->button() == Qt::LeftButton) {
			showMaxRestore();
		}
	}

private:
    PushButton *minimize;
    PushButton *maximize;
    PushButton *close;
    QPixmap restorePix, maxPix;
    bool maxNormal;
    bool titleBarPress;
    QPoint startPos;
    QPoint clickPos;
};

class Frame : public QFrame
{
public:

    Frame(QWidget *content)
    {
        m_mouse_down = false;
        setWindowFlags(Qt::FramelessWindowHint);
        setMouseTracking(true);

        m_titleBar = new TitleBar(this);

		m_content = content;

        QVBoxLayout *layout = new QVBoxLayout(this);
		layout->addWidget(m_titleBar);
        layout->addWidget(m_content);
        layout->setMargin(5);
        layout->setSpacing(0);
		this->setLayout(layout);
    }

    QWidget *contentWidget() const { return m_content; }
    TitleBar *titleBar() const { return m_titleBar; }

    void mousePressEvent(QMouseEvent *e)
    {
        m_old_pos = e->pos();
        m_mouse_down = e->button() == Qt::LeftButton;
    }


	bool nativeEvent(const QByteArray & eventType, void * message, long * result)
	{
	Q_UNUSED(eventType);
    const int HIT_BORDER = 20;
    const MSG *msg=static_cast<MSG*>(message);
    if(msg->message == WM_NCHITTEST) {
        int xPos = ((int)(short)LOWORD(msg->lParam)) - this->frameGeometry().x();
        int yPos = ((int)(short)HIWORD(msg->lParam)) - this->frameGeometry().y();
        if(this->childAt(xPos,yPos) == 0) {
            *result = HTCAPTION;
        } else {
            return false;
        }
        if(xPos > 0 && xPos < HIT_BORDER) {
            *result = HTLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0)) {
            *result = HTRIGHT;
        }
        if(yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOP;
        }
        if(yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOM;
        }
        if(xPos > 0 && xPos < HIT_BORDER && yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOPLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0) && yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOPRIGHT;
        }
        if(xPos > 0 && xPos < HIT_BORDER && yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOMLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0) && yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOMRIGHT;
        }
        return true;
    }
    return false;
}

    void mouseReleaseEvent(QMouseEvent *e)
    {
        m_mouse_down = false;
    }

	void paintEvent(QPaintEvent *event)
{
	QFrame::paintEvent(event);
	int titleHeight = 35;
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);

	const int border = 0;
	painter.drawPixmap(QRect(border, border, this->width()-2*border, this->height()-2*border), QPixmap(DEFAULT_SKIN));
	painter.drawRect(QRect(border, titleHeight, this->width()-2*border, this->height()-titleHeight-border));
}

private:
    TitleBar *m_titleBar;
    QWidget *m_content;
    QPoint m_old_pos;
    bool m_mouse_down;
    bool left, right, bottom;
};

