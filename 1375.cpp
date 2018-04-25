/*
  ����ϵر�֤��
    
      ���Լ��������������������ӷ�������Ƶ���������й�����

      ��������������У���������ʲô���Ѷ�������ˣ���ô���ҽ��ڳ���ʵϰ��
   ������ϸ���о��������������⣬�Լ����˸��ҵ���ʾ��

      �ҵĳ������з������õ�����������ĵ�֮��������̲ġ����ñʼǡ����ϵ�
   Դ�����Լ������ο����ϵĴ����,�Ҷ��Ѿ��ڳ����ע����������ע��������
   �ĳ�����

      �Ҵ�δû��Ϯ�����˵ĳ���Ҳû�е��ñ��˵ĳ��򣬲������޸�ʽ�ĳ�Ϯ��
   ��ԭ�ⲻ���ĳ�Ϯ��

      �ұ�д������򣬴���û�����Ҫȥ�ƻ���������������ϵͳ��������ת��

      ���Ӻ�
*/

// POJ 1375
// Intervals

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

class INTERVAL
{
public:
	double x1,x2;
	INTERVAL(double a,double b)
	{
		if(a<b)
		{
			x1=a;
			x2=b;
		}
		else
		{
			x1=b;
			x2=a;
		}
	} //��x1<x2
};

bool cmp(const INTERVAL &itv1,const INTERVAL &itv2)
{
	return (itv1.x1<itv2.x1)||(itv1.x1==itv2.x1&&itv1.x2<itv2.x2); //�������ݣ�x1
}

double max(const double x,const double y)
{
	if(x>y)return x;
	return y;
}

int main()
{
	int i,j,n,x,y,r,x0,y0;
	double k1,k2,x1,x2;
	vector<INTERVAL> v;
	while(cin>>n)
	{
		if(n==0)return 0;
		v.clear();
		scanf("%d%d",&x0,&y0);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x,&y,&r);
			double a=(y0-y)*(y0-y)-r*r; //��������б�ʵ�һԪ���η��̵Ķ�����
			double b=2*(y0-y)*(x-x0); //��������б�ʵ�һԪ���η��̵�һ����
			double c=(x0-x)*(x0-x)-r*r; //��������б�ʵ�һԪ���η��̵ĳ�����
			k1=(-b+sqrt(b*b-4*a*c))/(2*a);
			k2=(-b-sqrt(b*b-4*a*c))/(2*a); //�������ߵ�б��k1��k2
			x1=-y0*k1+x0;
			x2=-y0*k2+x0; //������x�����������ĺ�����x1��x2
			v.push_back(INTERVAL(x1,x2));
		}
		sort(v.begin(),v.end(),cmp); //�������䰴x1��С����
		j=0;
		for(i=1;i<v.size();i++)
		{
			if(v[j].x2>=v[i].x1)v[j].x2=max(v[j].x2,v[i].x2); //����һ�������x1��ǰһ�������x2С�������������н���������ϲ�
			else //��������û�н��������ǰһ�������x1��x2
			{
				printf("%.2f %.2f\n",v[j].x1,v[j].x2);
				j=i;
			}
		}
		printf("%.2f %.2f\n\n",v[j].x1,v[j].x2); //������һ�������x1��x2
	}
}