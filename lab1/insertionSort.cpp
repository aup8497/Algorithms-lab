#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

long long num=0;
void insertionSort(int a[],int n){
	// int n=((sizeof(a) )/sizeof(*a));

	for(int i=1;i<n;i++){
		int j=i-1;
		int temp=a[i];
		while(j>=0 && temp<a[j]){
			a[j+1]=a[j];
			j--;
			num++;
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

for (int i = 0; i < n; ++i)
{
	cout << a[i] << " " ; 
}

cout << "total number of swaps : " << num << endl;

return 0;
}