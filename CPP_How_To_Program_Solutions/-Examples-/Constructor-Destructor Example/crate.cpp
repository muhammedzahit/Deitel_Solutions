#include <iostream>
#include "crate.h"
using namespace std;
staff::staff(int newID,string newName)
     : ObjectID(newID) , name(newName)
{
    cout << "Object " << ObjectID << "  constuctors runs    " << name << endl;
} 
staff::~staff()
{
    cout << (ObjectID == 1 || ObjectID == 6 ? "\n" : "") ;
    cout << "Object " << ObjectID << "  destructors runs    " << name << endl;
}
