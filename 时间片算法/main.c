#include <malloc.h>
#include <stdio.h>
#include <string.h>
typedef struct table  {
    int key;               /*进程 ID 号*/
    int run_time;         /*进程运行时间*/
    char message[10];     /*进程说明信息*/
    struct table *next;  }node;
node *creat(void)      /*定义函数，输入 ID 号和顺序号，按照输入次序建立进程链表*/
{
     node *head,*p,*q;
     head=(node *)malloc(sizeof(node));
     p=head;
     q=(node *)malloc(sizeof(node));
     printf("新建的进程控制表为:\nkey  run_time  message\n");
     scanf("%d",&q->key);
     if(q->key==0)
        return  head;
     scanf("%d%s",&q->run_time,q->message);
     while(1)
     {
         p->next=q;
         p=q;
         q=(node *)malloc(sizeof(node));
         scanf("%d",&q->key);
     if(q->key==0)
        break;
     scanf("%d%s",&q->run_time,q->message);
         }
         p->next=NULL;
         return head;
}
void print (node *head)  /*输出链表*/
{
    node *p;
    p=head->next;
    printf("the table is:\n");
    while(p)
    {
        printf("%d,%d,%s\n",p->key,p->run_time,p->message);
        p=p->next;
    }
}
node *insert(node *head,node *news)   /*将进程 news 插入到队列尾部*/
{
    node *p;
     news->next=NULL;
    p=head->next;
    while(p->next!=NULL)
        p=p->next;
    p->next=news;

    return head;
}
node *timeslice(node *head,int cpu_base_time)                /*模拟时间片轮转调度过程:队列首进程使用一个时间片的 CPU*/
 {
     node *p,*q,*h;
     p=head;
     q=p->next;
     if(q->run_time<=cpu_base_time)
     {
         printf("key=%d,run_time=%d,massage=%s\n",q->key,q->run_time,q->message);
         if(q->next==NULL)
            p->next=NULL;
         else{
         p->next=q->next;
         free(q);}
         return head;
     }
    else
     {
         q->run_time=q->run_time-cpu_base_time;
         h=q;
         if(q->next==NULL)
         {
             p->next=NULL;
         }
         else{
         p->next=q->next;
         free(q);}
         insert(head,h);
         print(head);
         return head;
     }
     }
 int main()
 {
     int count=0,cpu_base_time;
     node *p;
     p=creat();     /*输入进程控制表*/
     print(p);      /*输出原始进程控制表*/
     printf("CPU 运行的单位时间片 cpu_base_time 为:\n");
     scanf("%d",&cpu_base_time);
     while(p->next!=NULL)      /*模拟按单位时间片进程逐个被调度并进入 CPU 运行的过程*/
        {
            count++;
            printf("第%d次进程调度的结果:\n",count);
            p=timeslice(p,cpu_base_time);
        }
        return 0;
}
/* 1 2 process1
   2 4 process2
   3 6 process3
   4 3 process4
*/
