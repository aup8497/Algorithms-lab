#include<stdio.h>
int main(){
	int i,pos,n,z;
	printf("enter the position : ");
	scanf("%d",&pos);
	// int a[0]=0;a[1]=1;
	int x=0,y=1;
	for(i=2;i<=pos;i++){
		z=x+y;
		x=y;
		y=z;
	}

	printf("the fibonacci number at the entered position is : %d\n",z );

} 
