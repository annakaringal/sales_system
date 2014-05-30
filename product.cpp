/*
 IMPLEMENTATION - Product Class
 */

#include "product.h"

using namespace std;

// GETTERS & SETTERS
string product::getName() { return name; }
void product::setName(string newName) { name = newName; }
void product::setName(ifstream& in){ in >> name; }

float product::getPrice() { return price; }
void product::setPrice(float newPrice) { price = newPrice; }
void product::setPrice(ifstream& in){ in >> price; }

int product::getTarget() { return inventory_target; }
void product::setTarget(int newTarget){ inventory_target = newTarget;}
void product::setTarget(ifstream& in){ in >> inventory_target; }

int product::getQty(){ return inventory_quantity; }
void product::setQty(int newQty){ inventory_quantity = newQty; }
void product::setQty(ifstream& in){ in >> inventory_quantity; }

// Compares quantity to inventory target
int product::status(){
    if (inventory_quantity < (inventory_target * .5)){
        return -1; //Returns -1 if quantity is <50% of target
    }
    else if (inventory_quantity > (inventory_target * 1.5)){
        return 1; //Returns 1 if quantity is >150% of target
    }
    else {return 0;} //Returns 0 otherwise
}

// DISPLAYS CATALOG -- Client Side
void product::display_client(){
    cout << name << endl;
    cout << "PRICE: $" ;
    cout << fixed << setprecision(2) << price << endl;
    cout << "QTY IN STOCK: " << inventory_quantity << endl;
}

// DISPLAYS CATALOG -- Business Side
void product::display_full(){
    cout << "PRODUCT: " << name << endl;
    cout << "PRICE: $" ;
    cout << fixed << setprecision(2) << price << endl;
    cout << "INVENTORY TARGET: " << inventory_target << endl;
    cout << "QUANTITY: " << inventory_quantity << endl;
    
}