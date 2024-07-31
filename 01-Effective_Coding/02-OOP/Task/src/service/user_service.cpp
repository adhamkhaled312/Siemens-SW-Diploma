#include "user_service.h"

static const int PATIENT_OPTION=1;
static const int DOCTOR_OPTION=2;
static const int ADMIN_OPTION=3;

std::string UserService::login(const User& user){
    std::string returnMessage;
    if(authenticator.authenticate(const_cast<User &>(user))){
        returnMessage="Good Credentials\n";
    }
    else{
        returnMessage="Bad Credentials\n";
    }
    return returnMessage;
}

std::string UserService::reg(const User &user,int userType) {
    std::string returnMessage;
    std::optional<User>userOptional;
    switch(userType){
        case PATIENT_OPTION: userOptional=authenticator.queryForPatient(user.getEmail()); break;
        case DOCTOR_OPTION: userOptional=authenticator.queryForDoctor(user.getEmail()); break;
        case ADMIN_OPTION: userOptional=authenticator.queryForAdmin(user.getEmail()); break;
    }
    if(userOptional.has_value()){
        returnMessage="Account already exists try another email\n";
    }
    else{
        returnMessage="Registration successful\n";
        authenticator.addUser(const_cast<User &>(user), userType);
    }
    return returnMessage;
}
UserService::UserService(const Authenticator &authenticator) : authenticator(authenticator) {}
