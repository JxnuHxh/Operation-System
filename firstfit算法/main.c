#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define NULL 0
typedef struct table   {
    int address;        /*存储分区起始地址*/
    int length;         /*存储分区长度*/
    int flag;           /*存储分区标志，0 为空闲，1 为被作业占据*/
    char name[10];     /*当 flag==1 时存储分区占用标志作业名，否则存储空 nil*/
   struct table *next;
     }node;
int flag; /*分配成功与否的标志*/
node *insert(node *head, node *news)  /*按照“地址递增方式”将 p 结点插入链表相应位置*/
{
    node *p,*q;
    if(head->next==NULL)
        {
          if(news->address<head->address)
           {
        news->next=head;
          head=news;
              return head;;
           }
        else
          {
           head->next=news;
          return head;
          }
        }
    p=head;
    q=p->next;
    while(1)
    {
            if(news->address > p->address && news->address < q->address)
                {
                    news->next=q;
                    p->next=news;
                    break;
                }
            else
            {
               if(q->next==NULL)
               {
                   if(news->address>q->address)
                  {
                   q->next=news;
                   break;
                  }
                  else
                   {
                   news->next=q;
                   p->next=news;
                   break;
                   }
               }
             else
               {
                   p=p->next;
                   q=q->next;
               }
            }

    }
       return head;
}
node *creat()   /*根据地址递增方式建立分配分区表(flag==1)或空闲分区表(flag==0)*/
  {
      node *head,*p;
     p=(node *)malloc(sizeof(node));
     p->next=NULL;
     head=p;
     printf("address length flag(0 or 1)\n");
  scanf("%d%d%d",&p->address,&p->length,&p->flag);
     if(p->flag==1){
     printf("        input job_name:");
     scanf("%s",p->name);
     }
     else{
            strcpy(p->name,"nil");
                  }
if(p->length==0)
        return  head;
while(1)
        {
      p=(node *)malloc(sizeof(node));
            p->next=NULL;
     scanf("%d%d%d",&p->address,&p->length,&p->flag);
     if(p->flag==1){
     printf("        input job_name:");
     scanf("%s",&p->name);
     }
     else{
            strcpy(p->name,"nil");
                  }
     if(p->length==0)
        break;
       head=insert(head,p);
      }
return head;
  }
  void print (node *head)  /*输出链表*/
{
    node *p;
    p=head;
    printf("the table is:\n");
    while(p)
    {
        printf("%d,%d,%d,%s\n",p->address,p->length,p->flag,p->name);
        p=p->next;
    }
}
void distribute(node *freehead, node *distributedhead, node *work)
/*在空闲分区表中找出首次合适 work 的分区，同时修改空闲分区表和分配分区表*/
{
    node *p;
    p=freehead;
    while(1)
    {
        while(work->length>p->length&&p->next!=NULL)
            p=p->next;
        if(work->length<p->length)
        {
           printf(" distributing is successful！！！\n");
            flag =1;
            work->address=p->address;
            p->address=p->address+work->length;
            p->length=p->length-work->length;
            work->flag=1;
            distributedhead=insert(distributedhead,work);
            break;
        }
        if(p->next==NULL)
        {
            flag=0;
            printf(" distributing is not successful ！！！\n");
            break;

        }
    }
}
void main()
{
    struct table *dtable,*ftable,*work;
    printf("The distributed table is:\n");
    dtable=creat();/*dtable 输入已分配情况表*/
    printf("The free table is:\n");
    ftable=creat();/*ftable 输入未分配情况表*/
    while(1)
        {
    work=(node *)malloc(sizeof(node));
    work->next=NULL;
    printf("the length of job is:");
    scanf("%d",&work->length);
    printf("the name of job is:");
    scanf("%s",&work->name);
    /*以下模拟逐个内存申请过程*/
        distribute(ftable,dtable,work);
        printf("the distribute table is！");
        print(dtable);
        printf("the free table is！");
        print(ftable);
        if(flag==0)
            break;
      }
}
