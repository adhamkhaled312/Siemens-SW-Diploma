#include "Paypal.h"

Paypal::Paypal(const RobotAuthenticator& authenticator,const std::string& email) 
                                        : authenticator(authenticator),email(email){}

void Paypal::pay(){
    authenticator.authenticateNotARobot();
    std::cout << "Processing paypal payment type" << "----";
    std::cout <<"Verifying email address: {" << email << "}"  << std::endl;
}