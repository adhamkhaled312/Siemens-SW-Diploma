#include "viewFrames.h"
#include "ui_viewFrames.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mCreateGui();
}

void MainWindow::mCreateGui()
{
    this->ui->tableWidget->setColumnCount(2);
    QStringList headerLabels;
    headerLabels << "Name" << "Email";
    this->ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    this->ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

QString MainWindow::mGetInputLoginEmail()
{
    return ui->EmailInputLE->text();
}

QString MainWindow::mGetInputLoginPassword()
{
    return ui->PasswordInputLE->text();
}

QString MainWindow::mGetInputRegisterEmail()
{
    return ui->EmailLE->text();
}

QString MainWindow::mGetInputRegisterFirstName()
{
    return ui->FirstNameLE->text();
}

QString MainWindow::mGetInputRegisterPassword()
{
    return ui->PasswordLE->text();
}

void MainWindow::mShowUserFrame(QString email, QString firstName)
{
    ui->FirstNameLabel->setText(firstName);
    dCurrentUserEmail = email;
    ui->stackedWidget->setCurrentWidget(ui->page_4);
    ui->EmailLE->clear();
    ui->FirstNameLE->clear();
    ui->PasswordLE->clear();
}

void MainWindow::mLoadUsersGui(QMap<QString,QString> xEmployees)
{
    this->ui->tableWidget->clearContents();

    this->ui->tableWidget->setRowCount(xEmployees.keys().count());
    int currentRow = 0;
    for(QString lFirstName : xEmployees.keys())
    {
        QTableWidgetItem *lNameItem = new QTableWidgetItem(lFirstName);
        QTableWidgetItem *lEmailItem = new QTableWidgetItem(xEmployees[lFirstName]);
        this->ui->tableWidget->setItem(currentRow, 0, lNameItem);
        this->ui->tableWidget->setItem(currentRow, 1, lEmailItem);
        currentRow++;
    }
}

void MainWindow::mShowInsertState(bool state)
{
    if(state)
        QMessageBox::information(this,"Success", "Added Successfully");
    else
        QMessageBox::critical(this,"Error", "Error while adding employee");
}

void MainWindow::mShowLoginState(bool state)
{
    if(!state)
        QMessageBox::information(this,"Error", "Incorrect Email or Password");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LoginButton_clicked()
{
    //TODO:: Implement this function
    emit LoginAttempt();
}


void MainWindow::on_LogoutPB_clicked()
{
    //TODO:: Implement this function
}


void MainWindow::on_AddUserPB_clicked()
{
    //TODO:: Implement this function
    emit AddNewUserAttempt();
}

