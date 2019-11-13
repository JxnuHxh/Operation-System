#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define M 3
#define N 5
int Resource[M];
int Max[N][M];
int Allocation[N][M];
int Need[N][M];
int Available[M];
int Work[M];
int wa[5][3];
int rec;
bool Finish[N];
int List[N]; // 存放安全序列的下标序列
void initial()
// 创建初始状态：先输入 Resource 、Max 和 和 Allocation ，再计算出 Need 、Available 。
{
	printf("Resourse--输入M种资源数量：\n");
	int i,j;
	for (i=0;i<3;i++){
		scanf("%d",&Resource[i]);
		Available[i] = Resource[i];
	}
	printf("Max--输入N个进程分别对M种资源的最大需求量：\n");
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			scanf("%d",&Max[i][j]);
		printf("Allocation--输入N个进程获得M种资源的数量：\n");
		for (i=0;i<N;i++)
			for (j=0;j<M;j++){
				scanf("%d",&Allocation[i][j]);
				Available[j] = Available[j]-Allocation[i][j];
				Need[i][j] = Max[i][j]-Allocation[i][j];
			}
    for (i=0;i<5;i++)
        List[i] = 0;
    for (i=0;i<3;i++)
        Work[i] = Available[i];
}
void printState()
// 输出当前的状态表|Process |Max |Allocation |Need |Available |
{
	printf("状态表：\n");
	printf("|%-5s|%-5s          |%-5s     |%-5s          |%-5s\n","Process","Max","Allocation","Need","Available");
	int i;
	for (i=0;i<5;i++){
		if (i==0)
			printf("|P%d     |%-5d%-5d%-5d|%-5d%-5d%-5d|%-5d%-5d%-5d|%-5d%-5d%-5d\n",i,Max[i][0],Max[i][1],Max[i][2],
			Allocation[i][0],Allocation[i][1],Allocation[i][2],Need[i][0],Need[i][1],Need[i][2],Available[0],Available[1],Available[2]);
		else
			printf("|P%d     |%-5d%-5d%-5d|%-5d%-5d%-5d|%-5d%-5d%-5d|\n",i,Max[i][0],Max[i][1],Max[i][2],
			Allocation[i][0],Allocation[i][1],Allocation[i][2],Need[i][0],Need[i][1],Need[i][2]);
	}
}
int isfinish(int f)
// 返回同时满足两个条件{ ①Finish[i]=false;  ②Need[i][j] ≤Work[j]}标 的进程下标 i( 修改
//Finish[i]=true) ，否则返回-1 。
{
    int i,j;
    int flag;
for (i=0;i<5;i++){
        if (!Finish[i]){
            flag = 0;
            Finish[i] = true;
            for (j=0;j<3;j++)
                if (Need[i][j]>Work[j]){
                     flag = 1;
                     break;
                }
            if (flag==0){
                rec++;
                for (j=0;j<3;j++)
                    wa[i][j] = Work[j] = Work[j]+Allocation[i][j];
                List[f] = i;
                isfinish(f+1);
                if (rec==5)
                    return 5;
                rec--;
                List[f] = 0;
                for (j=0;j<3;j++)
                    Work[j] = Work[j]-Allocation[i][j];
            }
            Finish[i] = false;
        }
    }

    return -1;
}
bool issafe()
//态 判定当前状态是否为安全状态 （返回 true 或 或 false ），把安全序列的下标放入 List[N] 数组。
{
    int i;
    rec = 0;
    for (i=0;i<5;i++)
        Finish[i] = false;
	if (isfinish(0)==5)
        return true;
    else
        return false;
}
void printList()
// 输出安全序列表|Process |Work |Need |Allocation |Work+Alloc |Finish |
{
    int i;

    printf("安全序列如下：\n");
    printf("|%-8s     |%-8s                |%-8s                |%-8s              |%-8s              |%-8s\n","Process","Work",
           "Need","Allocation","Work+Alloc","Finish");
    for (i=0;i<5;i++){
        if (i==0)
            printf("|P%-12d|%-8d%-8d%-8d|%-8d%-8d%-8d|%-8d%-8d%-8d|%-8d%-8d%-8d%-8s\n",List[i],Available[0],
                   Available[1],Available[2],Need[List[i]][0],Need[List[i]][1],Need[List[i]][2],Allocation[List[i]][0],Allocation[List[i]][1],
                   Allocation[List[i]][2],wa[List[i]][0],wa[List[i]][1],wa[List[i]][2],"|true");
        else
            printf("|P%-12d|%-8d%-8d%-8d|%-8d%-8d%-8d|%-8d%-8d%-8d|%-8d%-8d%-8d%s\n",List[i],wa[List[i-1]][0],wa[List[i-1]][1],wa[List[i-1]][2],Need[List[i]][0],
                   Need[List[i]][1],Need[List[i]][2],Allocation[List[i]][0],Allocation[List[i]][1],
                   Allocation[List[i]][2],wa[List[i]][0],wa[List[i]][1],wa[List[i]][2],"|true");
    }
}
void reqresource(int i, int request[M])
// 表示第 i  个进程请求 M  类资源 request[M]
{
	bool flag,flag1;
	int j;

	flag = false;
	flag1 = false;
	//Step1:  判断条件 Request[j] ≤Need[i][j]
	for (j=0;j<3;j++)
        if (request[j]>Need[i][j]){
            flag = true;
            break;
    }
    if (flag)
        printf("分配错误！\n");
    if (!flag){
        for (j=0;j<3;j++)
            if (request[j]>Available[j]){
                flag1 = true;
                printf("尚无主够资源，第%d个程序堵塞。\n",i);
                break;
            }
        if (!flag1){
            for (j=0;j<3;j++){
                Need[i][j] = Need[i][j]-request[j];
                Allocation[i][j] += request[j];
                Available[j] -= request[j];
                Work[j] = Available[j];
            }
            if (issafe()){
                    printf("是安全状态，分配成功！\n");
                    printList();
                    printf("\n");
                }
            else {
                printf("不存在安全序列，不是安全状态。\n");
                for (j=0;j<3;j++){
                Need[i][j] = Need[i][j]+request[j];
                Allocation[i][j] -= request[j];
                Available[j] += request[j];
            }
            }
        }
    }
}
int main()
{
    int reqid=-1,j,req[M];

    initial();
    printState();
	if(issafe()==false)
	{
		printf("Initial state is unsafe!\n");
	}
	else
	{
		printf("\nInitial state is safe!\n");
		printList();
		printf("Input the id of request process:");
		scanf("%d",&reqid);
		while(reqid>=0 && reqid<N) //输入进程 id 是否合法
		{
			printf("Input request resources:");
			for(j=0;j<M;j++)
			{
				scanf("%d",&req[j]);
			}
			reqresource(reqid, req);
			printState();
			printf("Input the id of request process:");
			scanf("%d",&reqid);
		}
	}

	return 0;
}


