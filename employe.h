#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQueryModel>
using namespace std;
class Employe
{
private:
    int id,bureau,cin,x;
    QString nom,prenom,tel,mail;
public:
    Employe();
    Employe(int,QString,QString,QString,QString,int,int);
    int getid();
    QString getnom();
    QString getprenom();
    int getCin();
    int getBureau();
    void setcin(int);
    void setBureau(int);
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    bool supprimer(int id);
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficherChercher(const QString &aux,int x);
    bool chercherId(const QString &aux);
    bool modifier();
    Employe modifierAff(QString);
};

#endif // EMPLOYE_H
