/* Title: CLIENT PROGRAM
 Author: Anna Cristina Karingal
 Description: Allows client to view list of products and make a purchase
 Last Revised: May 22, 2014
 */

#include <iostream>
#include <string>

#include "product.h"
#include "inventory.h"
#include "sales.h"

using namespace std;

void client_menu();

int main(){
    
    //Reads inventory from file
    inventory inv;
    inv.load("items.txt");
    
    //Reads sales from file
    sales s;
    
    int cmd;
    
    do {
        
        client_menu();
        cin >> cmd; //Gets menu choice from user
        
        if (cmd == 1) {
            inv.display_client(); //Displays full inventory for client
        }
        
        else if (cmd == 2) {
            int pid, qty;
            cout << "Please enter the product number: " ;
            cin >> pid;
            
            //In case user types in invalid product ID
            if (pid > inv.getSize() || pid < 0){
                cout << "ERROR: Product does not exist" << endl << endl;
            }
            //Successful product ID entry
            else {
                cout << "Please enter quantity: " ;
                cin >> qty;
                
                inv.sell (pid,qty,s); //Records sale in inventory & sales log
            }
        }
        
        else {
            if (cmd!=3){
                cout << "ERROR: Invalid menu choice. Please try again." << endl;
            }
            else { break; }
        }
        
    } while (cmd!= 3);
    
    if (cmd ==3) {
        cout << "Thank you. GOODBYE. " << endl;
    }
    
    
    return 0;
}

//Prints menu choices
void client_menu(){
    cout << endl ;
    cout << "=====CUSTOMER MENU===========" << endl;
    cout << "Choose a menu option by typing the corresponding number." << endl;
    cout << " ----------------------------" << endl;
    cout << "1 -- Print Catalog." << endl;
    cout << "2 -- Place Order." << endl;
    cout << "3 -- Exit" << endl << endl;
    cout << "MENU OPTION: " ;
}