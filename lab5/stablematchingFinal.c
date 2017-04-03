#include<stdio.h>
int n,match[10],a[20][10],ar=-1;
int accept(int girl,int boy)
{
	int i=0;
	while(a[n+girl][i]!=match[girl] && i<n)
	{
		if(a[n+girl][i]==boy)
		return 1;
		i++;
	}
	return 0;
}

void main()
{
	int i,j,x,ex;
	for(i=0;i<10;i++)
	match[i]=-1;
	printf("Enter the no. of men or women\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the preference list of man %d : ",i);
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter the preference list of woman %d : ",i);
		for(j=0;j<n;j++)
		scanf("%d",&a[n+i][j]);
	}
	for(i=0;i<n;i++)
	{
		ex=-1;
		for(j=0;j<n;j++)
		{
			if(a[i][j]==-1)
			continue;
			x=a[i][j];
			a[i][j]=-1;
			if(accept(x,i))
			{
				ex=match[x];
				match[x]=i;
				break;
			}
		}
		if(ex!=-1)
		{
			if(ar==-1)
			ar=i;
			i=ex-1;
		}
		else if(ar!=-1)
		{
			i=ar;
			ar=-1;
		}
	}
	for(i=0;i<n;i++)
	printf("%d-%d\t",i,match[i]);
	printf("\n");
} 
