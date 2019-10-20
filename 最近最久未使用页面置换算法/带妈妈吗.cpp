#include <stdio.h>
#include <stdlib.h>
#define M 3   /*M 为系统分配给作业的主存页面数*/
#define N 20  /*N 为要装入作业的页面总数*/
int i=0;
bool  LRU(int x,int a[M])   /*以下函数判断第 i 个页面是否在内存*/
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
     int a[M];/*存放已装入内存的页号序列*/
     int b[N]; /*存放作业页号序列*/
     int c[N]; /*存放被淘汰的页号序列*/
     int count=1;  /*count 为缺页总次数*/
     bool flag;  /*flag 标识该页是否在内存*/
     int k=0,j;
     printf("请输入作业序号:");
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
     printf("发生缺页次数=%d\n",count);
     printf("缺页中断概率=%d.00%%\n",count*100/20);
     printf("驻留内存的页号分别为:");
     for(i=2;i>=0;i--)
        printf("%d,",a[i]);
        printf("\n");
     printf("被淘汰的页号分别为:");
     for(i=0;i<k;i++)
        printf(" %d,",c[i]);
	 printf("\n");
      return 0;
}
/*
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/
