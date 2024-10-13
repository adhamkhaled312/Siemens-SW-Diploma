#ifndef MODEL_H
#define MODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringList>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QFile>
#include <QDebug>

class model
{
private:
    QSqlDatabase mDatabase;
    model(const QString& _dbPath);
    static model* mModel;
    void createTables();
    bool executeQuery(QSqlQuery query);
public:
   static model *getInstance(const QString& _dbPath);
   bool authenticateUser(QString _email, QString _password);
   bool insertEmployee(QString firstName, QString Email, QString Password);
   QString mGetEmployeeName(QString Email);
   QMap<QString, QString> mGetAllEmployeesData();
};

#endif // MODEL_H
