#include "employee.h"
using namespace std;
void demonstrate(Employee *employee){
    cout << "Name:          " << employee->getFirstName() << endl;
    cout << "Last Name:     " << employee->getLastName() << endl;
    cout << "Salary:        " << employee->getSalary() << endl << endl;
}
int main(){
    Employee personnel("Ahmed","Zahid",3000);
    Employee personnel2("Muhammed","Zahid",6000);
    demonstrate(&personnel);
    demonstrate(&personnel2);
    personnel.raiseSalary();
    personnel2.raiseSalary();
    demonstrate(&personnel);
    demonstrate(&personnel2);
}