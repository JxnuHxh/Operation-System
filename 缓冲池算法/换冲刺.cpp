#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Buff_MAX 10 // ��ʼ ���л������ĸ���
typedef struct buffernode
{
	int buf_type;
	//"0" ���л�������"-1" װ�������ݵĻ�������"1" װ������ݵĻ�����
	int buf_data; // ѭ��������
	struct buffernode *next; // ָ����һ��ָ��
}node;
// ȫ�ֱ���
node *tempnode; 
/********************************************************************
create  ����˵��: �������л������, ÿ�����л������ڵ����ݴ�š�-32768 ����
����ֵ:  ���ض��е�ͷָ��
********************************************************************/
node *creat( ) /* �������л������*/
{ //�����
	node *head,*p1,*p2;
	int n = 0;
	p1=p2=(node *)malloc(sizeof(node));
	head=NULL;
	for(int i = 0; i <	11; i++)
	   {
		p1->buf_data = -32768;
		p1->buf_type = 0;
		n = n+1;
		if(n==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(node *) malloc (sizeof(node));
	   }
	p2->next=NULL;
	return head;
}
/********************************************************************
print_buf  ����˵��: �ú�����ӡ ����������� ���������
����ֵ:  ��
********************************************************************/
void print_buf(node *emq, node *inq, node *outq)
{ //�����
	node *p;
	p = emq;
	printf("\n���л���������emq���ݣ�\n");
	while(p->next)
	{
		printf("%d\t",p->buf_data);
		p = p->next;
	}
	printf("\n\n���뻺��������inq��\n");
	p = inq;
	if(p == NULL)
		printf("Input buffer is emptty.");
	else
	{
		while(p)
		{
			printf("%d\t",p->buf_data);
			p = p->next;
		}
	}
	printf("\n\n�������������outq��\n");
	p = outq;
	if(p == NULL)
		printf("Output buffer is emptty.");
	else
		while(p)
		{
			printf("%d\t",p->buf_data);
			p = p->next;
		}
		
}
/********************************************************************
Getbuf  ����˵��: �� �ú����Ӷ��׶�һ�����ݳ����� ʹ�� tempnode  ָ����׵�һ�����
����ֵ: ����ָ�� head
********************************************************************/
node *Getbuf(node *head)
{ //�����
	if(head == NULL)
		return NULL;
	tempnode = (node *) malloc (sizeof(node));
	tempnode = head;
	head = head->next;
	tempnode->next = NULL;
	return head;
}
/********************************************************************
Putbuf  ����˵��:  �ú� ���Ӳ���һ����㵽��δ��
����ֵ: ����ָ�� head
********************************************************************/
node *Putbuf(node *head, node *newnode)
{ //�����
	node *p = head;
	if(head == NULL)
	{
		head = (node *) malloc (sizeof(node));
		head = newnode;
		head->next =NULL;
	}
	else
	{
		while(p->next)
			p = p->next;
		p->next = newnode;
		newnode->next = NULL;
	}
	
	return head;
}
/**************MAIN  ����**********************/
void main(int argc, char *argv[])
{
	int flag;
	node *emq,*inq,*outq;
	node *hin,*sin,*sout,*hout;
	emq=creat();
	inq=NULL;
	outq=NULL;
	print_buf(emq,inq,outq);
	printf("\n######################\n");
	printf("what do you want to do?\n");
	printf("1. ��������\n");
	printf("2. �������\n");
	printf("3. �������\n");
	printf("4. ������\n");
	printf("5. �˳�\n");
	printf("\nInput your choice:\n");
	scanf("%d",&flag);
	while(flag !=5)
	{
		switch(flag)
		{ //�����
		case 1: 
			{
				if(emq == NULL)
					printf("Empty buffer is empty! Error!");
				else
				{
					printf("��������--�����롰�������ݡ�:\t");
					emq = Getbuf(emq);
					hin = tempnode;
					scanf("%d",&hin->buf_data);
					hin->buf_type = -1;
					inq = Putbuf(inq, hin);
				}
				
				break;
			}
		case 2:
			{
				if(inq == NULL)
					printf("Input buffer is empty! Error!");
				else
				{
					printf("��ȡ����--�����������ݡ�:\t");
					inq = Getbuf(inq);
					sin = tempnode;
					printf("%d\n",sin->buf_data);//��ȡʹ��inq������
					sin->buf_data = -32768;
					sin->buf_type = 0;
					emq = Putbuf(emq, sin);
				}
				break;
			}
		case 3:
			{
				if(emq == NULL)
					printf("Empty buffer is empty! Error!");
				else
				{
					printf("�������--�����롰������ݡ�:\t");
					emq = Getbuf(emq);
					hout = tempnode;
					scanf("%d",&hout->buf_data);
					hout->buf_type = 1;
					outq = Putbuf(outq, hout);
					
				}
				break;
			}
		case 4:
			{
				if(outq == NULL)
					printf("Output buffer is empty! Error!");
				else
				{
					printf("��ȡ���--�������ȡ���ݡ�:\t");
					outq = Getbuf(outq);
					sout = tempnode;
					printf("%d\n",sout->buf_data);//��ȡʹ��outq������
					sout->buf_data = -32768;
					sout->buf_type = 0;
					emq = Putbuf(emq, sout);
				}
				break;
			}
		default: break;
		}
		print_buf(emq,inq,outq);
		printf("\n######################\n");
		printf("what do you want to do?\n");
		printf("1. ��������\n");
		printf("2. �������\n");
		printf("3. �������\n");
		printf("4. ������\n");
		printf("5. �˳�\n");
		printf("\nInput your choice:\n");
		scanf("%d",&flag);
	}
}