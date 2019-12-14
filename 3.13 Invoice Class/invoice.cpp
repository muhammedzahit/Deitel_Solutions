#include "invoice.h"
using namespace std;
invoice::invoice(std::string part_number, std::string part_description, int price, int quantity)
    : part_num(part_number),part_description(part_description),price(price),quantity(quantity)
{
    if (price < 0){
        cout << "Fault: Price under the 0 , new price is 0 ! " << endl;
        price = 0;
    }
    if (quantity < 0){
        cout << "Fault: Quantity under the 0, new quantity is 0 !" << endl;
        quantity = 0;
    }
}
void invoice::setPartNumber() {
    string a;
    cout << "Enter new part Number : ";
    getline(cin,a);
    part_num = a;
}
string invoice::getPartNumber() {
    return part_num;
}
void invoice::setPartDescription() {
    string a;
    cout << "Enter new part Number : ";
    getline(cin,a);
    part_description = a;
}
string invoice::getPartDesciption() {
    return part_description;
}
void invoice::setPrice() {
    int b;
    cout << "Enter new price :";
    cin >> b;
    if (b < 0) {
        cout << "Must be positive try again!" << endl;
        invoice::setPrice();
    }
    else{
        price = b;
    }
}
int invoice::getPrice() {
    return price;
}
void invoice::setQuantity() {
    int b;
    cout << "Enter new price :";
    cin >> b;
    if (b < 0) {
        cout << "Must be positive try again!" << endl;
        invoice::setPrice();
    }
    else{
        quantity = b;
    }
}
int invoice::getQuantity() {
    return quantity;
}
void invoice::showInfo() {
    cout << "Part Number :" << part_num << endl;
    cout << "Part Description : " << part_description << endl;
    cout << "Price : " << price << endl;
    cout << "Quantity : " << quantity << endl;
}
int invoice::sum() {
    return quantity*price;
}