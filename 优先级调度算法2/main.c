#include <malloc.h>
#include <stdio.h>
#include <string.h>
typedef struct table
{
    int key; /*���� ID ��*/
    int priority; /*���̽������˳���*/
    char message[10]; /*����˵����Ϣ*/
    struct table *next;
}node;
node *insert(node *head,node *news) /*���½��̲��뵽�Ѿ�����Ķ����У��Խ��̱��������Ӵ�С����*/
{ //�����
    node *p,*q;
    p=head;
    q=p->next;
    while(1)
    {
    if(head->next==NULL)
        {
          if(news->priority>head->priority)
           {
        news->next=head;
          head=news;
              break;
           }
        else
          {
           head->next=news;
           break;
          }
        }
    else
        {
            if(p->priority>news->priority&&news->priority>q->priority)
                {news->next=q;
            p->next=news;
            break;
                }
            else
            {
                p=p->next;
                q=q->next;
                if(q->next==NULL)
                {
                q->next=news;
                break;
                }
                break;
            }
         }
    }
       return head;
}
node *creat(void) /*���庯�������� insert ���������ź���Ľ�������*/
 {
     node *head,*p;
     head=NULL;
     p=(node *)malloc(sizeof(node));
     p->next=NULL;
     printf("��������̱�:\n");
     scanf("%d",&p->key);
     if(p->key==0)
        return head;
        scanf("%d%s",&p->priority,p->message);
        head=p;
       while(1)
        {
p=(node *)malloc(sizeof(node));
            p->next=NULL;
     scanf("%d",&p->key);
    if(p->key==0)
        break;
        scanf("%d%s",&p->priority,p->message);
       head=insert(head,p);
	   }
return head;//�����
 } 
void print (node *head)  /*�������*/
  {
      node *p = head;
	printf("The table is:\n");
	while(p)
	{
		printf("%d,%d,%s\n",p->key,p->priority,p->message);
		p = p->next;
	}
       }
       node *rank_out(node *head) /*ģ�ⰴ��������С���̷ּ����ӵĹ���*/
         {//�����
             node *r,*s;
             r=head;
             s=head->next;
             printf("key=%d,priority=%d,message=%s\n",r->key,r->priority,r->message);
             return s;
}
void main()
   {
       int count=0;
       node *head;
       head=creat();
       print(head);
       while(head)
       {
           count++;
           printf("��%d�ν��̵���Ϊ:\n",count);
           head=rank_out(head);
}//�����ģ����̿��ƿ���а������ȼ�������ӹ���
}
/*
1 20 process1
2 50 process2
3 30 process3
4 10 process4
5 40 process5
*/
