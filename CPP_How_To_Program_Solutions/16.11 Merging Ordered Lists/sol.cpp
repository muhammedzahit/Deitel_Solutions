#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int main(){
	ostream_iterator<string> out(cout," ");
	vector<string> s1{"abc","adf","bfc"};
	vector<string> s2{"aac","bbb","ccc"};
	vector<string> merged;
	copy(s1.begin(),s1.end(),back_inserter(merged));
	copy(s2.begin(),s2.end(),back_inserter(merged));
	inplace_merge(merged.begin(),merged.begin()+s1.size(),merged.end());
	copy(merged.begin(),merged.end(),out);
	return 0;
}

