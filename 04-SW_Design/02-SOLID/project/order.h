#ifndef SOLID_PRINCIPLES__ORDER_H_
#define SOLID_PRINCIPLES__ORDER_H_
#include "item.h"
#include "Payment.h"
#include <vector>
#include <string>
#include <iostream>

class Order {
 public:
  void AddItem(const Item& new_item);
  float TotalPrice() const;
  void PayOrder(Payment *method);
  void PrintOrder() const;

 private:
  std::vector<Item> items_;
  std::string status_{"open"};
};

#endif//SOLID_PRINCIPLES__ORDER_H_