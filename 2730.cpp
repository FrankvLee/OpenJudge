#include<stdio.h>
int ch[20000]={0,1},df=1;
int l=1,fuck=1;
void calc(int x)
{
	int i,j,t=0;
	for(i=1;i<=l+5;i++)
	{
		ch[i]=ch[i]*x+t;
		t=ch[i]/10;
		ch[i]%=10;
		if(i>l&&ch[i]!=0)l=i;
	}
	for(i=1;i<=l;i++)
		if(ch[i]!=0)
		{
			fuck+=(i-1);
			break;
		}
	l=l-i+1;
	for(j=1;j<=l+i;j++)
		ch[j]=ch[j+i-1];
	df=i;
}
int main()
{
	int n,i,k;
	scanf("%d",&n);
	k=1;
	for(i=2;i<=n;i++)
	{
		if((k<(2000000/i))&&i<n)
		{
			while(k%10==0)
			{
				fuck++;
				k/=10;
			}
			k*=i;
		}
		else 
		{
			calc(k);
			calc(i);
			k=1;
		}
	}
	for(i=l;i>=1;i--)
	{
		printf("%d",ch[i]);
	}
	for(i=1;i<fuck;i++)
	{
		printf("0");
	}
	return 0;
}