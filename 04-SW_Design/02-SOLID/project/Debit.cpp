#include "Debit.h"

Debit::Debit(const SMSAuthenticator& authenticator, const std::string& securityCode) 
                                            : authenticator(authenticator),securityCode(securityCode){}
void Debit::pay(){
    authenticator.authenticateSMS();
    std::cout << "Processing debit payment type" << "----";
    std::cout <<"Verifying security code: {" << securityCode << "}"  << std::endl;
}