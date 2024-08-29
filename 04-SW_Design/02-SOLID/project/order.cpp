#include "order.h"

void Order::AddItem(const Item &new_item) {
  items_.push_back(new_item);
}

void Order::PrintOrder() const {
  for (auto &item : items_) {
    std::cout << item.item_ << std::endl;
  }
}

float Order::TotalPrice() const {
  float total{0.0};
  for (auto &item : items_) {
    total += static_cast<float>(item.quantity_) * item.price_;
  }
  return total;
}

void Order::PayOrder(Payment *method) {
    method->pay();
    status_ = "paid";
}