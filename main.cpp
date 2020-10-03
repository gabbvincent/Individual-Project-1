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

  // Create an Item struct with an ID#, name, price, and quantity attribute.
  struct Item {

  int ID;
  string name;
  double price;
  unsigned int quantity;
 };

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

  // Create an object array of Items to represent items in the 
  // vending machine.
  Item vendingItem[7];
  vendingItem[0] = { 0, "exit", 0, 100};
  vendingItem[1] = { 1, "Chips", 1.75, 10};
  vendingItem[2] = { 2, "Candy bar", 1.50, 10};
  vendingItem[3] = { 3, "Fruit snacks", 1.00, 10};
  vendingItem[4] = { 4, "Water", 1.00, 10};
  vendingItem[5] = { 5, "Gatorade", 1.50, 10};
  vendingItem[6] = { 6, "Energy drink", 2.00, 10};

  // Create an object array of Items to represent the customers
  // inventory.
  Item customerInventory[7];
  customerInventory[1] = { 1, "Chips", 1.75, 0};
  customerInventory[2] = { 2, "Candy bar", 1.50, 0};
  customerInventory[3] = { 3, "Fruit snacks", 1.00, 0};
  customerInventory[4] = { 4, "Water", 1.00, 0};
  customerInventory[5] = { 5, "Gatorade", 1.50, 0};
  customerInventory[6] = { 6, "Energy drink", 2.00, 0};

  // Display the vending machin Items as a menu to the user.
  cout << "----------------------------------------\n\n";

  cout << "ID#\n";
  cout << toString(vendingItem[1]) << "\n";
  cout << toString(vendingItem[2]) << "\n";
  cout << toString(vendingItem[3]) << "\n";
  cout << toString(vendingItem[4]) << "\n";
  cout << toString(vendingItem[5]) << "\n";
  cout << toString(vendingItem[6]) << "\n";
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

  // Declare variables for user's itemChoice, amountDue, amountPaid,
  // and totalSpent.
  int itemChoice;
  float amountDue;
  float amountPaid;
  float totalSpent = 0;

  // Start a loop that asks the user what item they would like to 
  // purchase until the user's itemChoice = 0.
  while (itemChoice != 0) {

  cout << "ID#: ";
  cin >> itemChoice;

  // If the item chosen's quantity is 0 then tell the user it's sold 
  // out.
  if (vendingItem[itemChoice].quantity == 0) {

  cout << "\n|- Sold Out -|\n\n";
  continue;
  }

  amountDue = vendingItem[itemChoice].price;
  cout <<setprecision(2) << fixed << "Enter $" << vendingItem[itemChoice].price << "\n";

  // Display the amount of $ due and scan for amountPaid until the 
  // amountDue = 0
  while (amountDue != 0) {
    
  cin >> amountPaid; 
  amountDue = amountDue - amountPaid;
  cout << setprecision(2) << fixed <<  "Amount due: $" << amountDue << "\n\n";
  }

  // When the amountDue = 0 tell the user what item they purchased
  // and display the menu so that the user can purchase another item 
  // or exit the vending machine.
  if (itemChoice != 0){

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
  cout << toString(vendingItem[6]) << "\n";

  cout << "\n----------------------------------------\n";

  cout << "|- Enter an item ID# to purchase another item\n";
  cout << "|- Or enter 0 to exit.\n\n";
  }

  // If the itemChoice = 0 then exit the vendingmachine and display
  // the items the user purchased and the total amount of $ spent.
  else if (itemChoice == 0) {

  cout << "----------------------------------------\n\n";

  cout << "Your purchased items:\n\n";
  cout << vendingItem[1].name << ": " << customerInventory[1].quantity << "\n";
  cout << vendingItem[2].name << ": " << customerInventory[2].quantity << "\n";
  cout << vendingItem[3].name << ": " << customerInventory[3].quantity << "\n";
  cout << vendingItem[4].name << ": " << customerInventory[4].quantity << "\n";
  cout << vendingItem[5].name << ": " << customerInventory[5].quantity << "\n";
  cout << vendingItem[6].name << ": " << customerInventory[6].quantity << "\n";

  cout << "______________________\n\n";
   
  cout << setprecision(2) << fixed << "Total spent: $" << totalSpent;

  cout << "\n\n----------------------------------------\n";

  break;
  }
 }
}
