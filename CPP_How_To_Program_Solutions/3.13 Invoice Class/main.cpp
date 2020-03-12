#include "invoice.h"
using namespace std;
int main(){

    invoice invoice("12","Chocolate Ulker",-1,-20);
    invoice.showInfo();
    invoice.setPartNumber();
    invoice.setPartDescription();
    invoice.setPrice();
    invoice.setQuantity();
    invoice.showInfo();
    cout << endl << endl;
    cout << "Part Number :" << invoice.getPartNumber() << endl;
    cout << "Part Description :" << invoice.getPartDesciption() << endl;
    cout << "Price :" << invoice.getPrice() << endl;
    cout << "Quantity :" << invoice.getQuantity() << endl;
    cout << "Sum of Price: " << invoice.sum() << endl;
    return 0;
}