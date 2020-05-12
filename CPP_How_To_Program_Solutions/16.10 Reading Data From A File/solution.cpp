// 16.10 Reading Data From A File
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    ifstream file;
    file.open("anything.txt");
    vector<int> a;
    istream_iterator<int> iter(file);
    ostream_iterator<int> out(cout," ");
    copy(iter,istream_iterator<int>(),back_inserter(a));
    copy(a.begin(),a.end(),out);
    return 0;
}