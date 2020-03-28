#include <iostream>
#include <fstream>
#include <cstdlib>
#include "inventory.h"
using namespace std;

void menu(){
    cout << "1- Make a empty template" << endl;
    cout << "2- Add some tools" << endl;
    cout << "3- Show specific tool" << endl;
    cout << "4- Show tools" << endl;
    cout << "9- Exit" << endl;
    cout << "? ";
}

int main(){
    Inventory envanter;
    int control=1,choice,given,quantity;
    std::string name;
    double cost;
    fstream inventory("C:\\Projects\\C++\\inventory.dat",ios::in|ios::out|ios::binary);
    while(control){
        menu();
        cin >> choice;
        switch (choice){
            case 1:{
                Inventory empty;
                ofstream newInventory("C:\\Projects\\C++\\inventory.dat",ios::out|ios::binary);
                for (int i=0; i<100; i++){
                    newInventory.write(reinterpret_cast<const char *>(&empty), sizeof(Inventory));
                }
                newInventory.close();
                break;
            }
            case 2: {
                if (!inventory.is_open()) cout << "You need create an empty template!!!" << endl;
                else{
                    cout << "Enter number of new tool :" << endl;
                    cin >> given;
                    inventory.seekp((given-1)* sizeof(Inventory));
                    inventory.read(reinterpret_cast<char *>(&envanter), sizeof(Inventory));
                    if (envanter.getRecNum() != 0){
                        cout << "There is already a tool at this number!!!" << endl;
                    }
                    else{
                        envanter.setRecNum(given);
                        cin.ignore();
                        cout << "Enter tool name : "; getline(cin,name);
                        envanter.setName(name);
                        cout << "Enter tool quantity :"; cin >> quantity;
                        envanter.setQuatity(quantity);
                        cout << "Enter sum cost :"; cin >> cost;
                        envanter.setCost(cost);
                        inventory.seekp((given-1)* sizeof(Inventory));
                        inventory.write(reinterpret_cast<const char *>(&envanter), sizeof(Inventory));
                        cout << "Tool registered successfully " << endl;
                    }
                    inventory.seekg(0);inventory.clear();
                }
                break;
            }
            case 3: {
                if (!inventory.is_open()) cout << "You need create an empty template!!!" << endl;
                else{
                    cout << "Enter number of searched tool :" << endl;
                    cin >> given;
                    inventory.seekp((given-1)* sizeof(Inventory));
                    inventory.read(reinterpret_cast<char *>(&envanter), sizeof(Inventory));
                    if (envanter.getRecNum() == 0){
                        cout << "There is not a tool at this number !!!" << endl;
                    }
                    else{
                        cout << envanter;
                    }
                    inventory.seekg(0);inventory.clear();
                }
                break;
            }
            case 4: {
                if (!inventory.is_open()) cout << "You need create an empty template!!!" << endl;
                else{
                    for (int i=0; i<100; i++){
                        inventory.read(reinterpret_cast<char *>(&envanter), sizeof(Inventory));
                        if (envanter.getRecNum() != 0 && !inventory.eof()){
                            cout << envanter;
                        }
                    }
                }
                inventory.seekg(0);inventory.clear();
                break;
            }
            case 9: {
                control = 0;
                break;
            }
        }
    }


    return 0;
}