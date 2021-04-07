#include "entrydialog.h"
#include "ui_entrydialog.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QJsonArray>
#include <QVariant>

EntryDialog::EntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryDialog)
{
    ui->setupUi(this);
}

EntryDialog::~EntryDialog()
{
    delete ui;
}

void EntryDialog::on_btnCancel_clicked()
{
    close();
}

void EntryDialog::on_btnOK_clicked()
{
    recipeName = ui->recipeName->toPlainText();
    QStringList recipeLines;
    recipeLines = ui->recipeRecipe->toPlainText().split('\n');
    QJsonArray recipeArray;
    for(int i=0;i<recipeLines.length();i++)
    {
        recipeArray.push_back(recipeLines.at(i));
    }
    JsonObjectsNamesList.push_back(recipeName);
    recipeRecipe.insert("recipe", recipeArray);
    for(int i=0;i<model->rowCount();i++)
    {
        recipeRecipe.insert(model->index(i, 0).data().toString(),model->index(i, 1).data().toString());
    }
    JsonObjectsList.push_back(recipeRecipe);
    save_file();
    emit save_changes();
    this->close();
}

void EntryDialog::save_file()
{
    QString path = QCoreApplication::applicationDirPath();
    path.append("/recipes.json");

    QFile file(path);

    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }

    QJsonObject recipeObject;
    for(int i=0;i<JsonObjectsList.length();i++)
    {
        recipeObject.insert(JsonObjectsNamesList.at(i), JsonObjectsList.at(i));
    }

    QJsonDocument recipeDocument(recipeObject);

    file.write(recipeDocument.toJson());
    file.close();
}

void EntryDialog::start()
{
    model = new QStandardItemModel(0, 2, this);
    model->setHeaderData(0, Qt::Horizontal, "Ingredient name");
    model->setHeaderData(1, Qt::Horizontal, "Quantity");
    ui->recipeIngredients ->setModel(model);
}

void EntryDialog::on_recipeIngredients_clicked(const QModelIndex &index)
{
    ui->ingredientName->setText(model->index(index.row(), 0).data().toString());
    ui->ingredientQuantity->setText(model->index(index.row(), 1).data().toString());
}

void EntryDialog::on_addBtn_clicked()
{
    if(!ui->ingredientName->text().isEmpty()&&!ui->ingredientQuantity->text().isEmpty())
    {
        model->setRowCount(model->rowCount()+1);
        QModelIndex index=model->index(0,0,QModelIndex());
        ui->recipeIngredients->selectRow(model->rowCount()-1);
        index=ui->recipeIngredients->selectionModel()->selection().indexes().first();
        model->setData(index, ui->ingredientName->text());
        index=ui->recipeIngredients->selectionModel()->selection().indexes().last();
        model->setData(index, ui->ingredientQuantity->text());
    }
}

void EntryDialog::on_applyBtn_clicked()
{
    if(!ui->ingredientName->text().isEmpty()&&!ui->ingredientQuantity->text().isEmpty()&&!ui->recipeIngredients->selectionModel()->selection().indexes().isEmpty())
    {
        QModelIndex index=model->index(0,0,QModelIndex());
        index=ui->recipeIngredients->selectionModel()->selection().indexes().first();
        model->setData(index, ui->ingredientName->text());
        index=ui->recipeIngredients->selectionModel()->selection().indexes().last();
        model->setData(index, ui->ingredientQuantity->text());
    }
}
