#include "ui_manager.h"

static const int LOGIN_OPTION=1;
static const int REGISTER_OPTION=2;

static const int PATIENT_OPTION=1;
static const int DOCTOR_OPTION=2;
static const int ADMIN_OPTION=3;



void ui_manager::viewHomePage() {
    int option;
    std::cout << "Welcome to healthcare appointment system\nChoose an option\n1- Login\n2- Register\n";
    std::cin >> option;
    switch (option) {
        case LOGIN_OPTION: viewLoginPage(); break;
        case REGISTER_OPTION: viewRegisterPage(); break;
        default: std::cout<<"Invalid option"; viewHomePage(); break;
    }
}

void ui_manager::viewLoginPage() {
    std::string returnMessage;
    int option;
    std::cout << "Do you want to register as a\n1- Patient\n2- Doctor\n3- Admin";
    std::cin >> option;
    getUserDetails();
    returnMessage = userService.login(user);
    std::cout << returnMessage;
    if (returnMessage == "Good Credentials\n") {
        switch (option) {
            case PATIENT_OPTION:
                viewPatientOptions();
                break;
            case DOCTOR_OPTION:
                viewDoctorOptions();
                break;
            case ADMIN_OPTION:
                viewAdminOptions();
                break;
            default:
                std::cout<<"Invalid option ";
                viewLoginPage();
                break;
        }
    } else if (returnMessage == "Bad Credentials\n") {
        viewLoginPage();
    } else {
        std::cerr << "Error: " << returnMessage;
    }
}

void ui_manager::viewRegisterPage() {
  std::string returnMessage;
  int option;
  std::cout << "Do you want to register as a\n1- Patient\n2- Doctor\n3- Admin";
  std::cin >> option;
  getUserDetails();
  returnMessage = userService.reg(user,option);
  std::cout << returnMessage;
  if(returnMessage=="Registration successful\n"){
      viewLoginPage();
  }
  else if(returnMessage=="Account already exists try another email\n"){
      viewRegisterPage();
  }
}

void ui_manager::viewDoctorOptions() {
    std::cout << "1. view schedule" << std::endl;
    std::cout << "2. update schedule" << std::endl;
    std::cout << "3. view patient" << std::endl;
    std::cout << "4. update medical record" << std::endl;
    std::cout << "5. view profile" << std::endl;
    /*TODO: call proper APIs for each case*/
}

void ui_manager::viewPatientOptions() {
    int option;
    std::cout << "1. view medical history\n";
    std::cout << "2. book appointment\n";
    std::cout << "3. view profile\n";
    std::cin>>option;
    /*TODO: call proper APIs for each case*/
    switch (option) {
        case 1:
            ;break;
        case 2:
            ;break;
        case 3:
            ;break;
    }

}

void ui_manager::viewAdminOptions() {
    std::cout << "1. view patient\n";
    std::cout << "2. update patient\n";
    std::cout << "3. view doctor\n";
    std::cout << "3. update doctor\n";
    /*TODO: call proper APIs for each case*/
}

void ui_manager::getUserDetails() {
    std::string email;
    std::string password;
    std::cout<<"Please enter youe details\nEmail: ";
    std::getline(std::cin, email);
    std::cout<<"Password: ";
    std::getline(std::cin, password);
    user.setPassword(password);
    user.setEmail(email);
}

void ui_manager::setUserService(const UserService &userService) {
    ui_manager::userService = userService;
}
