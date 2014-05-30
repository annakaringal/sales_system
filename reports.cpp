/* Title: REPORTS PROGRAM
 Author: Anna Cristina Karingal
 Description: Generates sales and inventory reports for employees
 Last Revised: May 22, 2014
 */

#include <iostream>
#include <string>
#include <iomanip>

#include "product.h"
#include "inventory.h"
#include "sales.h"

using namespace std;

void employee_menu();

int main(){
    
    //Reads inventory from file
    inventory inv;
    inv.load("items.txt");
    
    //Reads sales from file
    sales s;
    
    int cmd;
    
    do {
        
        employee_menu();
        cin >> cmd; //Gets menu choice from user
        
        // MENU OPT 1 - Displays list of under/overstocked items
        if (cmd == 1) {
            inv.status();
        }
        
        // MENU OPT 2 - Prompts user for product ID and displays total sales for product
        else if (cmd == 2) { //
            int pid;
            
            do {
                cout << "Enter Product ID: ";
                cin >> pid;
                
                //In case user types in invalid product ID
                if (pid > inv.getSize() || pid < 0){
                    cout << "ERROR: Product does not exist" << endl;
                }
                //Successful product ID entry
                else {
                    sales_record pSales = s.prod_sales(pid);
                    cout << " ----------------------------" << endl;
                    cout << "TOTAL " << inv.getProd(pid).getName() << " SALES:" << endl;
                    cout << "Total Qty Sold: " << pSales.quantity << endl;
                    cout << "Total Revenue: $" ;
                    cout << fixed << setprecision(2) << pSales.cost << endl;
                    
                    break; //breaks loop
                }
                
            } while (!cin.fail() or pid > inv.getSize());
            
        }
        
        else {
            if (cmd!=3) {
                cout << "ERROR: Invalid menu choice. Please try again." << endl;
            }
            else { }
        }
        
        
    } while (cmd!=3);
    
    if (cmd == 3) {
        cout << "Thank you. GOODBYE. " << endl;
    }
    
    
    return 0;
}


//Prints menu choices
void employee_menu(){
    cout << endl ;
    cout << "=====EMPLOYEE MENU===========" << endl;
    cout << "Choose a menu option by typing the corresponding number." << endl;
    cout << " ----------------------------" << endl;
    cout << "1 -- View a list of understocked or overstocked items" << endl;
    cout << "2 -- View sales for an item." << endl;
    cout << "3 -- Exit" << endl << endl;
    cout << "MENU OPTION: " ;
    
}