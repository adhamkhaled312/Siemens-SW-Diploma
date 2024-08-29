#include<iostream>
#include "item.h"
#include "order.h"
#include "Debit.h"
#include "Credit.h"
#include "Paypal.h"
#include "SMSAuthenticator.h"
#include "RobotAuthenticator.h"

int main() {
  Item item1{"Monitor", 1, 5000.0};
  Item item2{"Mouse", 1, 150.0};
  Item item3{"HDMI cable", 2, 5.0};
  Order an_order{};

  an_order.AddItem(item1);
  an_order.AddItem(item2);
  an_order.AddItem(item3);

  an_order.PrintOrder();

  std::cout<< "The total price is {" << an_order.TotalPrice() << "}" << std::endl;

  SMSAuthenticator sms1("01095997525");
  SMSAuthenticator sms2("01001006334");
  RobotAuthenticator robot;

  Debit d1(sms1,"09878");
  Credit c1(sms2,"96553");
  Paypal p1(robot,"adhamkhaled312@gmail.com");

  std::cout<<"\n";
  try {
    an_order.PayOrder(&d1);
    std::cout<<"\n";
  } catch (int no) {
    std::cout << "Error" << std::endl;
  }

  try {
    an_order.PayOrder(&c1);
    std::cout<<"\n";
  } catch (int no) {
   std::cout << "Error" << std::endl;
  }

   try {
    an_order.PayOrder(&p1);
  } catch (int no) {
   std::cout << "Error" << std::endl;
  }
  return 0;
}