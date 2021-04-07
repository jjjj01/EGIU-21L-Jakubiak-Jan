#include "editdialog.h"
#include "ui_editdialog.h"
#include "mainwindow.h"
#include <QJsonDocument>
#include <QString>
#include <QJsonArray>
#include <QVariant>

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::on_buttonBox_rejected()
{
    close();
}

void EditDialog::on_buttonBox_accepted()
{
    JsonObjectsNamesList.removeAt(rowNumber);
    JsonObjectsList.removeAt(rowNumber);

    JsonObjectsNamesList.insert(rowNumber, ui->recipeName->toPlainText());

    QStringList recipeLines;
    recipeLines = ui->recipeRecipe->toPlainText().split('\n');
    QJsonArray recipeArray;
    for(int i=0;i<recipeLines.length();i++)
    {
        recipeArray.push_back(recipeLines.at(i));
    }
    QJsonObject recipeRecipe;
    recipeRecipe.insert("recipe", recipeArray);

    for(int i=0;i<model->rowCount();i++)
    {
        recipeRecipe.insert(model->index(i, 0).data().toString(),model->index(i, 1).data().toString());
    }
    JsonObjectsList.insert(rowNumber, recipeRecipe);
    save_file();
    emit save_changes();
    this->close();
}


void EditDialog::save_file()
{
    QString path = QCoreApplication::applicationDirPath();
    QTextStream(stdout)<<path<<"\n";
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

void EditDialog::showrecipe()
{
    if(!JsonObjectsNamesList.isEmpty())
    {
        ui->recipeName->insertPlainText(JsonObjectsNamesList.at(rowNumber));
        QJsonObject object = JsonObjectsList.at(rowNumber);

        QJsonArray recipeArray = object.value("recipe").toArray();
        QString recipeString;
        for(int i=0;i<recipeArray.size();i++)
        {
            recipeString.append(recipeArray[i].toString());
            recipeString.append("\n");
        }
        ui->recipeRecipe->insertPlainText(recipeString);




        QJsonObject object1 = JsonObjectsList[rowNumber];
        QList keyList = object1.keys();
        for(int i=0;i<keyList.length();i++)
        {
            if(keyList[i]=="recipe")
            {
                keyList.removeAt(i);
            }
        }

        model = new QStandardItemModel(keyList.length(), 2, this);

        for(int row=0;row<keyList.length();row++)
        {

                for(int column=0;column<2;column++)
                {
                    QModelIndex index = model->index(row, column, QModelIndex());
                    if(column==0)
                    {
                        model->setData(index, keyList[row]);
                    }

                    if(column==1)
                    {
                        QString ingredientsString;
                        ingredientsString=object1.value(keyList[row]).toString();
                        model->setData(index, ingredientsString);
                    }

                }

        }




    }
    model->setHeaderData(0, Qt::Horizontal, "Ingredient name");
    model->setHeaderData(1, Qt::Horizontal, "Quantity");

    ui->recipeIngredients->setModel(model);


}

void EditDialog::on_recipeIngredients_clicked(const QModelIndex &index)
{
    ui->ingredientName->setText(model->index(index.row(), 0).data().toString());
    ui->ingredientQuantity->setText(model->index(index.row(), 1).data().toString());
}


void EditDialog::on_applyBtn_clicked()
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

void EditDialog::on_addBtn_clicked()
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
