#include <iostream>
#include <string>
#include "date.h"
#include "employee.h"
info::info(std::string n_name,std::string n_lastname,date n_birth)
    : name(n_name) , lastname(n_lastname) , birth(n_birth)
{}
void info::printInfo(){
    std::cout << "Name:" << name << std::endl;
    std::cout << "Last Name:" << lastname << std::endl;
    std::cout << "Birth Date:" << birth.getDay() << std::endl; 
}
