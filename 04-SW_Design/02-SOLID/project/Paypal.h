#ifndef SOLID_PRINCIPLES__PAYPAL_H_
#define SOLID_PRINCIPLES__PAYPAL_H_

#include "Payment.h"
#include "RobotAuthenticator.h"
#include <string>
#include <iostream>
class Paypal : public Payment{
public:
    Paypal(const RobotAuthenticator& authenticator, const std::string& email);
    void pay() override;

private:
    RobotAuthenticator authenticator;
    std::string email;
};

#endif