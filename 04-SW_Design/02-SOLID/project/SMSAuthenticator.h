#ifndef SOLID_PRINCIPLES__SMSAUTHENTICATOR_H_
#define SOLID_PRINCIPLES__SMSAUTHENTICATOR_H_

#include <string>
#include <iostream>

class SMSAuthenticator{
public:
    SMSAuthenticator(const std::string& mobileNumber);
    void authenticateSMS();
private:
    std::string mobileNumber;
};

#endif