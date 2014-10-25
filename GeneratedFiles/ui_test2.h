/********************************************************************************
** Form generated from reading UI file 'test2.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST2_H
#define UI_TEST2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test2
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QListView *listView;

    void setupUi(QWidget *test2)
    {
        if (test2->objectName().isEmpty())
            test2->setObjectName(QStringLiteral("test2"));
        test2->resize(400, 300);
        gridLayout = new QGridLayout(test2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter_2 = new QSplitter(test2);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        splitter->addWidget(pushButton);
        radioButton = new QRadioButton(splitter);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        splitter->addWidget(radioButton);
        splitter_2->addWidget(splitter);
        listView = new QListView(splitter_2);
        listView->setObjectName(QStringLiteral("listView"));
        splitter_2->addWidget(listView);

        gridLayout->addWidget(splitter_2, 0, 0, 1, 1);


        retranslateUi(test2);

        QMetaObject::connectSlotsByName(test2);
    } // setupUi

    void retranslateUi(QWidget *test2)
    {
        test2->setWindowTitle(QApplication::translate("test2", "test2", 0));
        pushButton->setText(QApplication::translate("test2", "PushButton", 0));
        radioButton->setText(QApplication::translate("test2", "RadioButton", 0));
    } // retranslateUi

};

namespace Ui {
    class test2: public Ui_test2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST2_H
