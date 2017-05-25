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

void print(int i,int j){

	if(i==0 && j==0){
		cout << " /****reached base****/ " <<endl;
		return;
	}

	if(i==0 && j!=0){
		print(i,j-1);
		cout << "* adding " << s2[j] << " to string1"  << endl;
		return;
	}
	else if(i!=0 && j==0){
		print(i-1,j);
		cout << "* removing " << s1[i] << " from string1 "  << endl;
		return;
	}

	if(memo[i-1][j-1]<=memo[i-1][j] && memo[i-1][j-1]<= memo[i][j-1]  ){

		print(i-1,j-1);

		if(!diff(i,j))
				cout << "* leaving " << s1[i] << " as it is "<< endl;
 		else
			cout << "* replacing " << s1[i] << " by " << s2[j]  << endl;

	}else if(memo[i-1][j]<=memo[i-1][j-1] && memo[i-1][j]<= memo[i][j-1]  ){

		print(i-1,j);

			cout << "* removing " << s1[i] << " from string1"  << endl;

	}else{

		print(i,j-1);

			cout << "* adding " << s2[j] << " to string1"  << endl;
	}

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


	cout << " The final path is \n" << endl;
	print(n1-1,n2-1);

}