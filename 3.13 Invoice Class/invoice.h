#include <iostream>
#include <string>
class invoice{
public:
    explicit invoice(std::string part_number,std::string part_description,int price,int quantity);
    void setPartNumber();
    std::string getPartNumber();
    void setPartDescription();
    std::string getPartDesciption();
    void setPrice();
    int getPrice();
    void setQuantity();
    int getQuantity();
    void showInfo();
    int sum();
private:
    int price,quantity;
    std::string part_num,part_description;
};