#include <malloc.h>
#include<stdio.h>
#include<math.h>
typedef struct track{
    int column;
    struct track *next;
    }node;
int location;        /*当前磁头位置*/
int sum_move;     /*磁头移动总磁道数*/
float ave_move;    /*磁头移动平均磁道数*/
int l=0;
node *found_SSTF(node *head,int m)  /*找到离当前磁头最近的磁道，并从 head 中删除该结点*/
{
    int c,s=200,i;
    node *p,*q;
    p=head->next;
    q=head;
    while(p)
    {
        if(p->column>m)
            c=p->column-m;
        else
            c=m-p->column;
        if(s>c)
          s=c;
          p=p->next;
    }
	p=head->next;
    for(i=0;i<9;i++)
    {
        if(p->column>m)
        {
            if(p->column-m==s)
              {
                  l=p->column;
				  if(p->next==NULL)
					  q->next=NULL;
				  else{
                  q->next=p->next;
              free(p); 
				  }
                 sum_move=sum_move+s;
			return head;
			}
        }
        if(p->column<m)
        {
            if(m-p->column==s)
                 {l=p->column;
                     if(p->next==NULL)
					  q->next=NULL;
				  else{
                  q->next=p->next;
              free(p); 
				  } 
			  sum_move=sum_move+s;
			  return head;
			}
        }
        p=p->next;
        q=q->next;
    }
    return head;
}
 void main()
 {
     int i,num,disk_length;
     node *head,*p,*pre;
     printf("输入磁盘柱面总数:\n");
     scanf("%d",&disk_length);
     printf("输入磁盘读写请求总数:\n");
     scanf("%d",&num);
     printf("输入磁盘读写请求柱面号序列:\n");
     head=(node *)malloc(sizeof(node));
     p=head;
    for(i=1;i<=num;i++)
        {
            pre=(node *)malloc(sizeof(node)) ;
			pre->next=NULL;
            scanf("%d",&pre->column);
            p->next=pre;
            p=pre;
        }
     printf("输入磁盘当前位置为:\n");
     scanf("%d",&location);
     printf("\n 依次访问的柱面号为:\n");
     sum_move=0;
    for(i=1;i<=num;i++)
        {
            head=found_SSTF(head,location);
			printf("%d ",l);
			location=l;

        }
      ave_move=(float)sum_move/num;
      printf("\n 总的移动柱面次数为:%d\n ",sum_move);
      printf("\n 平均移动次数为：%.2f \n",ave_move);
}
/*
200
9
55 58 39 18 90 160 150 38 184
100
  */