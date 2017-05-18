#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare( const pair<int,int> &a ,const pair<int,int> &b ){
	return a.second <= b.second;
}

int main(){

	int a,i;
	std::vector< pair<int,int> > v;

	v.push_back(make_pair(1,10));
	v.push_back(make_pair(5,3));
	v.push_back(make_pair(8,8));

	sort(v.begin(),v.end(),compare);

	for(i=0;i<v.size();i++)
		cout << v[i].first << ' ' << v[i].second << endl;

return 0;
}