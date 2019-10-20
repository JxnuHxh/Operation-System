#include <malloc.h>
#include <stdio.h>
#include <string.h>
typedef struct table  {
    int key;               /*���� ID ��*/
    int run_time;         /*��������ʱ��*/
    char message[10];     /*����˵����Ϣ*/
    struct table *next;  }node;
node *creat(void)      /*���庯�������� ID �ź�˳��ţ����������������������*/
{
     node *head,*p,*q;
     head=(node *)malloc(sizeof(node));
     p=head;
     q=(node *)malloc(sizeof(node));
     printf("�½��Ľ��̿��Ʊ�Ϊ:\nkey  run_time  message\n");
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
void print (node *head)  /*�������*/
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
node *insert(node *head,node *news)   /*������ news ���뵽����β��*/
{
    node *p;
     news->next=NULL;
    p=head->next;
    while(p->next!=NULL)
        p=p->next;
    p->next=news;

    return head;
}
node *timeslice(node *head,int cpu_base_time)                /*ģ��ʱ��Ƭ��ת���ȹ���:�����׽���ʹ��һ��ʱ��Ƭ�� CPU*/
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
     p=creat();     /*������̿��Ʊ�*/
     print(p);      /*���ԭʼ���̿��Ʊ�*/
     printf("CPU ���еĵ�λʱ��Ƭ cpu_base_time Ϊ:\n");
     scanf("%d",&cpu_base_time);
     while(p->next!=NULL)      /*ģ�ⰴ��λʱ��Ƭ������������Ȳ����� CPU ���еĹ���*/
        {
            count++;
            printf("��%d�ν��̵��ȵĽ��:\n",count);
            p=timeslice(p,cpu_base_time);
        }
        return 0;
}
/* 1 2 process1
   2 4 process2
   3 6 process3
   4 3 process4
*/
