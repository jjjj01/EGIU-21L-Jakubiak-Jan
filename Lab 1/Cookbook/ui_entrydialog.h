/********************************************************************************
** Form generated from reading UI file 'entrydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTRYDIALOG_H
#define UI_ENTRYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntryDialog
{
public:
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *recipeName;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *ingredientName;
    QLineEdit *ingredientQuantity;
    QPushButton *addBtn;
    QPushButton *applyBtn;
    QTableView *recipeIngredients;
    QTextEdit *recipeRecipe;

    void setupUi(QDialog *EntryDialog)
    {
        if (EntryDialog->objectName().isEmpty())
            EntryDialog->setObjectName(QString::fromUtf8("EntryDialog"));
        EntryDialog->resize(719, 410);
        layoutWidget1 = new QWidget(EntryDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 140, 71, 181));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(EntryDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 30, 47, 13));
        recipeName = new QTextEdit(EntryDialog);
        recipeName->setObjectName(QString::fromUtf8("recipeName"));
        recipeName->setGeometry(QRect(160, 10, 370, 51));
        layoutWidget = new QWidget(EntryDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(600, 190, 77, 100));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnOK = new QPushButton(layoutWidget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        verticalLayout_2->addWidget(btnOK);

        btnCancel = new QPushButton(layoutWidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        verticalLayout_2->addWidget(btnCancel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        ingredientName = new QLineEdit(EntryDialog);
        ingredientName->setObjectName(QString::fromUtf8("ingredientName"));
        ingredientName->setGeometry(QRect(160, 380, 181, 20));
        ingredientQuantity = new QLineEdit(EntryDialog);
        ingredientQuantity->setObjectName(QString::fromUtf8("ingredientQuantity"));
        ingredientQuantity->setGeometry(QRect(349, 380, 181, 20));
        addBtn = new QPushButton(EntryDialog);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(550, 380, 75, 23));
        applyBtn = new QPushButton(EntryDialog);
        applyBtn->setObjectName(QString::fromUtf8("applyBtn"));
        applyBtn->setGeometry(QRect(640, 380, 75, 23));
        recipeIngredients = new QTableView(EntryDialog);
        recipeIngredients->setObjectName(QString::fromUtf8("recipeIngredients"));
        recipeIngredients->setGeometry(QRect(160, 220, 370, 151));
        recipeIngredients->setSelectionMode(QAbstractItemView::SingleSelection);
        recipeIngredients->setSelectionBehavior(QAbstractItemView::SelectRows);
        recipeRecipe = new QTextEdit(EntryDialog);
        recipeRecipe->setObjectName(QString::fromUtf8("recipeRecipe"));
        recipeRecipe->setGeometry(QRect(160, 70, 370, 148));

        retranslateUi(EntryDialog);

        QMetaObject::connectSlotsByName(EntryDialog);
    } // setupUi

    void retranslateUi(QDialog *EntryDialog)
    {
        EntryDialog->setWindowTitle(QCoreApplication::translate("EntryDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EntryDialog", "Recipe", nullptr));
        label_2->setText(QCoreApplication::translate("EntryDialog", "Ingredients", nullptr));
        label_3->setText(QCoreApplication::translate("EntryDialog", "Name", nullptr));
        btnOK->setText(QCoreApplication::translate("EntryDialog", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("EntryDialog", "Cancel", nullptr));
        addBtn->setText(QCoreApplication::translate("EntryDialog", "Add", nullptr));
        applyBtn->setText(QCoreApplication::translate("EntryDialog", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EntryDialog: public Ui_EntryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRYDIALOG_H
