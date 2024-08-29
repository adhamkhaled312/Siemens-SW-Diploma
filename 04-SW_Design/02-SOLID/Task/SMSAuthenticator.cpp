#include "SMSAuthenticator.h"

SMSAuthenticator::SMSAuthenticator(const std::string& mobileNumber) : mobileNumber(mobileNumber) {}

void SMSAuthenticator::authenticateSMS(){
    std::cout<<"Authentiaction messege sent to : "<<mobileNumber<<std::endl;
}