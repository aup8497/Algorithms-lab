#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

	int n,i;
	cout << "enter n" <<  endl;
	cin >> n;

	int p[n],d[n];
	std::vector< pair<int,int> > v;

	cout << "enter deadlines\n" ;
	for(i=0;i<n;i++){
		cin >> d[i];
	}
	cout << "enter profits\n" ;
	for(i=0;i<n;i++){
		cin >> p[i];
	}

	for(i=0;i<n;i++){
		v.push_back(make_pair(d[i],p[i]));
	}

	sort(v.begin(), v.end());

	reverse(v.begin(), v.end());


	for(i=0;i<n;i++)
		cout << v[i].first << ' ' << v[i].second << endl;
	
return 0;	
}