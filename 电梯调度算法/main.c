#include <malloc.h>
#include<stdio.h>
#include<math.h>
#include <limits.h>
typedef struct track{
    int column;
    struct track *next;
    }node;
int location;        /*��ǰ��ͷλ��*/
int sum_move=0;     /*��ͷ�ƶ��ܴŵ���*/
float ave_move;    /*��ͷ�ƶ�ƽ���ŵ���*/
int direction;    /*��ͷ�ƶ��ķ���direction=1 ��ʾ���������ƶ���direction=-1 ��ʾ���� �����ƶ�*/
node *found_node(node *head)  /*�ҵ��뵱ǰ��ͷ������� direction ͬ����Ĵŵ�*/   
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
node *SCAN(node *head,int direction,int location)  /*���� found_node �ҵ����������Ĵŵ������� head ������ɾ�� �ý��*/
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
	printf("���������������:\n");
     scanf("%d",&disk_length);
	  printf("������̶�д��������:\n");
     scanf("%d",&num);
	 printf("��������ƶ�����(1 ��ʾ���������ƶ���-1 ��ʾ���������ƶ�):\n");
    scanf("%d",&direction);
    printf("������̶�д�������������:\n");
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
printf("������̵�ǰλ��Ϊ:\n");
     scanf("%d",&location);
printf("\n ���η��ʵ������Ϊ:\n");
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
    printf("\n �ܵ��ƶ��������Ϊ:%d\n ",sum_move);
    printf("\n ƽ���ƶ�����Ϊ��%.2f \n",ave_move);
return 0;
    }
