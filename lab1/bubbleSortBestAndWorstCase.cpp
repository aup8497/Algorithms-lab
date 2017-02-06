#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long num=0;
void bubbleSort(int a[],int n){
	// int n=((sizeof(a) )/sizeof(*a));

	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			num++;

			if(a[j+1]<a[j]){
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
num=0;
bubbleSort(a,n);
cout << "total number of iterations in best case: " << num << endl;
num=0;
reverse(a,a+n);
bubbleSort(a,n);
cout << "total number of iterations in worst case: " << num << endl;


// for (int i = 0; i < n; ++i)
// {
// 	cout << a[i] << " " ; 
// }

return 0;
}