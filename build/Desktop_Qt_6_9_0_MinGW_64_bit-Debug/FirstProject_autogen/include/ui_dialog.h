/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *lineEdit_6;
    QFrame *line;
    QPushButton *btn_save;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QComboBox *cbox_space;
    QComboBox *cbox_units;
    QComboBox *cbox_model;
    QPlainTextEdit *txtbox_para1;
    QPlainTextEdit *txtbox_para2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(636, 638);
        lineEdit_6 = new QLineEdit(Dialog);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(360, 20, 271, 91));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy);
        lineEdit_6->setTabletTracking(false);
        lineEdit_6->setFrame(true);
        lineEdit_6->setDragEnabled(false);
        lineEdit_6->setReadOnly(true);
        line = new QFrame(Dialog);
        line->setObjectName("line");
        line->setGeometry(QRect(340, 10, 16, 481));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        btn_save = new QPushButton(Dialog);
        btn_save->setObjectName("btn_save");
        btn_save->setGeometry(QRect(250, 510, 141, 41));
        graphicsView = new QGraphicsView(Dialog);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(370, 130, 256, 192));
        widget = new QWidget(Dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 20, 321, 151));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(80, 0));
        lineEdit->setMaximumSize(QSize(75, 16777215));

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(80, 0));
        lineEdit_2->setMaximumSize(QSize(75, 16777215));

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setMinimumSize(QSize(80, 0));
        lineEdit_3->setMaximumSize(QSize(75, 16777215));

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setMinimumSize(QSize(80, 0));
        lineEdit_4->setMaximumSize(QSize(75, 16777215));

        verticalLayout->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setMinimumSize(QSize(80, 0));
        lineEdit_5->setMaximumSize(QSize(75, 16777215));

        verticalLayout->addWidget(lineEdit_5);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        cbox_space = new QComboBox(widget);
        cbox_space->setObjectName("cbox_space");

        verticalLayout_2->addWidget(cbox_space);

        cbox_units = new QComboBox(widget);
        cbox_units->setObjectName("cbox_units");

        verticalLayout_2->addWidget(cbox_units);

        cbox_model = new QComboBox(widget);
        cbox_model->setObjectName("cbox_model");

        verticalLayout_2->addWidget(cbox_model);

        txtbox_para1 = new QPlainTextEdit(widget);
        txtbox_para1->setObjectName("txtbox_para1");
        txtbox_para1->setMaximumSize(QSize(16777215, 24));

        verticalLayout_2->addWidget(txtbox_para1);

        txtbox_para2 = new QPlainTextEdit(widget);
        txtbox_para2->setObjectName("txtbox_para2");
        txtbox_para2->setMaximumSize(QSize(16777215, 24));

        verticalLayout_2->addWidget(txtbox_para2);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("Dialog", "Visual representation changes based on Model", nullptr));
        btn_save->setText(QCoreApplication::translate("Dialog", "Save", nullptr));
        lineEdit->setText(QCoreApplication::translate("Dialog", "Space", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Dialog", "Units", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Dialog", "Model", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("Dialog", "Parameter 1 ", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("Dialog", "Parameter 2", nullptr));
        txtbox_para1->setPlainText(QCoreApplication::translate("Dialog", "Radius", nullptr));
        txtbox_para2->setPlainText(QCoreApplication::translate("Dialog", "Width or Height", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
