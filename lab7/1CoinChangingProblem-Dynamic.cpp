#include <iostream>

using namespace std;

int main(){
	int i,n,j;
	int num=3;
	int a[]={1,10,25};

	cout << "enter n\n" ;
	cin >> n;
	int dp[n+1];

	for(i=0;i<n+1;i++)
		dp[i]=1000;

	dp[0]=0;

	for(i=1;i<n+1;i++){
		
		j=0;
		while( a[j] <= i && j<=num){
			dp[i]=min(dp[i],dp[i-a[j]]+1 );
			j++;
		} 	
		cout << " i= " << i << " "<<  dp[i] << endl;
	}	

	cout << dp[n] << endl;

return 0;
}