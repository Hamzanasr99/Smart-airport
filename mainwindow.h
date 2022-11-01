#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "employe.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_tab_employe_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_tab_chercher_activated(const QModelIndex &index);

    void on_pb_chercher_clicked();

    void on_pb_ajouter_2_clicked();

    void on_progressBar_valueChanged(int value);

    void on_pb_verifier_clicked();

private:
    Ui::MainWindow *ui;
    Employe E;
};
#endif // MAINWINDOW_H
