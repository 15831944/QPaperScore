/********************************************************************************
** Form generated from reading UI file 'QPaperScore.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPAPERSCORE_H
#define UI_QPAPERSCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPaperScoreClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_AddPaper;
    QPushButton *pushButton_DelPaper;
    QPushButton *pushButton_Goal;
    QPushButton *pushButton_ClearPaper;
    QPushButton *pushButton_Export;
    QTableWidget *tableWidget_Paper;
    QPushButton *pushButton_reset;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_DelTemplate;
    QPushButton *pushButton_AddTemplate;
    QTableWidget *tableWidget_Template;
    QPushButton *pushButton_ClearTemplate;
    QLabel *label;
    QComboBox *comboBox_Algorithm;
    QGroupBox *groupBox_ReulstPreview;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget_Result;

    void setupUi(QMainWindow *QPaperScoreClass)
    {
        if (QPaperScoreClass->objectName().isEmpty())
            QPaperScoreClass->setObjectName(QStringLiteral("QPaperScoreClass"));
        QPaperScoreClass->resize(781, 614);
        centralWidget = new QWidget(QPaperScoreClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_AddPaper = new QPushButton(groupBox_2);
        pushButton_AddPaper->setObjectName(QStringLiteral("pushButton_AddPaper"));

        gridLayout_3->addWidget(pushButton_AddPaper, 1, 0, 1, 1);

        pushButton_DelPaper = new QPushButton(groupBox_2);
        pushButton_DelPaper->setObjectName(QStringLiteral("pushButton_DelPaper"));

        gridLayout_3->addWidget(pushButton_DelPaper, 1, 1, 1, 1);

        pushButton_Goal = new QPushButton(groupBox_2);
        pushButton_Goal->setObjectName(QStringLiteral("pushButton_Goal"));

        gridLayout_3->addWidget(pushButton_Goal, 1, 3, 1, 1);

        pushButton_ClearPaper = new QPushButton(groupBox_2);
        pushButton_ClearPaper->setObjectName(QStringLiteral("pushButton_ClearPaper"));

        gridLayout_3->addWidget(pushButton_ClearPaper, 1, 2, 1, 1);

        pushButton_Export = new QPushButton(groupBox_2);
        pushButton_Export->setObjectName(QStringLiteral("pushButton_Export"));

        gridLayout_3->addWidget(pushButton_Export, 1, 5, 1, 1);

        tableWidget_Paper = new QTableWidget(groupBox_2);
        tableWidget_Paper->setObjectName(QStringLiteral("tableWidget_Paper"));

        gridLayout_3->addWidget(tableWidget_Paper, 0, 0, 1, 6);

        pushButton_reset = new QPushButton(groupBox_2);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));

        gridLayout_3->addWidget(pushButton_reset, 1, 4, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 1, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_DelTemplate = new QPushButton(groupBox);
        pushButton_DelTemplate->setObjectName(QStringLiteral("pushButton_DelTemplate"));

        gridLayout->addWidget(pushButton_DelTemplate, 2, 1, 1, 1);

        pushButton_AddTemplate = new QPushButton(groupBox);
        pushButton_AddTemplate->setObjectName(QStringLiteral("pushButton_AddTemplate"));

        gridLayout->addWidget(pushButton_AddTemplate, 2, 0, 1, 1);

        tableWidget_Template = new QTableWidget(groupBox);
        tableWidget_Template->setObjectName(QStringLiteral("tableWidget_Template"));

        gridLayout->addWidget(tableWidget_Template, 1, 0, 1, 3);

        pushButton_ClearTemplate = new QPushButton(groupBox);
        pushButton_ClearTemplate->setObjectName(QStringLiteral("pushButton_ClearTemplate"));

        gridLayout->addWidget(pushButton_ClearTemplate, 2, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_Algorithm = new QComboBox(groupBox);
        comboBox_Algorithm->setObjectName(QStringLiteral("comboBox_Algorithm"));

        gridLayout->addWidget(comboBox_Algorithm, 0, 1, 1, 2);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_ReulstPreview = new QGroupBox(centralWidget);
        groupBox_ReulstPreview->setObjectName(QStringLiteral("groupBox_ReulstPreview"));
        gridLayout_4 = new QGridLayout(groupBox_ReulstPreview);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tabWidget_Result = new QTabWidget(groupBox_ReulstPreview);
        tabWidget_Result->setObjectName(QStringLiteral("tabWidget_Result"));
        tabWidget_Result->setMinimumSize(QSize(0, 300));

        gridLayout_4->addWidget(tabWidget_Result, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_ReulstPreview, 2, 0, 1, 2);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 2);
        QPaperScoreClass->setCentralWidget(centralWidget);

        retranslateUi(QPaperScoreClass);

        tabWidget_Result->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(QPaperScoreClass);
    } // setupUi

    void retranslateUi(QMainWindow *QPaperScoreClass)
    {
        QPaperScoreClass->setWindowTitle(QApplication::translate("QPaperScoreClass", "QPaperScore", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("QPaperScoreClass", "\345\233\276\347\272\270\345\210\227\350\241\250", Q_NULLPTR));
        pushButton_AddPaper->setText(QApplication::translate("QPaperScoreClass", "\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_DelPaper->setText(QApplication::translate("QPaperScoreClass", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_Goal->setText(QApplication::translate("QPaperScoreClass", "\346\211\223\345\210\206", Q_NULLPTR));
        pushButton_ClearPaper->setText(QApplication::translate("QPaperScoreClass", "\346\270\205\347\251\272", Q_NULLPTR));
        pushButton_Export->setText(QApplication::translate("QPaperScoreClass", "\345\257\274\345\207\272CSV", Q_NULLPTR));
        pushButton_reset->setText(QApplication::translate("QPaperScoreClass", "\351\207\215\346\226\260\350\256\276\347\275\256", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QPaperScoreClass", "\346\250\241\346\235\277", Q_NULLPTR));
        pushButton_DelTemplate->setText(QApplication::translate("QPaperScoreClass", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_AddTemplate->setText(QApplication::translate("QPaperScoreClass", "\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_ClearTemplate->setText(QApplication::translate("QPaperScoreClass", "\346\270\205\347\251\272", Q_NULLPTR));
        label->setText(QApplication::translate("QPaperScoreClass", "\347\256\227\346\263\225\357\274\232", Q_NULLPTR));
        groupBox_ReulstPreview->setTitle(QApplication::translate("QPaperScoreClass", "\351\242\204\350\247\210\357\274\210\345\217\214\345\207\273\345\217\257\346\224\276\345\244\247\357\274\211", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QPaperScoreClass: public Ui_QPaperScoreClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPAPERSCORE_H
