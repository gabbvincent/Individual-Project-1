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

 double usersWallet = 25.00;
  
  // Initialize Items to store in the vending machine.
  Item chips;

  initItem(chips, "Chips", 1.75, 10);

  Item candyBar;
  initItem(candyBar, "Candy bar", 1.5, 10);

  Item fruitSnacks;
  initItem(fruitSnacks, "Fruit snacks", 1.0, 10);

  Item water;
  initItem(water, "Water", 1.0, 10);

  Item gatorade;
  initItem(gatorade, "Gatorade", 1.5, 10);

  // Display the Items as a menu to the user.
  cout << "----------------------------------------\n\n";

  cout << "ID#\n";
  cout << "1.) " << toString(chips) << "\n";
  cout << "2.) " << toString(candyBar) << "\n";
  cout << "3.) " << toString(fruitSnacks) << "\n";
  cout << "4.) " << toString(water) << "\n";
  cout << "5.) " << toString(gatorade) << "\n\n";

  cout << "----------------------------------------\n";
  
  // Display a greeting to the user with intstructions on how to use // the vending machine and their current $balance.
  cout << "|- Welcome Customer, Thankyou for choosing our vending machine!\n";

  cout << "|- You currently have $25.00.\n";
  cout << "|- To purchase an item, enter the ID#\n";
  cout << "|- Enter 0 to exit to vending machine\n";

  int userInput;

  while (userInput != 0) {

    cin >> userInput;

    if (userInput == 0) {

      break;
    }else{

    

    }


  }

 









}











}
