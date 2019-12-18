#include <iostream>
using namespace std;
int main(){
    int a[6]={1,2,3,4,5,6};
    int *aPtr = &a[2];
    for (int s: a){
        cout << s <<" ";
    }
    cout << endl;
    for (int s=0; s<6; s++){
        cout << *(a + s) << " ";
    }
    cout << endl;
    for (int s=0; s<4 ; s++){
        cout << aPtr[s] << " ";
    }
    cout << endl;
    for (int s=0; s<4; s++){
        cout << *(aPtr) << " ";
        aPtr++;
    }
    return 0;
}