#include <iostream>
#include <string>
class Employee{
private:
    std::string first_name;
    std::string last_name;
    int salary;
public:
    explicit Employee(std::string name1,std::string name2,int salary);
    void setFirstName();
    std::string getFirstName();
    void setLastName();
    std::string getLastName();
    void setSalary();
    int getSalary();
    void yearlySalary();
    void raiseSalary();
};