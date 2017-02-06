// didnot complete this still

#include<stdio.h>
int main(){

	int n,i,ii,len,sum,maxsum=0;
	scanf("%d",&n);
	int a[n];

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(len=1;len<=n;len++){
		for(i=0;i<=n-len;i++){
			sum=0;
			for(ii=i;ii<i+len;ii++){
				sum+=a[ii];
			}	
			if(sum>maxsum){
				maxsum=sum;
			}	
		}
	}

	printf("%d",maxsubarray(a,n));

return 0;
}