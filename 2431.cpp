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

// POJ 2431
// Expedition

#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX_NUM 10001
using namespace std;

class FUELSTOP
{
public:
	int dis,f; //ÿ������վ�ĵ�Ŀ�ĵصľ���ͼ�����
	FUELSTOP(){};
	FUELSTOP(int n1,int n2)
	{
		dis=n1;
		f=n2;
	}
}fuelstop[MAX_NUM];

bool cmp(const FUELSTOP &fs1,const FUELSTOP &fs2)
{
	return fs1.dis<fs2.dis; //�������ݣ�����վ��Ŀ�ĵصľ���
}

int max(int x,int y)
{
	if(x>y)return x;
	return y;
}

int main()
{
	int n,l,p,i,j,sum=0;
	bool b[MAX_NUM]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&fuelstop[i].dis,&fuelstop[i].f);
	sort(fuelstop,fuelstop+n,cmp); //��ÿ������վ����Ŀ�ĵصľ��볤������
	scanf("%d%d",&l,&p);
	n--;
	while(fuelstop[n].dis>l&&n>=0)
		n--; //�ų��ڳ�����֮��ļ���վ
	while(1)
	{
		int tl=l-p,maxf=0; //tl��ʾ�Ĺ⵱ǰ�����ܵ������Զ����
		if(tl<=0) //��ǰ�����Ѿ��㹻�ִܵ�Ŀ�ĵ�
		{
			cout<<sum;
			return 0;
		}
		j=-1;
		for(i=n;i>=0;i--)
		{
			if(fuelstop[i].dis<tl)break; //�Ĺ⵱ǰ����Ҳ�޷��ִ�ļ���վ
			if(fuelstop[i].f>maxf&&!b[i]) //�����Ĺ�ǰ��δ�ӹ��͵ļ���վ��ѡ����������ģ�������maxf��ʾ����j��¼�ü���վ�ı��
			{
				j=i;
				maxf=fuelstop[i].f;
			}
		}
		if(j==-1) //�Ĺ�����Ҳ�޷��ִ��κ�һ��δ�ӹ��͵ļ���վ�����-1
		{
			cout<<-1;
			return 0;
		}
		else
		{
			b[j]=1;
			p+=maxf;
			sum++;
		}
	}
}
