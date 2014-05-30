/*
 DEFINITIONS - Inventory Class
 */

#ifndef __INVENTORY__
#define __INVENTORY__

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

#include "product.h"
#include "sales.h"
using namespace std;

class inventory {
    vector <product> items;
    
public:
    void load (string fname);
    void save (string fname);
        
    //SALE IS MADE -- updates inventory with new qty
    //             -- updates sales record with new sale
    void sell (int pdt, int qty, sales &s);
    
    //PRINTS CATALOG -- for customer
    void display_client();
    
    //PRINTS STOCK REPORT -- overstocked and understocked items
    void status();
    
    //PRINTS SALES REPORT FOR ITEM (product_id pdt)
    void salesrep(int pdt);
    
    //RETURNS PRODUCT with product_id pdt
    product getProd(int pdt);
    
    //RETURNS number of items in inventory
    int getSize();
    
};


#endif
