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
node *creat(void) /*定义函数，输入 ID 号和顺序号，按照输入次序建立进程链表21 1 1*/
{
     node *head,*p,*q;
     head=(node *)malloc(sizeof(node));
     p=head;
     q=(node *)malloc(sizeof(node));
     printf("新建的进程控制表为:\nkey  priority  message\n");
     scanf("%d",&q->key);
     if(q->key==0)
        return  head;
     scanf("%d%s",&q->priority,q->message);
     while(1)
     {
         p->next=q;
         p=q;
         q=(node *)malloc(sizeof(node));
         scanf("%d",&q->key);
     if(q->key==0)
        break;
     scanf("%d%s",&q->priority,q->message);
         }
         p->next=NULL;
         return head;
 }
void print (node *head)
{
    node *p;
    p=head->next;
    printf("the table is:\n");
    while(p)
    {
        printf("%d,%d,%s\n",p->key,p->priority,p->message);
        p=p->next;
    }
}
void processdo(node *head)
{
printf("key=%d, priority=%d, message=%s\n",head->key,head->priority,head->message);
}
int main()
{
    int i=0;
node *head;
    int h;
    node *p,*pre,*s,*q;
   head = creat();
    print(head);
    while (head->next)
        {

        h = 0;
        q = head->next;
        s = head;
        while (q){
            if (h<q->priority){
                h = q->priority;
                p = q;
                pre = s;
            }
            q = q->next;
            s = s->next;
        }
        i++;
        printf("第%d次出队的进程为:\n",i);
        processdo(p);
        if (p->next==NULL)
            pre->next = NULL;
        else
            pre->next = p->next;
        free(p);
    }
    return 0;
 }
 /*
 1 20 process1
 2 50 process2
 3 30 process3
 4 10 process4
 5 40 process5
 */






