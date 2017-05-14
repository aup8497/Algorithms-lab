#include <iostream>

using namespace std;

int countInversions(int a[1000],int n){
int i,j,count=0;

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j])
				count++;
		}
	}

	return count;
}

int main(){
	int n,i;
	int a[1000];

	cout << "enter the size of array:";
	cin >> n;
	cout << "enter an array\n";

	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int res=countInversions(a,n);
	cout << "the number of inversions are " << res << endl;
}