#include "Credit.h"

Credit::Credit(const SMSAuthenticator& authenticator, const std::string& securityCode) 
                                            : authenticator(authenticator),securityCode(securityCode){}

void Credit::pay(){
    authenticator.authenticateSMS();
    std::cout << "Processing credit payment type" << "----";
    std::cout <<"Verifying security code: {" << securityCode << "}"  << std::endl;

}