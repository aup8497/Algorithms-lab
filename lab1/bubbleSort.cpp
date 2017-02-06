#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

long long num=0;
void bubbleSort(int a[],int n){
	// int n=((sizeof(a) )/sizeof(*a));

	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j+1]<a[j]){
				num++;
				swap(a[j+1],a[j]);
			}
		}
	}
}

int main(){

srand(time(NULL));
int n;
cin >> n;
int a[n];

for(int i=0;i<n;i++){
	a[i]=rand() % n + 1 ;
}

bubbleSort(a,n);

// for (int i = 0; i < n; ++i)
// {
// 	cout << a[i] << " " ; 
// }

cout << "total number of swaps : " << num << endl;

return 0;
}