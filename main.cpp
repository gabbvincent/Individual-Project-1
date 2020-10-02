// Individual Project 1
// Vincent Gabb 
//
// 09/23/2020

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using std::ios;
using std::string;
using std::ostringstream;
using namespace std;

 
  // Create an Item object with a name, price, and quantity attribute.
  struct Item {

  int ID;
  string name;
  double price;
  unsigned int quantity;
 };

  // Create a function to determine total value of an item
  double totalValue(const Item &vendingItem) {

  return vendingItem.price * vendingItem.quantity;
 }

  // Reduce the quantity of an Item.
  // If amount > Item.quantity, set Item.quantity to 0.
  void reduceQuantity(Item &vendingItem, unsigned int amount) {

 if (amount > vendingItem.quantity) {
  vendingItem.quantity = 0;
 } else {
  vendingItem.quantity = vendingItem.quantity - amount;
  }
 }

  // Create a function to increase the quantity of an Item.
  void increaseQuantity(Item &customerInventory, unsigned int amount) {

 customerInventory.quantity = customerInventory.quantity + amount;
 }

  // Use the "magic formula" to format the price.
  string toString(const Item &i) {

  ostringstream out;
  out.setf(ios::fixed);
  out.setf(ios::showpoint);
  out.precision(2);

  out <<"["<< i.ID << "] " << i.name << " (price: $" << i.price << ", " << "quantity: " << i.quantity << ")";

  

  return out.str();
 }

 int main() {

  // Create an object array for Items in the vending Machine.
  Item vendingItem[6];
  vendingItem[1] = { 1, "Chips", 1.75, 10};
  vendingItem[2] = { 2, "Candy bar", 1.50, 10};
  vendingItem[3] = { 3, "Fruit snacks", 1.00, 10};
  vendingItem[4] = { 4, "Water", 1.00, 10};
  vendingItem[5] = { 5, "Gatorade", 1.50, 10};

  // Create an object array for Items in the customers Inventory.
  Item customerInventory[6];
  customerInventory[1] = { 1, "Chips", 1.75, 0};
  customerInventory[2] = { 2, "Candy bar", 1.50, 0};
  customerInventory[3] = { 3, "Fruit snacks", 1.00, 0};
  customerInventory[4] = { 4, "Water", 1.00, 0};
  customerInventory[5] = { 5, "Gatorade", 1.50, 0};
  
  // Display the Items as a menu to the user.
  cout << "----------------------------------------\n\n";

  cout << "ID#\n";
  cout << toString(vendingItem[1]) << "\n";
  cout << toString(vendingItem[2]) << "\n";
  cout << toString(vendingItem[3]) << "\n";
  cout << toString(vendingItem[4]) << "\n";
  cout << toString(vendingItem[5]) << "\n";
  cout << "\n 0 to exit";

  cout << "\n----------------------------------------\n";
  
  // Display a greeting to the user with intstructions on how to use 
  // the vending machine.
  cout << "|- Welcome Customer, Thankyou for choosing our vending machine!\n";
  cout << "|- This machine only accepts quarters and $1 bills\n";
  cout << "|- To purchase an item, enter the ID#\n";
  cout << "|- Then enter .25(quarter) or 1($1) until\n";
  cout << "|- Sufficient funds have been input.\n";
  cout << "|- Enter 0 to exit to vending machine\n\n";


  int itemChoice;
  float amountDue;
  float amountPaid;
  float totalSpent;

  while (itemChoice != 0) {

  cout << "ID#: ";
  cin >> itemChoice;
  amountDue = vendingItem[itemChoice].price;
  cout <<setprecision(2) << fixed << "Enter $" << vendingItem[itemChoice].price << "\n";
  while (amountDue != 0) {
    
    cin >> amountPaid; 
    amountDue = amountDue - amountPaid;
    cout << setprecision(2) << fixed <<  "Amount due: $" << amountDue << "\n\n";
    
  }

  totalSpent = totalSpent + vendingItem[itemChoice].price;
  cout << "\n----------------------------------------\n\n";
  cout << "|- Thankyou for purchasing " << vendingItem[itemChoice].name << "!\n\n";
  reduceQuantity(vendingItem[itemChoice],1);
  increaseQuantity(customerInventory[itemChoice],1);

  

  cout << "ID#\n";
  cout << toString(vendingItem[1]) << "\n";
  cout << toString(vendingItem[2]) << "\n";
  cout << toString(vendingItem[3]) << "\n";
  cout << toString(vendingItem[4]) << "\n";
  cout << toString(vendingItem[5]) << "\n";


  cout << "\n----------------------------------------\n";

  cout << "|- Enter an item ID# to purchase another item\n";
  cout << "|- Or enter 0 to exit.\n\n";
  
 if (itemChoice == 0) {

   cout << "\n----------------------------------------\n";

   cout << "Your purchased items:\n\n";
   cout << vendingItem[1].name << ": " << customerInventory[1].quantity << "\n";;
   cout << vendingItem[2].name << ": " << customerInventory[2].quantity << "\n";;
   cout << vendingItem[3].name << ": " << customerInventory[3].quantity << "\n";;
   cout << vendingItem[4].name << ": " << customerInventory[4].quantity << "\n";;
   cout << vendingItem[5].name << ": " << customerInventory[5].quantity << "\n";;
   
   cout << setprecision(2) << fixed << "Total spent: $" << totalSpent;

   cout << "\n----------------------------------------\n";

  break;
  }
 }
}
