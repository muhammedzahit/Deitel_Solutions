#ifndef INTEGER_HPP
#define INTEGER_HPP

class IntegerSet{
public:
    IntegerSet();
    IntegerSet(int dizi[],int);
    void put(int);
    void deleteNum(int);
    bool getNumber(int);
    IntegerSet UnionofSets(IntegerSet&,IntegerSet&);
    IntegerSet IntersectionOfSets(IntegerSet&,IntegerSet&);
    void printList();
    bool isEqual(IntegerSet&,IntegerSet&);
private:
    bool a[101];
};

#endif 
