#include <stdio.h>
#include <stdlib.h>
#define M 3   /*M Ϊϵͳ�������ҵ������ҳ����*/
#define N 20  /*N ΪҪװ����ҵ��ҳ������*/
int i=0;
bool  LRU(int x,int a[M])   /*���º����жϵ� i ��ҳ���Ƿ����ڴ�*/
{
     
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
     int k=0,j;
     printf("��������ҵ���:");
     for(j=0;j<N;j++)
     {
         scanf("%d",&b[j]);
     }
     a[2]=b[0];
	 if(b[1]!=a[2])
	 { a[1]=b[1];
      count++;
	 }
	 if(b[2]!=a[2]||b[2]!=a[1])
     {
		 a[0]=b[2];
		 count++;
	 }
       for(j=count;j<N;j++)
     {
         flag= LRU(b[j],a);
         if(flag!=true)
         {
             c[k]=a[2];
             a[2]=a[1];
             a[1]=a[0];
             a[0]=b[j];
			 k++;
             count++;
            }
		 else
		 {
			 int temp;
			 if(i==1)
			 {
				 temp=a[1];
				 a[1]=a[0];
				 a[0]=temp;
			 }
			 if(i==2)
			 {
				 temp=a[2];
				 a[2]=a[1];
				 a[1]=a[0];
				 a[0]=temp;
			 }
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
