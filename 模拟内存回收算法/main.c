#include <malloc.h>
#include <stdio.h>
#include <string.h>
typedef struct table   {
    int address;        /*�洢������ʼ��ַ*/
    int length;         /*�洢��������*/
    int flag;           /*�洢������־��0 Ϊ���У�1 Ϊ����ҵռ��*/
    char name[10];     /*�� flag==1 ʱ�洢����ռ�ñ�־��ҵ��������洢�� nil*/
    struct table *next;
}node;
node *work;    /*����һ��ȫ�ֱ��� work����λ��Ҫ�ͷŵĽ��*/
char type;     /*����һ��ȫ�ֱ��� type����ע��������*/
int flag;  /*����һ��ȫ�ֱ��� success����ע���ս���Ƿ��ڷ����������*/
node *insert(node *head, node *news)  /*���ա���ַ������ʽ���� p ������������Ӧλ��*/
{
    node *p,*q;
	news->next=NULL;
	p=head;
	q=p->next;

	if(head->address>=news->address)
	{ news->next=head;
	head=news;
	return head;
	}
	else if(head->next==NULL)
	{
		head->next=news;
		return head;
	}
	else
	{
		while(1)
		{
			if(q->address>=news->address)
			{
				news->next=q;
				p->next=news;
				break;
			}
			else if(q->next==NULL)
			{
				q->next=news;
				break;
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
	printf("address    length    flag(0 or 1)\n");
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
node *found(node *distributedhead,char workn[10])  /*�����ѷ������Ҫ���յķ���λ��*/
{
    node *p, *q,*h;
    q=distributedhead;
    p=(node *)malloc(sizeof(node));
    p->next=q;
	while(strcmp(q->name,workn)!=0)
	{
	    if(q->next==NULL)
	{flag=0;
	return NULL;
	}
	    p=p->next;
	q=q->next;
		}
		flag=1;
       printf(" distributing is successful������\n");
		h=(node *)malloc(sizeof(node));
		h->address=q->address;
		h->flag=0;
		h->length=q->length;
		strcpy(h->name,"nil");
		p->next=q->next;
		free(q);
		return h;
}
node *release(node *freehead,node *work)   /*�����������ɿ��з������չ���*/
{
    node *p,*q;
    p=freehead;
	q=p->next;
	if(work==NULL)
        return freehead;
	while(q)
	{
		if( (p->address + p->length==work->address) && (work->address + work->length==q->address))
		{
		    type='C';
			p->length=work->length+p->length+q->length;
			if(q->next==NULL)
			{	p->next=NULL;
			free(q);
			}
	        else
			{
				p->next=q->next;
				free(q);
			}
		   break;
		}
   else	if(p->address+p->length==work->address)
		{
			type='A';
			p->length=p->length+work->length;
			break;
		}
	else	if(work->address+work->length==q->address)
		{
			type='B';
			q->address=work->address;
			q->length=work->length+q->length;
		    break;
		}

else if((work->address>p->address) && (work->address<q->address) )
		{
	     	type='D';
			freehead=insert(freehead,work);
				break;
		}
else if(work->address<freehead->address)
	 {
	     	type='D';
			freehead=insert(freehead,work);
				break;
		}
else
{
		p=p->next;
		q=q->next;
}
	}
	return freehead;
}
void print (node *head)  /*�������*/
{
	node *p;
    p=head;
	if(p->flag==0)
    printf("free table is:\n");
	else
       printf(" distributed table is:\n");
    while(p)
    {
        printf("%d,%d,%d,%s\n",p->address,p->length,p->flag,p->name);
        p=p->next;
    }
}
void main()
{   int i=0,sum;
struct table *dtable,*ftable,*p;
char workn[10];
printf("The distributed table is:\n");
dtable=creat();              /*dtable �����ѷ��������*/
printf("The free table is:\n");
ftable=creat();  /*ftable ����δ���������*/
print(dtable);
print(ftable);
/*����ģ������ڴ���չ���*/
printf("Input the released work segment sum:");
scanf("%d",&sum);
while(sum--)
{
	i++;
	printf("%d: Input the released work segment name:",i);
	scanf("%s",&workn);
	p=found(dtable,workn);
	if(flag==0)
	{
		printf("Ҫ���յķ���������!\n");
	}
	else{
		ftable=release(ftable,p);
		printf("the type of release is %c!\n",type);
		print(dtable);
		printf("\n");
		print(ftable);
	}
}
}
