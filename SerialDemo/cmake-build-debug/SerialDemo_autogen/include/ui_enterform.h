/********************************************************************************
** Form generated from reading UI file 'enterform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERFORM_H
#define UI_ENTERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EnterForm
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *frame;
    QPushButton *btn_Serial;

    void setupUi(QDialog *EnterForm)
    {
        if (EnterForm->objectName().isEmpty())
            EnterForm->setObjectName(QString::fromUtf8("EnterForm"));
        EnterForm->resize(442, 420);
        buttonBox = new QDialogButtonBox(EnterForm);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(80, 380, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        frame = new QFrame(EnterForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 20, 401, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btn_Serial = new QPushButton(frame);
        btn_Serial->setObjectName(QString::fromUtf8("btn_Serial"));
        btn_Serial->setGeometry(QRect(40, 60, 75, 61));

        retranslateUi(EnterForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), EnterForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EnterForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(EnterForm);
    } // setupUi

    void retranslateUi(QDialog *EnterForm)
    {
        EnterForm->setWindowTitle(QCoreApplication::translate("EnterForm", "Dialog", nullptr));
        btn_Serial->setText(QCoreApplication::translate("EnterForm", "\344\270\262\345\217\243\346\265\213\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterForm: public Ui_EnterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERFORM_H
