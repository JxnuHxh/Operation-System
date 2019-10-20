#include <malloc.h>
#include<stdio.h>
#include<math.h>
#include <limits.h>
typedef struct track{
    int column;
    struct track *next;
    }node;
int location;        /*当前磁头位置*/
int sum_move=0;     /*磁头移动总磁道数*/
float ave_move;    /*磁头移动平均磁道数*/
int direction;    /*磁头移动的方向：direction=1 表示从里向外移动，direction=-1 表示从外 向里移动*/
node *found_node(node *head)  /*找到离当前磁头最近且与 direction 同方向的磁道*/   
{ 
	node *p,*q;
	int i,temp;
p=head->next;
q=p->next;
for(i=0;i<9;i++)
{
	while(q)
	{
		if(p->column<q->column)
		{
			temp=p->column;
			p->column=q->column;
			q->column=temp;
		}
		p=p->next;
		q=q->next;
	}
	p=head->next;
	q=p->next;
}
return head;
}
node *SCAN(node *head,int direction,int location)  /*调用 found_node 找到满足条件的磁道，并从 head 链表中删除 该结点*/
{
	node *p,*q,*h;
	int k=0,i,temp;
	h=found_node(head);
	p=h->next;
	q=p->next;
	head=(node *)malloc(sizeof(node));
	head->next=NULL;
	while(q)
	{
		if(p->column>=location && q->column<location)
		{head->next=q;
		p->next=NULL;
		break;
		}
		p=p->next;
		q=q->next;
	}
	p=h->next;
	while(p)
	{	k++;
	p=p->next;
	}
	p=h->next;
	q=p->next;
for(i=0;i<k;i++)
{
	while(q)
	{
		if(p->column>q->column)
		{
			temp=p->column;
			p->column=q->column;
			q->column=temp;
		}
		p=p->next;
		q=q->next;
	}
	p=h->next;
	q=p->next;
}
if(direction==1)
{
	p=h->next;
	while(p->next)
		p=p->next;
	p->next=head->next;
}
if(direction==-1)
{
	p=head->next;
	while(p->next)
		p=p->next;
	p->next=h->next;
	h=head;
}
return h;	
}
int  main()
{
    int i,num,disk_length,t;
    node *head,*p,*pre;
	printf("输入磁盘柱面总数:\n");
     scanf("%d",&disk_length);
	  printf("输入磁盘读写请求总数:\n");
     scanf("%d",&num);
	 printf("输入磁盘移动方向(1 表示从里向外移动，-1 表示从外向里移动):\n");
    scanf("%d",&direction);
    printf("输入磁盘读写请求柱面号序列:\n");
    head=(node *)malloc(sizeof(node));
	p=head;
    for(i=1;i<=num;i++)
        {
            pre=(node *)malloc(sizeof(node));
			pre->next=NULL;
			scanf("%d",&pre->column);
			p->next=pre;
			p=pre;
	}
printf("输入磁盘当前位置为:\n");
     scanf("%d",&location);
printf("\n 依次访问的柱面号为:\n");
head=SCAN(head,direction,location);
p=head->next;
while(p)
{
	printf("%d ",p->column);
	if(p->column>location)
		t=p->column-location;
	else
		t=location-p->column;
	location=p->column;
sum_move=sum_move+t;
p=p->next;
}
ave_move=(float)sum_move/num;
    printf("\n 总的移动柱面次数为:%d\n ",sum_move);
    printf("\n 平均移动次数为：%.2f \n",ave_move);
return 0;
    }
