#ifndef SOLID_PRINCIPLES__DEBIT_H_
#define SOLID_PRINCIPLES__DEBIT_H_

#include "Payment.h"
#include "SMSAuthenticator.h"
#include <string>
#include <iostream>
class Debit : public Payment{
public:
    Debit(const SMSAuthenticator& authenticator , const std::string& securityCode);
    void pay() override ;

private:
    SMSAuthenticator authenticator;
    std::string securityCode;
};

#endif