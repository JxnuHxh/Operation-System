#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Buff_MAX 10 // 初始 空闲缓冲区的个数
typedef struct buffernode
{
	int buf_type;
	//"0" 空闲缓冲区，"-1" 装输入数据的缓冲区，"1" 装输出数据的缓冲区
	int buf_data; // 循环区数据
	struct buffernode *next; // 指向下一个指针
}node;
// 全局变量
node *tempnode; 
/********************************************************************
create  函数说明: 建立空闲缓冲队列, 每个空闲缓冲区内的数据存放“-32768 ”。
返回值:  返回队列的头指针
********************************************************************/
node *creat( ) /* 建立空闲缓冲队列*/
{ //填补程序
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
print_buf  函数说明: 该函数打印 三个缓冲队列 的数据情况
返回值:  无
********************************************************************/
void print_buf(node *emq, node *inq, node *outq)
{ //填补程序
	node *p;
	p = emq;
	printf("\n空闲缓冲区队列emq内容：\n");
	while(p->next)
	{
		printf("%d\t",p->buf_data);
		p = p->next;
	}
	printf("\n\n输入缓冲区队列inq：\n");
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
	printf("\n\n输出缓冲区队列outq：\n");
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
Getbuf  函数说明: ， 该函数从队首读一个数据出来， 使用 tempnode  指向队首第一个结点
返回值: 队列指针 head
********************************************************************/
node *Getbuf(node *head)
{ //填补程序
	if(head == NULL)
		return NULL;
	tempnode = (node *) malloc (sizeof(node));
	tempnode = head;
	head = head->next;
	tempnode->next = NULL;
	return head;
}
/********************************************************************
Putbuf  函数说明:  该函 数从插入一个结点到队未。
返回值: 队列指针 head
********************************************************************/
node *Putbuf(node *head, node *newnode)
{ //填补程序
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
/**************MAIN  程序**********************/
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
	printf("1. 收容输入\n");
	printf("2. 提出输入\n");
	printf("3. 收容输出\n");
	printf("4. 提出输出\n");
	printf("5. 退出\n");
	printf("\nInput your choice:\n");
	scanf("%d",&flag);
	while(flag !=5)
	{
		switch(flag)
		{ //填补程序
		case 1: 
			{
				if(emq == NULL)
					printf("Empty buffer is empty! Error!");
				else
				{
					printf("收容输入--请输入“输入数据”:\t");
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
					printf("提取输入--输出“输出数据”:\t");
					inq = Getbuf(inq);
					sin = tempnode;
					printf("%d\n",sin->buf_data);//提取使用inq内数据
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
					printf("收容输出--请输入“输出数据”:\t");
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
					printf("提取输出--输出“提取数据”:\t");
					outq = Getbuf(outq);
					sout = tempnode;
					printf("%d\n",sout->buf_data);//提取使用outq内数据
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
		printf("1. 收容输入\n");
		printf("2. 提出输入\n");
		printf("3. 收容输出\n");
		printf("4. 提出输出\n");
		printf("5. 退出\n");
		printf("\nInput your choice:\n");
		scanf("%d",&flag);
	}
}