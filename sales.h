/*
 DEFINITITIONS - Sales Struct & Class
 */

#ifndef __SALES__
#define __SALES__

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdlib.h>

#include "product.h"

using namespace std;

struct sales_record {
    int product_id;
    int quantity;
    float cost;
};

class sales {
    vector<sales_record> allSales;
public:
    sales();
    
    //Saves all sales to file
    void save();
    
    //PRINTS SALES REPORT -- For item at index pdt
    sales_record prod_sales(int pdt);
    
    //Adds new sale to all sales vector and to sales file
    void newSale(sales_record newS);
};

#endif
