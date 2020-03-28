#ifndef C___INVENTORY_H
#define C___INVENTORY_H

#include <iostream>
#include <string>

class Inventory {
private:
    int recNum;
    char name[30];
    int quantity;
    double cost;
public:
    Inventory(int=0,std::string= " ",int=0,double=0.0);
    void setRecNum(const int&);
    void setName(std::string const&);
    void setQuatity(const int&);
    void setCost(const double&);
    int getRecNum() const;
    std::string getName() const;
    int getQuantity() const;
    double getCost() const;
    friend std::ostream& operator<<(std::ostream&,Inventory&);
};


#endif
