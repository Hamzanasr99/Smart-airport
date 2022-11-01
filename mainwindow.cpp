#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QIntValidator>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,99999,this));


ui->tab_employe->setModel(E.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_pb_ajouter_clicked()
{ int id=ui->le_id->text().toInt();
    QMessageBox msgBox;
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
   QString tel=ui->le_tel->text();
   QString mail=ui->le_mail->text();
   int bureau=ui->le_bureau->text().toInt();
   int cin=ui->le_cin->text().toInt();
   Employe E(id,nom,prenom,tel,mail,bureau,cin);
   bool test=E.ajouter();
     if (test)
     {ui->tab_employe->setModel(E.afficher());
       msgBox.setText("Ajout avec succes");
     }

msgBox.exec();
}

void MainWindow::on_pb_ajouter_2_clicked()
{QMessageBox msgBox;
  int id=ui->le_idmod->text().toInt();

 QString id_string=QString::number(id);

       QString nom=ui->le_nommod->text();
       QString prenom=ui->le_prenommod->text();
       QString tel=ui->le_telmod->text();
       QString mail=ui->le_mailmod->text();
       int bureau=ui->le_bureaumod->text().toInt();
       int cin=ui->le_cinmod->text().toInt();
       Employe E(id,nom,prenom,tel,mail,bureau,cin);
       bool test=E.modifier();

         if (test)
         {
             ui->tab_employe->setModel(E.afficher());
           msgBox.setText("Modifie avec succes");
         }
         else
 msgBox.setText("error");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Employe E1;
    QMessageBox msgBox;
    E1.setid(ui->le_supprimer->text().toInt());
    //if  (E1.chercherId(E1.getid()))
       {
    bool test=E1.supprimer(E1.getid());


    if (test)
    {msgBox.setText("Suppresion avec succes");
        ui->tab_employe->setModel(E1.afficher());}
    else
        msgBox.setText("Echec de suppresion");}
    //else
      //  msgBox.setText("ID intourvable");
    msgBox.exec();
}





void MainWindow::on_tab_chercher_activated(const QModelIndex &index)
{

}
void MainWindow::on_pb_chercher_clicked()
{
    QString id=ui->le_chercher->text();
    //cout<<id<<endl;
    if (ui->chercher_type->currentText()=="ID")
        ui->tab_chercher->setModel(E.afficherChercher(id,1));
    else if (ui->chercher_type->currentText()=="NOM")
    ui->tab_chercher->setModel(E.afficherChercher(id,2));
    else if(ui->chercher_type->currentText()=="CIN")
        ui->tab_chercher->setModel(E.afficherChercher(id,3));
    else ui->tab_chercher->setModel(E.afficherChercher(id,4));
}


void MainWindow::on_pb_verifier_clicked()
{

    {

        Employe E;
       E=E.modifierAff(ui->le_idmod->text());
       cout<<"id"<<E.getid()<<endl;
       cout<<"cin"<<E.getCin()<<endl;
    QString Scin=QString::number(E.getCin());
           ui->le_cinmod->setText(Scin);
           ui->le_nommod->setText(E.getnom());
           ui->le_prenommod->setText(E.getprenom());




    }

}
