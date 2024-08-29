#ifndef SOLID_PRINCIPLES__CREDIT_H_
#define SOLID_PRINCIPLES__CREDIT_H_

#include "Payment.h"
#include "SMSAuthenticator.h"
#include <string>
#include <iostream>
class Credit : public Payment{
public:
    Credit(const SMSAuthenticator& authenticator , const std::string& securityCode);
    void pay() override;

private:
    SMSAuthenticator authenticator;
    std::string securityCode;
};

#endif