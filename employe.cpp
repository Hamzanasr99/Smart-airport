#include "employe.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include <iostream>
Employe::Employe()
{
id=0;
x=0;
nom="";
prenom="";
}

Employe::Employe(int id,QString nom,QString prenom,QString tel,QString mail,int bureau,int cin)
{
    this ->id =id;
this ->nom=nom;
this ->prenom=prenom;
    this ->mail=mail;
    this ->bureau=bureau;
    this ->tel=tel;
    this->cin=cin;

}
int Employe::getid()
{
    return id;
}
int Employe::getCin()
{return cin;}
int Employe::getBureau()
{return bureau;}
void Employe::setBureau(int bureau)
{
    this->bureau=bureau;
}
void Employe::setcin(int cin)
{
    this ->cin=cin;
}
QString Employe::getnom()
{return nom;}
QString Employe::getprenom(){
    return prenom;
}
void Employe::setid(int id)
{this ->id=id;
}
void Employe::setnom(QString nom)
{this ->nom=nom;}
void Employe::setprenom(QString prenom)
{this ->prenom=prenom;}

bool Employe::ajouter()
{bool test=false;

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString id_bureau=QString::number(bureau);
    QString id_cin=QString::number(cin);
          query.prepare("INSERT INTO EMPLOYE(id,nom,prenom,tel,mail,bureau,cin) "
                        "VALUES (:id, :forename, :surname, :tel, :mail, :bureau, :cin)");
          query.bindValue(":id",id_string);
          query.bindValue(":forename",nom);
          query.bindValue(":surname",prenom);
          query.bindValue(":tel",tel);
          query.bindValue(":mail",mail);
          query.bindValue(":bureau",bureau);
          query.bindValue(":cin",cin);
       return  query.exec();
return false;
}

bool Employe::modifier()
{
        QSqlQuery query;
       //  query.exec("UPDATE EMPLOYE SET cin=151515 WHERE id=:id");
       //query.prepare("UPDATE EMPLOYE SET id=:id where id=:1;");
        query.prepare("UPDATE EMPLOYE SET NOM= :NOM,CIN= :CIN,PRENOM= :PRENOM  where id=:id");
        //cout<<"id="<<id<<endl;
         query.bindValue(":id",id);
        query.bindValue(":CIN", cin);
       query.bindValue(":NOM",nom);
       query.bindValue(":PRENOM",prenom);


        return  query.exec();
}
QSqlQueryModel* Employe::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM employe ");
//model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
//model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
//model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));

 return model;

}

QSqlQueryModel* Employe::afficherChercher(const QString &aux,int x)
{
 QSqlQueryModel* model=new QSqlQueryModel();
 switch (x){
 case 1:    model->setQuery("Select* FROM employe where (id)LIKE '%"+aux+"%'");
break;
 case 2:
model->setQuery("Select* FROM employe where (nom)LIKE '%"+aux+"%'");
     break;
 case 3:
model->setQuery("Select* FROM employe where (cin)LIKE '%"+aux+"%'");
     break;

 case 4:
model->setQuery("Select* FROM employe where (bureau)LIKE '%"+aux+"%'");
     break;
}
 return model;

}
bool Employe::supprimer(int id)
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    if (chercherId(id_string))
          {query.prepare("Delete from employe where id=:id");
          query.bindValue(0,id);
}
       return  query.exec();

}
bool Employe::chercherId(const QString &aux)
 {
     QSqlQuery query;
   if( query.prepare("SELECT COUNT (*)FROM employe where (id)LIKE '%"+aux+"%'"))

       //query.bindValue(0,id);

    { cout<<"hey"<<endl;
        return true;

    }
    cout<<"non"<<endl;
    return false;

 }
/*
bool Employe::chercherId(int n)
{

    QSqlQuery query;
          query.prepare("Select* from employe where id=:id");
          query.bindValue(1,id);

       return  query.exec();

}
*/

Employe Employe::modifierAff(QString cin)
{
    Employe E;
     QSqlQueryModel model;
    QSqlQuery query;

    model.setQuery("SELECT * from EMPLOYE WHERE (id LIKE '"+cin+"')");
    //QString Nom=model.data(model.index(0, 0)).toString();
    QString Nom=model.data(model.index(0, 1)).toString();
    QString Prenom=model.data(model.index(0,2)).toString();
    QString Cin=model.data(model.index(0,6)).toString();
    //QString Fonction=model.data(model.index(0, 4)).toString();
    //QString Tel=model.data(model.index(0, 5)).toString();
       // QString Sexe=model.data(model.index(0, 6)).toString();
       /* query.prepare("SELECT * from EMPLOYE WHERE CIN= :CIN");
        query.bindValue(":CIN",cin);*/


      //  qInfo() << "Nom"<<" "<<model.data(model.index(0, 1)).toString()<<endl;

        E.setnom(Nom);
       E.setprenom(Prenom);
       E.setcin(Cin.toInt());
     /*  E.setsalaire(Salaire.toInt());
       E.settel(Tel.toInt());
       E.setfonction(Fonction);
       E.setsexe(Sexe);
*/
                return    E;

}
