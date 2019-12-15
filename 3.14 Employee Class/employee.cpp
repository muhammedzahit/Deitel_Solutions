/*
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
 */
#include "employee.h"
using namespace std;
string name;
int number;
Employee::Employee(std::string firstName, std::string lastName, int salary)
    : first_name(firstName),last_name(lastName),salary(salary)
{
    if (salary < 0){
        cout << "Fault: Salary must not be under 0! New salary is 0" << endl ;
        salary = 0;
    }
}
void Employee::setFirstName() {
    cout << "Enter First Name:";
    getline(cin,name);
    first_name = name;
}
string Employee::getFirstName() {
    return first_name;
}
void Employee::setLastName(){
    cout << "Enter Last Name:";
    getline(cin,name);
    last_name = name;
}
string Employee::getLastName(){
    return last_name;
}
void Employee::setSalary() {
    cout << "Enter new salary:";
    cin >> number;
    salary = number;
}
int Employee::getSalary() {
    return salary;
}
void Employee::yearlySalary() {
    cout << "Yearly Salary is : " << salary*12 << endl;
}
void Employee::raiseSalary() {
    cout << "Enter raising percent:";
    cin >> number;
    salary = (salary*(100+number))/100;
}