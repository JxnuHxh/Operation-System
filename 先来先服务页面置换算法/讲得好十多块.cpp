#include <stdio.h>
#include <stdlib.h>
#define M 3   /*M Ϊϵͳ�������ҵ������ҳ����*/
#define N 20  /*N ΪҪװ����ҵ��ҳ������*/
bool found(int x,int a[M])   /*���º����жϵ� i ��ҳ���Ƿ����ڴ�*/
{
	int i;
   for(i=0;i<3;i++)
   {
     if(a[i]==x)
        return true;
   }
   return false;
}
int main()
{
     int a[M];/*�����װ���ڴ��ҳ������*/
     int b[N]; /*�����ҵҳ������*/
     int c[N]; /*��ű���̭��ҳ������*/
     int count=1;  /*count Ϊȱҳ�ܴ���*/
     bool flag;  /*flag ��ʶ��ҳ�Ƿ����ڴ�*/
     int i,k=0,j=0;
     printf("��������ҵ���:");
     for(i=0;i<N;i++)
     {
         scanf("%d",&b[i]);
     }
     a[0]=b[0];
	 if(b[1]!=a[0])
	 { a[1]=b[1];
      count++;
	 }
	 if(b[2]!=a[1]||b[2]!=a[0])
     {
		 a[2]=b[2];
		 count++;
	 }
       for(i=count;i<N;i++)
     {
         flag=found(b[i],a);
         if(flag!=true)
         {
             c[k]=a[j];
             a[j]=b[i];
             count++;
             j++;k++;
             if(j==3)
                j=0;
        }

     }
     printf("����ȱҳ����=%d\n",count);
     printf("ȱҳ�жϸ���=%d.00%%\n",count*100/20);
     printf("פ���ڴ��ҳ�ŷֱ�Ϊ:");
     for(i=2;i>=0;i--)
        printf("%d,",a[i]);
        printf("\n");
     printf("����̭��ҳ�ŷֱ�Ϊ:");
     for(i=0;i<k;i++)
        printf(" %d,",c[i]);
	 printf("\n");
      return 0;
}
/*
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/
