#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define NULL 0
typedef struct table   {
    int address;        /*�洢������ʼ��ַ*/
    int length;         /*�洢��������*/
    int flag;           /*�洢������־��0 Ϊ���У�1 Ϊ����ҵռ��*/
    char name[10];     /*�� flag==1 ʱ�洢����ռ�ñ�־��ҵ��������洢�� nil*/
   struct table *next;
     }node;
int flag; /*����ɹ����ı�־*/
node *insert(node *head, node *news)  /*���ա���ַ������ʽ���� p ������������Ӧλ��*/
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
node *creat()   /*���ݵ�ַ������ʽ�������������(flag==1)����з�����(flag==0)*/
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
  void print (node *head)  /*�������*/
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
/*�ڿ��з��������ҳ��״κ��� work �ķ�����ͬʱ�޸Ŀ��з�����ͷ��������*/
{
    node *p;
    p=freehead;
    while(1)
    {
        while(work->length>p->length&&p->next!=NULL)
            p=p->next;
        if(work->length<p->length)
        {
           printf(" distributing is successful������\n");
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
            printf(" distributing is not successful ������\n");
            break;

        }
    }
}
void main()
{
    struct table *dtable,*ftable,*work;
    printf("The distributed table is:\n");
    dtable=creat();/*dtable �����ѷ��������*/
    printf("The free table is:\n");
    ftable=creat();/*ftable ����δ���������*/
    while(1)
        {
    work=(node *)malloc(sizeof(node));
    work->next=NULL;
    printf("the length of job is:");
    scanf("%d",&work->length);
    printf("the name of job is:");
    scanf("%s",&work->name);
    /*����ģ������ڴ��������*/
        distribute(ftable,dtable,work);
        printf("the distribute table is��");
        print(dtable);
        printf("the free table is��");
        print(ftable);
        if(flag==0)
            break;
      }
}
