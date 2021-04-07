#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entrydialog.h"
#include "editdialog.h"
#include <QFile>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDir>
#include <QJsonArray>
#include <QModelIndex>
#include <QModelIndexList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Loading recipes from the json file
    readrecipes();

    //Showing the loaded recipes in the table
    showrecipes(this->JsonObjectsList, this->JsonObjectsNamesList);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAdd_clicked()
{
    EntryDialog* dlg = new EntryDialog(this);
    dlg->show();
    dlg->JsonObjectsList = this->JsonObjectsList;
    dlg->JsonObjectsNamesList = this->JsonObjectsNamesList;
    dlg->start();

    connect(dlg, SIGNAL(save_changes()), this, SLOT(update_recipes()));

}


void MainWindow::on_btnDelete_clicked()
{
    QMessageBox::StandardButton confirm = QMessageBox::question(this, "Warning", "Are you sure you want to delete this?");
    if(confirm == QMessageBox::Yes)
    {
        deleterecipe();
    }
}


void MainWindow::on_btnEdit_clicked()
{
    QItemSelection selection = ui->RecipeList->selectionModel()->selection();
    if(!selection.isEmpty())
    {
        if(selection.indexes().size()==3)
        {
            EditDialog* dlg = new EditDialog(this);
            dlg->JsonObjectsList = this->JsonObjectsList;
            dlg->JsonObjectsNamesList = this->JsonObjectsNamesList;
            QModelIndex selectedRow = selection.indexes().last();
            int rownumber = selectedRow.row();
            dlg->rowNumber=rownumber;
            dlg->show();
            dlg->showrecipe();
            connect(dlg, SIGNAL(save_changes()), this, SLOT(update_recipes()));

        }
    }


}

void MainWindow::update_recipes()
{
    readrecipes();
    showrecipes(JsonObjectsList, JsonObjectsNamesList);
}

void MainWindow::readrecipes()
{
    QString path = QCoreApplication::applicationDirPath();
    QTextStream(stdout)<<path<<"\n";
    path.append("/recipes.json");

    QFile file(path);

    if (!file.open(QIODevice::ReadWrite))
    {
        return;
    }

    QJsonDocument textFromJson = QJsonDocument::fromJson(file.readAll());
    file.close();

    if(!textFromJson.isNull())
    {

        if(textFromJson.isObject())
        {
            QJsonObject titlesJson = textFromJson.object();
            QList<QJsonObject> ObjectList;
            QStringList NameList;
            QJsonObject::iterator iterator;

            for(iterator=titlesJson.begin();iterator!=titlesJson.end();++iterator)
            {
                NameList.push_back(iterator.key());
                QJsonObject help = iterator.value().toObject();
                ObjectList.push_back(help);
            }
            this->JsonObjectsList = ObjectList;
            this->JsonObjectsNamesList = NameList;
        } else{
            //json file empty
            qDebug("Json file is empty");
        }
    } else{
          QMessageBox::critical(this, "Error", "Json file not imported!");
          return;
        }


}


void MainWindow::showrecipes(QList<QJsonObject> objects, QStringList names)
{
    model = new QStandardItemModel(names.length(), 3, this);
    for(int row=0;row<names.length();row++)
    {
        for(int column=0;column<3;column++)
        {
            QModelIndex index = model->index(row, column, QModelIndex());
            QJsonObject object = objects[row];
            if(column==0)
            {
                model->setData(index, names[row]);
            }

            if(column==1)
            {
                QJsonArray recipeArray = object.value("recipe").toArray();
                QString recipeString;
                for(int i=0;i<recipeArray.size();i++)
                {
                    recipeString.append(recipeArray[i].toString());
                    recipeString.append("\n");
                }
                model->setData(index, recipeString);
            }

            if(column==2)
            {
                QList keyList = object.keys();
                QString ingredientsString;
                for(int i=0;i<keyList.length();i++)
                {
                    if(keyList[i]!="recipe")
                    {
                        ingredientsString.append(keyList[i]);
                        ingredientsString.append(" ");
                        ingredientsString.append(object.value(keyList[i]).toString());
                        ingredientsString.append("\n");
                    }
                }
                model->setData(index, ingredientsString);
            }
        }
    }


    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "Recipe");
    model->setHeaderData(2, Qt::Horizontal, "Ingredients");

    ui->RecipeList->setModel(model);

    ui->RecipeList->setMinimumSize(820, 300);

    ui->RecipeList->setColumnWidth(0,50);
    ui->RecipeList->setColumnWidth(1,500);
    ui->RecipeList->setColumnWidth(2,250);

    ui->RecipeList->verticalHeader()->setDefaultSectionSize(150);

}


void MainWindow::deleterecipe()
{
    QItemSelection selection = ui->RecipeList->selectionModel()->selection();
    QList <int> removeRows;
    QModelIndex index = selection.indexes().first();
    removeRows.append(index.row());

    for(int i=0;i<removeRows.length();i++)
    {
        JsonObjectsList.removeAt(removeRows.at(i));
        JsonObjectsNamesList.removeAt(removeRows.at(i));
    }

    save_file();
    showrecipes(JsonObjectsList, JsonObjectsNamesList);
}

void MainWindow::save_file()
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


