/********************************************************************************
** Form generated from reading UI file 'viewFrames.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWFRAMES_H
#define UI_VIEWFRAMES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QFrame *frame;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *PasswordInputLE;
    QLabel *label;
    QLineEdit *EmailInputLE;
    QPushButton *LoginButton;
    QLabel *label_2;
    QWidget *page_4;
    QFrame *frame_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *FirstNameLE;
    QPushButton *LogoutPB;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *PasswordLE;
    QPushButton *AddUserPB;
    QLabel *FirstNameLabel;
    QLabel *label_6;
    QLineEdit *EmailLE;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuUsers;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(703, 616);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(703, 616));
        MainWindow->setMaximumSize(QSize(703, 616));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 701, 541));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        frame = new QFrame(page_3);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 180, 641, 151));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget = new QWidget(frame);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 621, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 11);
        PasswordInputLE = new QLineEdit(gridLayoutWidget);
        PasswordInputLE->setObjectName("PasswordInputLE");
        QFont font;
        font.setPointSize(11);
        PasswordInputLE->setFont(font);

        gridLayout->addWidget(PasswordInputLE, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MS Reference Sans Serif")});
        font1.setPointSize(12);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        EmailInputLE = new QLineEdit(gridLayoutWidget);
        EmailInputLE->setObjectName("EmailInputLE");
        EmailInputLE->setFont(font);

        gridLayout->addWidget(EmailInputLE, 0, 1, 1, 1);

        LoginButton = new QPushButton(gridLayoutWidget);
        LoginButton->setObjectName("LoginButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LoginButton->sizePolicy().hasHeightForWidth());
        LoginButton->setSizePolicy(sizePolicy1);
        LoginButton->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(LoginButton, 2, 1, 1, 1, Qt::AlignRight);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        frame_2 = new QFrame(page_4);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 701, 551));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayoutWidget_2 = new QWidget(frame_2);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 691, 531));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        FirstNameLE = new QLineEdit(gridLayoutWidget_2);
        FirstNameLE->setObjectName("FirstNameLE");
        FirstNameLE->setFont(font);

        gridLayout_2->addWidget(FirstNameLE, 2, 2, 1, 1);

        LogoutPB = new QPushButton(gridLayoutWidget_2);
        LogoutPB->setObjectName("LogoutPB");
        sizePolicy1.setHeightForWidth(LogoutPB->sizePolicy().hasHeightForWidth());
        LogoutPB->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(LogoutPB, 0, 2, 1, 1, Qt::AlignRight);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName("label_7");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("MS Reference Sans Serif")});
        font2.setPointSize(11);
        label_7->setFont(font2);

        gridLayout_2->addWidget(label_7, 2, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);

        gridLayout_2->addWidget(label_5, 3, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);

        gridLayout_2->addWidget(label_4, 1, 1, 1, 2);

        PasswordLE = new QLineEdit(gridLayoutWidget_2);
        PasswordLE->setObjectName("PasswordLE");
        PasswordLE->setFont(font);
        PasswordLE->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(PasswordLE, 4, 2, 1, 1);

        AddUserPB = new QPushButton(gridLayoutWidget_2);
        AddUserPB->setObjectName("AddUserPB");
        sizePolicy1.setHeightForWidth(AddUserPB->sizePolicy().hasHeightForWidth());
        AddUserPB->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(AddUserPB, 5, 2, 1, 1, Qt::AlignRight);

        FirstNameLabel = new QLabel(gridLayoutWidget_2);
        FirstNameLabel->setObjectName("FirstNameLabel");
        QPalette palette;
        QBrush brush(QColor(5, 0, 47, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        FirstNameLabel->setPalette(palette);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("MS Reference Sans Serif")});
        font3.setPointSize(18);
        FirstNameLabel->setFont(font3);

        gridLayout_2->addWidget(FirstNameLabel, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName("label_6");
        label_6->setFont(font2);

        gridLayout_2->addWidget(label_6, 4, 1, 1, 1);

        EmailLE = new QLineEdit(gridLayoutWidget_2);
        EmailLE->setObjectName("EmailLE");
        EmailLE->setFont(font);

        gridLayout_2->addWidget(EmailLE, 3, 2, 1, 1);

        tableWidget = new QTableWidget(gridLayoutWidget_2);
        tableWidget->setObjectName("tableWidget");

        gridLayout_2->addWidget(tableWidget, 6, 1, 1, 2);

        stackedWidget->addWidget(page_4);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 703, 21));
        menuUsers = new QMenu(menubar);
        menuUsers->setObjectName("menuUsers");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuUsers->menuAction());

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MVC Tutorial", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        LogoutPB->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Add new user", nullptr));
        AddUserPB->setText(QCoreApplication::translate("MainWindow", "Add User", nullptr));
        FirstNameLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        menuUsers->setTitle(QCoreApplication::translate("MainWindow", "Users", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWFRAMES_H
