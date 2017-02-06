#include<stdio.h>

int fibo(int n){
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else if(n==2)
		return 1;
	else
		return fibo(n-1)+fibo(n-2);
}

int main(){
	int i,pos,n,z;
	printf("enter the position : ");
	scanf("%d",&pos);
	
	printf("the fibonacci number at the entered position is : %d\n",fibo(pos) );

} 
