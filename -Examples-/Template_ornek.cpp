#include <iostream>
using namespace std;

template <class T>
class veriler {
private:
    T* datas;
    int index;
public:
    veriler() : index(1) {}
    ~veriler() {
        delete[] datas;
    }
    void elemanEkle(T eleman) {
        if (index == 1) {
            datas = (T*) malloc(sizeof(T)*1);
            datas[index-1] = eleman;
            index++;
        }
        else {
            datas = (T*)(realloc(datas, sizeof(T) * index));
            datas[index-1] = eleman;
            index++;
        }
    }
    void elemanYazdir()const {
        for (int i = 0; i < index-1; i++) {
            cout << datas[i] << endl;
        }
    }
    void elemanSil() {
        if (index == 0) {
            cout << "Silinebilecek bir eleman yok" << endl;
        }
        else {
            index--;
            datas = (T*)(realloc(datas, sizeof(T) * index));
        }

    }
};

int main() {

    veriler<int> veriler1;
    veriler1.elemanEkle(12);
    veriler1.elemanEkle(13);
    veriler1.elemanEkle(14);
    veriler1.elemanYazdir();
    cout << endl << endl;
    veriler1.elemanSil();
    veriler1.elemanYazdir();

    cout << endl << endl;

    veriler<double> veriler2;
    veriler2.elemanEkle(12.2);
    veriler2.elemanEkle(13.3);
    veriler2.elemanYazdir();
    veriler2.elemanSil();
    cout << endl <<endl;
    veriler2.elemanYazdir();
    veriler2.elemanSil();
    veriler2.elemanSil();
    return 0;
}