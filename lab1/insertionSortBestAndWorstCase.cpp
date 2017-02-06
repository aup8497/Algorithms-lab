#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int num=0;
void insertionSort(int a[],int n){
	// int n=((sizeof(a) )/sizeof(*a));

	for(int i=1;i<n;i++){
		int j=i-1;
		int temp=a[i];
		while(j>=0 && temp<a[j] && ++num){
			
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
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

insertionSort(a,n);
num=0;
insertionSort(a,n);

cout << "total number of iterations in best case: " << num << endl;
num=0;
reverse(a,a+n);
insertionSort(a,n);

cout << "total number of iterations in worst case: " << num << endl;

return 0;
}