#ifndef __USER_SERVICE_H__
#define __USER_SERVICE_H__
#include "../model/user/user.h"
#include "../security/authenticator.h"

class UserService{
private:
    Authenticator authenticator;
public:
    explicit UserService(const Authenticator &authenticator);

    std::string login(const User& user);
    std::string reg(const User& user,int userType);

};

#endif
