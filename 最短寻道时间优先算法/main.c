#include <malloc.h>
#include<stdio.h>
#include<math.h>
typedef struct track{
    int column;
    struct track *next;
    }node;
int location;        /*��ǰ��ͷλ��*/
int sum_move;     /*��ͷ�ƶ��ܴŵ���*/
float ave_move;    /*��ͷ�ƶ�ƽ���ŵ���*/
int l=0;
node *found_SSTF(node *head,int m)  /*�ҵ��뵱ǰ��ͷ����Ĵŵ������� head ��ɾ���ý��*/
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
     printf("���������������:\n");
     scanf("%d",&disk_length);
     printf("������̶�д��������:\n");
     scanf("%d",&num);
     printf("������̶�д�������������:\n");
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
     printf("������̵�ǰλ��Ϊ:\n");
     scanf("%d",&location);
     printf("\n ���η��ʵ������Ϊ:\n");
     sum_move=0;
    for(i=1;i<=num;i++)
        {
            head=found_SSTF(head,location);
			printf("%d ",l);
			location=l;

        }
      ave_move=(float)sum_move/num;
      printf("\n �ܵ��ƶ��������Ϊ:%d\n ",sum_move);
      printf("\n ƽ���ƶ�����Ϊ��%.2f \n",ave_move);
}
/*
200
9
55 58 39 18 90 160 150 38 184
100
  */