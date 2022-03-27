/********************************************************************************
** Form generated from reading UI file 'inputline.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTLINE_H
#define UI_INPUTLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputLine
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *comboBox;

    void setupUi(QWidget *InputLine)
    {
        if (InputLine->objectName().isEmpty())
            InputLine->setObjectName(QString::fromUtf8("InputLine"));
        InputLine->resize(326, 21);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InputLine->sizePolicy().hasHeightForWidth());
        InputLine->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(InputLine);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(InputLine);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(9);
        label->setFont(font);
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(InputLine);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMinimumSize(QSize(101, 0));
        lineEdit->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(lineEdit);

        comboBox = new QComboBox(InputLine);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy3);
        comboBox->setMinimumSize(QSize(50, 0));

        horizontalLayout->addWidget(comboBox);


        retranslateUi(InputLine);

        QMetaObject::connectSlotsByName(InputLine);
    } // setupUi

    void retranslateUi(QWidget *InputLine)
    {
        InputLine->setWindowTitle(QCoreApplication::translate("InputLine", "Form", nullptr));
        label->setText(QCoreApplication::translate("InputLine", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputLine: public Ui_InputLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTLINE_H
