#include <malloc.h>
#include <stdio.h>
#include <string.h>
typedef struct table
{
    int key; /*进程 ID 号*/
    int priority; /*进程进入队列顺序号*/
    char message[10]; /*进程说明信息*/
    struct table *next;
}node;
node *insert(node *head,node *news) /*将新进程插入到已经排序的队列中，对进程表按优先数从大到小排序*/
{ //填补程序
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
node *creat(void) /*定义函数，调用 insert 函数建立排好序的进程链表*/
 {
     node *head,*p;
     head=NULL;
     p=(node *)malloc(sizeof(node));
     p->next=NULL;
     printf("请输入进程表:\n");
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
return head;//填补程序
 } 
void print (node *head)  /*输出链表*/
  {
      node *p = head;
	printf("The table is:\n");
	while(p)
	{
		printf("%d,%d,%s\n",p->key,p->priority,p->message);
		p = p->next;
	}
       }
       node *rank_out(node *head) /*模拟按优先数大小进程分级出队的过程*/
         {//填补程序
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
           printf("第%d次进程调度为:\n",count);
           head=rank_out(head);
}//填补程序：模拟进程控制块队列按照优先级逐个出队过程
}
/*
1 20 process1
2 50 process2
3 30 process3
4 10 process4
5 40 process5
*/
