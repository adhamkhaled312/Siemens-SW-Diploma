#include "model.h"


model* model::mModel = nullptr;

model *model::getInstance(const QString& _dbPath)
{
    if (mModel == nullptr) {
        mModel = new model(_dbPath);
    }
    return mModel;
}

model::model(const QString& _dbPath)
{
    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER)) {
        mDatabase = QSqlDatabase::addDatabase(DRIVER);
        mDatabase.setDatabaseName(_dbPath);
        if (!mDatabase.open())
        {
            qWarning() << "ERROR: " << mDatabase.lastError().text();
        }
        else
        {
           createTables();
        }
    }
}

bool model::executeQuery(QSqlQuery query) {
    bool success = true;
    if (!query.exec()) {
        success = false;
    }

    return success;
}

void model::createTables() {
    if (!mDatabase.tables().contains(QLatin1String("employees"))) {
        executeQuery(QSqlQuery("CREATE TABLE employees"
                     "(first_name TEXT, "
                     "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                     "email TEXT UNIQUE, "
                     "password TEXT)"));
     }
    insertEmployee("Administrator","admin", "admin");
}

bool model::authenticateUser(QString email, QString password) {
    bool exists = false;
    QSqlQuery authQuery;
    authQuery.prepare("SELECT email FROM employees WHERE email = (:email) AND password = (:password)");
    authQuery.bindValue(":email", email);
    authQuery.bindValue(":password", password);

    if (authQuery.exec())
    {
        if (authQuery.next())
        {
           return true;
        }
    }

    return exists;
}


bool model::insertEmployee(QString firstName, QString Email, QString Password) {
    bool success = false;
    QSqlQuery query;

    query.prepare("INSERT INTO employees (first_name, email ,password)"
                  "VALUES (:firstname ,:email, :password);");
    query.bindValue(":firstname", firstName);
    query.bindValue(":email", Email);
    query.bindValue(":password", Password);

    try {
        success = executeQuery(query);
    } catch (std::runtime_error e){
        qWarning() << "ERROR: " << mDatabase.lastError().text();
    }
    return success;
}

QString model::mGetEmployeeName(QString Email) {
    QSqlQuery query;
    QString firstName;
    query.prepare("SELECT first_name FROM employees WHERE email = :email");
    query.bindValue(":email", Email);
    if (query.exec()) {
        while (query.next()) firstName = query.value(0).toString();
    }
    return firstName;
}


QMap<QString, QString> model::mGetAllEmployeesData()
{
    QSqlQuery query;
    QMap<QString, QString> employess;
    query.prepare("SELECT first_name,email FROM employees");
    if (query.exec()) {
        while (query.next())
        {
            employess[query.value(0).toString()] = query.value(1).toString();
        }
    }
    return employess;
}



