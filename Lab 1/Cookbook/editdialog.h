#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QStandardItem>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr);
    ~EditDialog();
    QList<QJsonObject> JsonObjectsList;
    QStringList JsonObjectsNamesList;
    int rowNumber;
    void showrecipe();
private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_recipeIngredients_clicked(const QModelIndex &index);

    void on_applyBtn_clicked();

    void on_addBtn_clicked();

    void save_file();

signals:
    void save_changes();


private:
    Ui::EditDialog *ui;
    QStandardItemModel *model;

};

#endif // EDITDIALOG_H
