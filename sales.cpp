/*
 IMPLEMENTATION - Sales Class
 */


#include "sales.h"

//Automatically populates vector with data from sales file
sales::sales(){
    //opens sales file
    ifstream salesf;
    salesf.open("sales.txt");
    
    // In case cannot open file
    if (salesf.fail()){
        cout << "ERROR: Could not open sales file." << endl;
        exit(-1);
    }
    
    if (salesf.is_open()){
        while (!salesf.eof()){
            
            //Create new sales_record instance and populate from file
            sales_record input;
            salesf >> input.product_id;
            salesf >> input.quantity;
            salesf >> input.cost;
            
            // Saves new sales_record instance to all sales vector
            allSales.push_back(input);
        }
    }
    
    salesf.close();
}

//Saves sales to file
void sales::save() {
    ofstream salesf;
    salesf.open("sales.txt");
    
    // In case cannot open file
    if (salesf.fail()){
        cout << "ERROR: Could not open sales file." << endl;
        exit(-1);
    }
    
    
    if (salesf.is_open()){
        // Writes each sales_record variable as new line in file
        for (int i=0; i<(allSales.size()-1); i++) {
            salesf << allSales[i].product_id << endl;
            salesf << allSales[i].quantity << endl;
            salesf << allSales[i].cost << endl;
        }
        for (int i=allSales.size()-1; i<allSales.size(); i++){
            salesf << allSales[i].product_id << endl;
            salesf << allSales[i].quantity << endl;
            salesf << allSales[i].cost; //So new linebreak doesn't get written at end of file
        }
    }
    
    salesf.close(); // Closes file
}

//PRINTS SALES REPORT -- For item at index pdt
sales_record sales::prod_sales(int pdt){
    
    sales_record pSales;
    pSales.product_id = pdt;
    pSales.cost = 0;
    pSales.quantity = 0;
    
    //Loops through all sales and totals quantity & cost of all sales of item
    for (int i=0; i<allSales.size(); i++) {
        if (allSales[i].product_id == pdt){
            pSales.quantity += allSales[i].quantity;
            pSales.cost += allSales[i].cost;
        }
    }
    
    return pSales;
}

void sales::newSale(sales_record newS){
    allSales.push_back(newS); //adds new sales_record to all sales vector
    save();
}
