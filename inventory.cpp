/*
 IMPLEMENTATION - Inventory Class
 */

#include "inventory.h"
#include "product.h"
#include "sales.h"

using namespace std;

// READS INVENTORY
void inventory::load (string fname){
    // Open inventory file
    ifstream readf;
    readf.open(fname.c_str());
    
    // In case cannot open file
    if (readf.fail()) {
        cout << "ERROR: Could not open " << fname << " file." << endl;
        exit(-1);
    }
    
    if (readf.is_open()) {
        product input;
        
        while (!readf.eof()){
            // Creates new product instance and populates from file
            input.setName(readf);
            input.setPrice(readf);
            input.setTarget(readf);
            input.setQty(readf);
        
            // Saves new product instance to items vector
            items.push_back(input);
        }
    }
    
    readf.close(); // Closes file
}

//SAVE INVENTORY
void inventory::save (string fname){
    //Open file
    ofstream savef;
    savef.open(fname.c_str());
    
    // In case cannot open file
    if (savef.fail()){
        cout << "ERROR: Could not open " << fname << " file." << endl;
        exit(-1);
    }
    
    if (savef.is_open()){
        // Writes each product variable as new line in file
        for (int i=0; i<(items.size()-1); i++) {
            savef << items[i].getName() << endl;
            savef << items[i].getPrice() << endl;
            savef << items[i].getTarget() << endl;
            savef << items[i].getQty() << endl;
        }
        for (int i=items.size()-1; i<items.size(); i++) {
            savef << items[i].getName() << endl;
            savef << items[i].getPrice() << endl;
            savef << items[i].getTarget() << endl;
            savef << items[i].getQty() ; //So new linebreak doesn't get written at end of file
        }
    }
    
    savef.close(); // Closes file
}

//SALE IS MADE -- updates inventory with new qty
//             -- updates sales record with new sale
void inventory::sell (int pdt, int qty, sales &s){
    
    sales_record newS;
    
    newS.product_id = pdt;
    newS.quantity = qty;
    newS.cost = items[pdt].getPrice() * qty;    
    
    //Checks if there is enough inventory in stock to make sale
    if (items[pdt].getQty() < qty){
        cout << endl << "ERROR: Sale not made. Insufficient inventory." << endl << endl;
    }
    
    else if (items[pdt].getQty() >= qty) {
        //Deducts sale quantity from inventory quantity
        int newQty = items[pdt].getQty() - qty;
        items[pdt].setQty(newQty);
        
        save("items.txt"); // Saves updated inventory file.
        
        //Appends sales record with new sale
        s.newSale(newS);
        
        cout << endl << "TRANSACTION COMPLETE." << endl;
        cout << "You have just purchased " << qty << " " << items[pdt].getName() << "s for a total of $";
        cout << fixed << setprecision(2) << newS.cost << "." << endl;
        cout << "Thank you for your purchase!" << endl;
    }
}

//PRINTS CATALOG -- for customer
void inventory::display_client(){
    
    for (int i=0; i<items.size(); i++) {
        cout << "Product # " << i << " -- " ;
        items[i].display_client();
        cout << "==========================" << endl;
    }
    
}

//PRINTS STOCK REPORT -- overstocked and understocked items
void inventory::status(){
    
    vector<product> over;
    vector<product> under;
    
    for (int i=0; i<items.size(); i++) {
        if (items[i].status() == -1){
            //if product is understocked, add to list of understocked items
            under.push_back(items[i]);
        }
        else if (items[i].status() == 1){
            //if product is overstocked, add to list of overstocked items
            over.push_back(items[i]);
        }
        else{}
    }
    
    cout << endl << "=== OVERSTOCKED ITEMS ================" << endl;
    
    //Prints out list of overstocked items
    for (int i=0; i<over.size(); i++) {
        cout << over[i].getName() << endl;
        cout << "Qty: " << over[i].getQty() << " | Target: " << over[i].getTarget() << " | Surplus: " << over[i].getQty()-over[i].getTarget() << endl;
    }

    cout << endl << "=== UNDERSTOCKED ITEMS ================" << endl;
    
    //Prints out list of understocked items
    for (int i=0; i<under.size(); i++) {
        cout << under[i].getName() << endl;
        cout << "Qty: " << under[i].getQty() << " | Target: " << under[i].getTarget() << " | Deficit: " << over[i].getTarget()-over[i].getQty() << endl;
    }
}

product inventory::getProd(int pdt){
    product p = items[pdt];
    return p;
}

int inventory::getSize(){
    return items.size();
}