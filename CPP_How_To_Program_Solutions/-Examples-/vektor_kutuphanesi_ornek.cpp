#include <iostream>
using namespace std;
template <typename T>
class vector{
private:
    int cap,index;
    T* data;
    void reset(int size=0,int capacity=1){
        T* temp = new T[capacity];
        for (int i=0; i<size ; i++){
            temp[i] = data[i];
        }
        delete [] data;
        data = temp;
        index = size;
        cap = capacity;
    }
    void move(int loc=0/* den itibaren*/){
        push_back(at(index-1));
        for (int i=(index-2); i>=loc ; i--){
            at(i+1) = at(i);
        }
    }
    void remove(int loc=0){
        for (int i=loc+1 ; i<index ; i++){
            data[i-1] = data[i];
        }
    }
public:
    vector() : data(NULL), cap(1) , index(0){
        data = new T[cap];
    }
    vector(const vector<T>& r) : vector<T> ()  {
        *this = r;
    }
    vector(int n,const T& val = T()) : vector<T> () {
        for (int i = 0; i<n ;i++){
            push_back(val);
        }
    }
    ~vector(){
        delete []data;
    }
    int capacity() const{ return cap; }
    int size() const{return index;}
    void push_back(const T& a){
        if (index < cap){
            data[index++] = a;
        }
        else {
            cap *= 2;
            T* temp = new T[cap];
            for (int i=0; i<index; i++){
                temp[i] = data[i];
            }
            delete [] data;
            data = temp;
            data[index++] = a;
        }
    }
    void pop_back(){
        if (isEmpty()){
            throw invalid_argument("Vektorde eleman bulunmamaktadir!!!");
        }
        index--;
        if (index <= (cap/2)){
            if (cap == 1) {}
            else cap /= 2;
            T* temp = new T[cap];
            for (int i=0; i<index; i++){
                temp[i] = data[i];
            }
            delete [] data;
            data = temp;
        }
    }
    bool isEmpty() const{
        return index == 0;
    }
    T front() const{
        if (isEmpty()) {
            cout << "Vektorde eleman bulunmamaktadir.  ";
        }
        else return data[0];
    }
    T back() const{
        if (isEmpty()){
            cout << "Vektorde eleman bulunmamaktadir.  " ;
            return 0;
        }
        else return data[index-1];
    }
    T* begin() const{ return data ;}
    T* end() const{ return &data[index];}
    void print(){
        T* a = begin();
        while (a != end()){
            cout << *a << " ";
            a++;
        }
        cout << endl;
    }
    T& at(const T& a){
        if (a > -1 && a < index){
            return data[a];
        }
        else throw invalid_argument("Hata: Vektorde olmayan bir degere erismeye calistiniz!!!");
    }
    T& operator [](const T& a){
        return at(a);
    }
    void clear(){
        reset();
    }
    void insert(const T& loc,const T& val){
        if (loc > index) throw invalid_argument("Hata : Bulunmayan bir lokasyona atama yapilamaz!!!");
        move(loc);
        at(loc) = val;
    }
    void insert(const T* loc,const T& val){
        if (begin()<= loc && loc <= end()){
            int pos = loc - begin();
            insert(pos,val);
        }
        else throw invalid_argument("Hata : Bulunmayan bir lokasyona atama yapilamaz!!!");
    }
    void insert(const T* loc,int n,const T& val){
        int pos = loc - begin();
        insert(loc,val);
        for (int i=1; i<n; i++){
            insert(pos,val);
        }
    }
    void insert(const T* loc,const T* first,const T* last){
        const T* iter = last-1;
        int pos = loc - begin();
        while (iter >= first){
            insert(pos,*iter);
            iter--;
        }
    }
    void erase(int pos){
        remove(pos);
        pop_back();
    }
    void erase(const T* loc){
        if (begin()<= loc && loc <= end()){
            int pos = loc - begin();
            remove(pos);
            pop_back();
        }
    }
    void erase(const T* first,const T* second){
        if (begin() <= first && first <= end() && begin() <= second && second <= end()){
            int pos = first - begin();
            int n = second - first;
            for (int i=0; i<n ; i++){
                erase(pos);
            }
        }
        else throw invalid_argument ("Error : Vector Erase !");
    }
    void operator = (const vector &b){
        for (int i=0; i<b.size() ; i++){
            push_back(b.data[i]);
        }
    }
};

int main(){
    vector <int> a;
    a.push_back(12);
    a.push_back(13);
    vector <int> b = a;
    b.print();
    b.push_back(14);
    b.print();
    vector <int> c(5,5);
    c.print();
    vector <string> d(4);
}