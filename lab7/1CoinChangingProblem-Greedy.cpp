#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n,i,z,x;

	cout << "This works only if - for all available coins i , value of coin i is atleast 2 times greater than value of coin i-1\n\n" ; 

	std::vector< pair<int,int> > ans;
	cout << "enter the number of coins that you have" <<  endl;
	cin >> z;
	std::vector<int> coins(z);
	cout << "enter the value of coins" <<  endl;
	for(i=0;i<z;i++){
		cin >> coins[i];
	}

	cout << "enter the amount" << endl;
	cin >> n;

	sort(coins.begin(),coins.end());
	reverse(coins.begin(),coins.end());

	for(i=0;i<coins.size();i++){

		int div=n/coins[i];
		ans.push_back(make_pair(coins[i],div));

		n%=coins[i];
		if(n==0)
			break;
	}

	for(i=0;i<ans.size();i++){
		cout << ans[i].first << " * " << ans[i].second << endl;
	}


return 0;
}