/*
DEFINITIONS - Product Class
 */

#ifndef __PRODUCT__
#define __PRODUCT__

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class product{
    
    string name;
    float price;
    int inventory_target;
    int inventory_quantity;
    
public:
    
    // GETTERS & SETTERS for private variables
    string getName();
    void setName(string newName);
    void setName(ifstream& in);
    
    float getPrice();
    void setPrice(float newPrice);
    void setPrice(ifstream& in);
    
    int getTarget();
    void setTarget(int newTarget);
    void setTarget(ifstream& in);

    int getQty();
    void setQty(int newQty);
    void setQty(ifstream& in);
    
    // Returns -1 if inventory level is <50% of target
    // Returns 1 if >150% of target
    // Returns 0 otherwise
    int status();
    
    // Displays name, price and quantity to customer
    void display_client();
    
    //Displays more detail for business side, also displays inventory target
    void display_full();
};



#endif
