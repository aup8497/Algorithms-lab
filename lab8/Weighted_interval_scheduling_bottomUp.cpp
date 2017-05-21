// this is the bottom up approach for the weighted interval scheduling problem
// completed successfully
 #include <bits/stdc++.h>
using namespace std;

std::vector< pair<int, pair<int,int> > > v;
int prev[1000];
int memo[1000];

int optimal(int n){
	int result;
	memo[0]=0;
	for (int i = 1; i <= n; ++i)
	{
		memo[i]=max( memo[i-1], v[i-1].second.second + memo[prev[i-1]+1] );
		// cout << memo[i-1] << " " << v[i-1].second.second << "+" << memo[prev[i-1]+1] << endl;
		// cout << "memo of " << i << " is " << memo[i] << endl;
	}

	return memo[n];
} 


void printSequence(int n){

	if(n<=0)
		return;
	else{
		if(memo[n-1] > memo[n] ){
			printSequence(n-1);
			// cout << "came here";
		}
		else{
			printf("%d ", n);
			printSequence(prev[n]+1);
		}
	}

}

int main(){

	int num,i;
	cout <<  "enter the number of intervals";
	cin >> num;

	cout << "enter start time, finish time and weight of the intervals \n" << endl;
	for (i = 0; i < num; ++i)
	{	
		int x,y,z;
		cin >> x >> y >> z;
		v.push_back( make_pair(y, make_pair(x,z)) );

	}

	sort(v.begin(),v.end());


	// this is v[i] after sorting
	// for (int i = 0; i < num; ++i)
	// {
	// 	cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
	// }


	for (int i = num-1; i >=0; --i){
		int flag=0;
		for (int j = i-1; j >=0 ; --j){
			if(v[i].second.first >= v[j].first ){
				prev[i]=j;
				flag=1;
				break;
			}
		}
		if(flag==0)
			prev[i]=-1;
	}

	//prints the 'prev[]' array
	// for (int i = 0; i < num; ++i)
	// {
	// 	cout << prev[i] <<  endl;
	// }

	cout << "the optimal total weight is " << optimal(num) << endl ;

	cout << "the order of choosing is  ";
	printSequence(num);
	cout << endl;

return 0;	
}
