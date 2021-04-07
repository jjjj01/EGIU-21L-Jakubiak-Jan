/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
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

class Ui_EditDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QTextEdit *recipeName;
    QLabel *label_3;
    QLineEdit *ingredientQuantity;
    QPushButton *addBtn;
    QPushButton *applyBtn;
    QTableView *recipeIngredients;
    QLineEdit *ingredientName;
    QTextEdit *recipeRecipe;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName(QString::fromUtf8("EditDialog"));
        EditDialog->resize(719, 408);
        buttonBox = new QDialogButtonBox(EditDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(620, 180, 81, 161));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(EditDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(76, 140, 81, 181));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        recipeName = new QTextEdit(EditDialog);
        recipeName->setObjectName(QString::fromUtf8("recipeName"));
        recipeName->setGeometry(QRect(160, 10, 370, 51));
        label_3 = new QLabel(EditDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 30, 47, 13));
        ingredientQuantity = new QLineEdit(EditDialog);
        ingredientQuantity->setObjectName(QString::fromUtf8("ingredientQuantity"));
        ingredientQuantity->setGeometry(QRect(349, 380, 181, 20));
        addBtn = new QPushButton(EditDialog);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(550, 380, 75, 23));
        applyBtn = new QPushButton(EditDialog);
        applyBtn->setObjectName(QString::fromUtf8("applyBtn"));
        applyBtn->setGeometry(QRect(640, 380, 75, 23));
        recipeIngredients = new QTableView(EditDialog);
        recipeIngredients->setObjectName(QString::fromUtf8("recipeIngredients"));
        recipeIngredients->setGeometry(QRect(160, 225, 370, 149));
        recipeIngredients->setSelectionMode(QAbstractItemView::SingleSelection);
        recipeIngredients->setSelectionBehavior(QAbstractItemView::SelectRows);
        ingredientName = new QLineEdit(EditDialog);
        ingredientName->setObjectName(QString::fromUtf8("ingredientName"));
        ingredientName->setGeometry(QRect(160, 380, 181, 20));
        recipeRecipe = new QTextEdit(EditDialog);
        recipeRecipe->setObjectName(QString::fromUtf8("recipeRecipe"));
        recipeRecipe->setEnabled(true);
        recipeRecipe->setGeometry(QRect(160, 71, 370, 148));

        retranslateUi(EditDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QCoreApplication::translate("EditDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EditDialog", "Recipe", nullptr));
        label_2->setText(QCoreApplication::translate("EditDialog", "Ingredients", nullptr));
        label_3->setText(QCoreApplication::translate("EditDialog", "Name", nullptr));
        addBtn->setText(QCoreApplication::translate("EditDialog", "Add", nullptr));
        applyBtn->setText(QCoreApplication::translate("EditDialog", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
