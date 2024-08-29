#ifndef SOLID_PRINCIPLES__ITEM_H_
#define SOLID_PRINCIPLES__ITEM_H_
#include<string>

struct Item {
  Item(std::string item, int quantity, float price)
      : item_{item}
      , quantity_{quantity}
      , price_{price} {}

  std::string item_;
  int quantity_;
  float price_;
};
#endif//SOLID_PRINCIPLES__ITEM_H_