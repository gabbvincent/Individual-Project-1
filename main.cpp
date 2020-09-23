// Individual Project 1
// Vincent Gabb 
//
// 09/23/2020

#include <iostream>
#include <sstream>
#include <string>
using std::ios;
using std::string;
using std::ostringstream;
using namespace std;

 
// Create an Item object with a name, price, and quantity attribute.
struct Item {

  string name;
  double price;
  unsigned int quantity;
};

// Create a function to initialize an item
void initItem(Item &i, string name, double price, unsigned int quantity) {

  i.name = name;
  i.price = price;
  i.quantity = quantity;
}

// Create a function to determine total value of an item
double totalValue(const Item &i) {

return i.price * i.quantity;
}

// Reduce the quantity of an Item.
// If amount > Item.quantity, set Item.quantity to 0.
void reduceQuantity(Item &i, unsigned int amount) {

if (amount > i.quantity) {
  i.quantity = 0;
} else {
  i.quantity = i.quantity - amount;
 }
}

// Create a function to increase the quantity of an Item.
void increaseQuantity(Item &i, unsigned int amount) {

i.quantity = i.quantity + amount;
}

// Use the "magic formula" to format the price.
string toString(const Item &i) {

  ostringstream out;
  out.setf(ios::fixed);
  out.setf(ios::showpoint);
  out.precision(2);

  out << i.name << " (price: $" << i.price << ", " << "quantity: " << i.quantity << ")";

  return out.str();
}

int main() {

  Item item;

  initItem(item, "Chips", 2.5, 10);
  initItem(item, "Candy bar", 1.5, 10);
  initItem(item, "Fruit snacks", 1.0, 10);
  initItem(item, "Water", 1.0, 10);
  initItem(item, "Gatorade", 1.5, 10);

  















}