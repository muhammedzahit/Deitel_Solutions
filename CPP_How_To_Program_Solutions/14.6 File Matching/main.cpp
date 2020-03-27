#include <iostream>
#include <fstream>
#include <cstdlib>
#include "transaction.h"
#include "clientdata.h"
using namespace std;

void menu(){
    cout << endl;
    cout << "1- Musteri ekle" << endl;
    cout << "2- Musteri goster" << endl;
    cout << "3- islem yap" << endl;
    cout << "4- islem goruntule" << endl;
    cout << "5- Tum bilgileri bir dosya icine yaz" << endl;
    cout << "6- Listeyi sifirla" << endl;
    cout << "9- Programdan cik " << endl;
    cout << "Seciminiz ? ";
}

int main(){
    fstream islemler("islemler.txt",ios::in|ios::out|ios::binary);
    fstream musteriler("kayitlar.txt",ios::in|ios::out|ios::binary);
    if (!islemler || !musteriler){
        cout << "Dosyalar acilamadi!!!" ;
        exit(EXIT_FAILURE);
    }
    Transaction t;
    ClientData m;
    int control = 1, secim;
    while(control){
        menu();
        cin >> secim;
        switch (secim){
            case 1:{
                int num;
                string ad,soyad;
                double bakiye;
                cout << "Eklemek istediginiz musteri numarasini giriniz(1-100) : ";
                cin >> num;
                musteriler.seekp((num-1)* sizeof(ClientData));
                musteriler.read(reinterpret_cast<char *>(&m), sizeof(ClientData));
                if (m.getAccountNumber() != 0) cout << "Bu numarada bir musteri var!!!" << endl;
                else{
                    m.setAccountNumber(num);
                    cout << "Ad giriniz : ";
                    cin >> ad;
                    m.setFirstName(ad);
                    cout << "Soyad giriniz : ";
                    cin >> soyad;
                    m.setLastName(soyad);
                    cout << "Bakiye giriniz :";
                    cin >> bakiye;
                    m.setBalance(bakiye);
                }
                musteriler.seekp((num-1)* sizeof(ClientData));
                musteriler.write(reinterpret_cast<const char *>(&m), sizeof(ClientData));
                musteriler.seekg(0);musteriler.clear();
                break;
            }
            case 2:{
                int num;
                cout << "Gormek istediginiz musterinin numarasini giriniz : ";
                cin >> num;
                musteriler.seekp((num-1)* sizeof(ClientData));
                musteriler.read(reinterpret_cast<char *>(&m), sizeof(ClientData));
                if (m.getAccountNumber() == 0) cout << "Bu numarada bir musteri yok!!!" << endl;
                else{
                    cout << m;
                }
                musteriler.seekg(0);musteriler.clear();
                break;
            }
            case 3:{
                int num;
                cout << "islem yapilacak musterinin numarasini giriniz : ";
                cin >> num;
                musteriler.seekp((num-1)* sizeof(ClientData));
                musteriler.read(reinterpret_cast<char *>(&m), sizeof(ClientData));
                if (m.getAccountNumber() == 0) cout << "Bu numarada bir musteri yok!!!" << endl;
                else{
                    cout << "Bakiye : " << m.getBalance() << endl;
                    cout << "1-Para cek" << endl;
                    cout << "2-Para yatir" << endl;
                    int yapilacak;
                    double para = 0;
                    cout << "? "; cin >> yapilacak;
                    switch(yapilacak){
                        case 1:
                            cout << "Cekilecek miktari giriniz :";
                            cin >> para;
                            m.setBalance(m.getBalance()-para);
                            break;
                        case 2:
                            cout << "Yatirilacak miktari giriniz :";
                            cin >> para;
                            m.setBalance(m.getBalance()+para);
                            break;
                    }
                    cout << "isleminiz basariyla tamamlanmistir." << endl;
                    islemler.seekp((num-1)* sizeof(Transaction));
                    islemler.read(reinterpret_cast<char *>(&t), sizeof(Transaction));
                    if (t.getNum() == 0) t.setNum(num);
                    string eklenecek;
                    if (yapilacak == 1) eklenecek = "Musteri " + to_string(para) + "TL cekti.";
                    else eklenecek = "Musteri " + to_string(para) + "TL yatirdi.";
                    t.islemEkle(eklenecek);
                    islemler.seekg(0);islemler.clear();
                    islemler.seekp((num-1)* sizeof(Transaction));
                    islemler.write(reinterpret_cast<const char *>(&t), sizeof(Transaction));
                }
                musteriler.seekg(0);musteriler.clear();
                musteriler.seekp((num-1)* sizeof(ClientData));
                musteriler.write(reinterpret_cast<const char *>(&m), sizeof(ClientData));
                musteriler.seekg(0);musteriler.clear();
                islemler.seekg(0);islemler.clear();
                break;
            }
            case 4:{
                int num;
                cout << "islemleri goruntulenecek musterinin numarasini giriniz : ";
                cin >> num;
                islemler.seekp((num-1)* sizeof(Transaction));
                islemler.read(reinterpret_cast<char *>(&t), sizeof(Transaction));
                if (t.getNum() == 0) cout << "Boyle bir musteri yok ya da islem kaydi bulunmuyor." << endl;
                else{
                    cout << t.islemler << endl;
                }
                islemler.seekg(0);islemler.clear();
                break;
            }
            case 5:{
                ofstream genel("genel.txt",ios::out);
                for (int i=0 ; i<100 ; i++){
                    musteriler.read(reinterpret_cast<char *>(&m), sizeof(ClientData));
                    islemler.read(reinterpret_cast<char *>(&t), sizeof(Transaction));
                    if (m.getAccountNumber() != 0){
                        genel << m;
                        if (t.getNum() != 0){
                            genel << endl << "islemler :" << endl;
                            genel << t.islemler << endl;
                        }
                        genel << endl;
                    }
                }
                cout  << "Yazdirma islemi basariyla tamamlandi " << endl;
                genel.close();
                musteriler.seekg(0);musteriler.clear();
                islemler.seekg(0);islemler.clear();
                break;
            }
            case 6:{
                ClientData newData;
                Transaction newTransaction;
                for (int i=0; i<100; i++){
                    musteriler.write(reinterpret_cast<const char *>(&newData), sizeof(ClientData));
                    islemler.write(reinterpret_cast<const char *>(&newTransaction), sizeof(Transaction));
                }
                musteriler.seekg(0);musteriler.clear();
                islemler.seekg(0);islemler.clear();
                break;
            }
            case 9:
                control = 0;
        }
    }
    return 0;
}