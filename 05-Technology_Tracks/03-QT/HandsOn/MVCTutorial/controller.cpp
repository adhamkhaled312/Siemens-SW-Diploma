#include "controller.h"


controller::controller(MainWindow *view, model* xModel)
{
    dModel = xModel;
    dView = view;

    mRegisterSignals();
}

void controller::mRegisterSignals()
{
    //TODO:: connect login attempt and add new user attempts to slots
    connect(dView,&MainWindow::LoginAttempt,this,&controller::mAttemptLoginAndRedirect);
    connect(dView,&MainWindow::AddNewUserAttempt,this,&controller::mAttemptAddingEmployee);

}

void controller::mAttemptLoginAndRedirect()
{
    //TODO:: Implement this function
    QString loginMail=dView->mGetInputLoginEmail();
    QString loginPW=dView->mGetInputLoginPassword();
    if(dModel->authenticateUser(loginMail,loginPW)){
        dView->mShowLoginState(true);
        dView->mLoadUsersGui(dModel->mGetAllEmployeesData());
    }
    else{
        qDebug()<<"wrong";
    }
}

void controller::mAttemptAddingEmployee()
{
    //TODO:: Implement this function
}
