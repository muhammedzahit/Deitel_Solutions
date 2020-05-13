// PALINDROME TESTER
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
using namespace std;
bool palindromeTester(string& s1){
	string s2 = s1;
	reverse_copy(s1.begin(),s1.end(),s2.begin());
	return s1 == s2;
}
int main(){
	string s1;
	getline(cin,s1);
	cout << "Palindrome result : ";
	if (palindromeTester(s1)){
		cout << "True";
	}
	else cout << "False";
	return 0;
}

