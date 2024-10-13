#ifndef VIEWFRAMES_H
#define VIEWFRAMES_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString mGetInputLoginEmail();
    QString mGetInputLoginPassword();
    QString mGetInputRegisterEmail();
    QString mGetInputRegisterFirstName();
    QString mGetInputRegisterPassword();
    void mShowUserFrame(QString email, QString firstName);
    void mShowInsertState(bool state);
    void mShowLoginState(bool state);
    void mLoadUsersGui(QMap<QString,QString> xEmployees);

private slots:
    void on_LoginButton_clicked();

    void on_LogoutPB_clicked();

    void on_AddUserPB_clicked();

private:
    Ui::MainWindow *ui;
    QString dCurrentUserEmail;


    void mCreateGui();

signals:
    void LoginAttempt();
    void AddNewUserAttempt();
};
#endif // VIEWFRAMES_H
