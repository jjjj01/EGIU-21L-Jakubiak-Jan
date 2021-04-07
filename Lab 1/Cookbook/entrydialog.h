#ifndef ENTRYDIALOG_H
#define ENTRYDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QStandardItem>

namespace Ui {
class EntryDialog;
}

class EntryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EntryDialog(QWidget *parent = nullptr);
    ~EntryDialog();
    QList<QJsonObject> JsonObjectsList;
    QStringList JsonObjectsNamesList;
    void start();

    QString recipeName;
    QJsonObject recipeRecipe;

private slots:
    void on_btnCancel_clicked();

    void on_btnOK_clicked();

    void on_recipeIngredients_clicked(const QModelIndex &index);

    void on_addBtn_clicked();

    void on_applyBtn_clicked();

    void save_file();

signals:
    void save_changes();



private:
    Ui::EntryDialog *ui;
    QStandardItemModel *model;
};

#endif // ENTRYDIALOG_H
