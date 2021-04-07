#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStandardItemModel>
#include <QMainWindow>
#include <QJsonObject>
#include <QFile>






QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<QJsonObject> JsonObjectsList;
    QStringList JsonObjectsNamesList;


private slots:
    void on_btnAdd_clicked();

    void on_btnEdit_clicked();

    void on_btnDelete_clicked();

    void readrecipes();

    void save_file();

    void showrecipes(QList<QJsonObject> objects, QStringList names);

    void deleterecipe();

    void update_recipes();





private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;

};
#endif // MAINWINDOW_H
