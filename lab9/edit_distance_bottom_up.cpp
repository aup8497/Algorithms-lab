#include <iostream>
#include <string.h>

using namespace std;
int a[1000][1000],n1,i,j,n2;


int diff(string s1,string s2,int i,int j){
	if(s1[i]==s2[j])
		return 0;
	else
		return 1;
}

int edit_distance(string s1, string s2) {

	int i,j;
	n1=s1.length() ;
	n2=s2.length() ;

	for(i=0;i<=n2;i++)
		a[0][i]=i;
	for(i=0;i<=n1;i++)
		a[i][0]=i;

	for(i=1;i<=n1;i++){
		for(j=1;j<=n2;j++){

			a[i][j] = min(  min( a[i-1][j]+1,a[i][j-1]+1)  , a[i-1][j-1]+diff(s1,s2,i-1,j-1)  );
		
		}
	}

	for (i = 0; i <= n1; ++i){
		for (j = 0; j <= n2; ++j){

			cout << a[i][j] << " " ;
		
		}cout << endl;
	}

	return a[n1][n2];


}

void print(string s1,string s2){

	i=n1;j=n2;
	while(i!=0 || j!=0 ){

		if(a[i-1][j-1]<=a[i-1][j] && a[i-1][j-1]<=a[i][j-1]){
			if(diff(s1,s2,i-1,j-1)==1)
				cout << "replacing " << s1[i-1] << " by " << s2[j-1] << endl;
			else
				cout << "leave " << s1[i-1] << " as it is "  << endl;

			i-=1;
			j-=1;

		}else if( a[i-1][j]<=a[i-1][j-1] && a[i-1][j]<=a[i][j-1] ){

			cout << "removing " << s1[i-1] << " from string s1" << endl; 
			i-=1;

		}else{
			cout << "adding " << s2[j-1] << "to string s1" << endl;
			j-=1; 
		}



	} 

}

int main(){

	string s1,s2;
	cout << "enter the two strings\n" ;
	cin >> s1 >> s2;

	cout << "minimum of edit_distance is " << edit_distance(s1,s2) << endl;

	print(s1,s2);


return 0;	
}
