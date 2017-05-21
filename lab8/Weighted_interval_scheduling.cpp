// this is the top down approach for the weighted interval scheduling problem

 #include <bits/stdc++.h>
using namespace std;

std::vector< pair<int, pair<int,int> > > v;
int prev[1000];
int memo[1000];

int optimal(int n){
	int result;
	if(memo[n]!=-1)
		return memo[n];
	else{
		if(n<0)
			result=0;
		else{
			result=max( optimal(n-1), v[n].second.second + optimal(prev[n]) );
		}		
	}
	memo[n]=result;
	return result;
} 

void printSequence(int n){

	if(n<0)
		return;
	else{
		if(optimal(n-1) > v[n].second.second + optimal(prev[n]) )
			printSequence(n-1);
		else{
			printf("%d ", n);
			printSequence(prev[n]);
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

		//initaializing memo array to 0;
		memo[i]=-1;
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

	cout << "the optimal total weight is " << optimal(num-1) << endl ;

	printf("\n\nthe sequence of choosing the interval is  ");
	printSequence(num-1);

return 0;	
}
