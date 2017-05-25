#include <iostream>
#include <string.h>

using namespace std;

int a[1000][1000],i,j;
string s1,s2;
int memo[1000][1000];

int diff(int i,int j){
	if(s1[i]==s2[j])
		return 0;
	else
		return 1;
}

int edit_dist(int i,int j){

	// cout << "\n i= " << i << " j= " << j ;

	if(i==-1)
		return j+1;
	if(j==-1)
		return i+1;

	if(memo[i][j]!=-1)
		return memo[i][j];
	else
		memo[i][j]=min( min( edit_dist(i,j-1)+1 , edit_dist(i-1,j)+1 ) , edit_dist(i-1,j-1)+diff(i,j) );

	return memo[i][j];
}

int main(){

	cout << "enter the strings \n";
	cin >> s1  >> s2;
	int n1=s1.length();
	int n2=s2.length();

	for(i=0;i<n1;i++)
		for(j=0;j<n2;j++)
			memo[i][j]=-1;

	cout << "the minimum edit distance is "  << edit_dist(n1-1,n2-1) << endl;	

	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++)
			cout << memo[i][j];
		cout << endl;
	}


}