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
int List[N]; // ��Ű�ȫ���е��±�����
void initial()
// ������ʼ״̬�������� Resource ��Max �� �� Allocation ���ټ���� Need ��Available ��
{
	printf("Resourse--����M����Դ������\n");
	int i,j;
	for (i=0;i<3;i++){
		scanf("%d",&Resource[i]);
		Available[i] = Resource[i];
	}
	printf("Max--����N�����̷ֱ��M����Դ�������������\n");
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			scanf("%d",&Max[i][j]);
		printf("Allocation--����N�����̻��M����Դ��������\n");
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
// �����ǰ��״̬��|Process |Max |Allocation |Need |Available |
{
	printf("״̬��\n");
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
// ����ͬʱ������������{ ��Finish[i]=false;  ��Need[i][j] ��Work[j]}�� �Ľ����±� i( �޸�
//Finish[i]=true) �����򷵻�-1 ��
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
//̬ �ж���ǰ״̬�Ƿ�Ϊ��ȫ״̬ ������ true �� �� false �����Ѱ�ȫ���е��±���� List[N] ���顣
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
// �����ȫ���б�|Process |Work |Need |Allocation |Work+Alloc |Finish |
{
    int i;

    printf("��ȫ�������£�\n");
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
// ��ʾ�� i  ���������� M  ����Դ request[M]
{
	bool flag,flag1;
	int j;

	flag = false;
	flag1 = false;
	//Step1:  �ж����� Request[j] ��Need[i][j]
	for (j=0;j<3;j++)
        if (request[j]>Need[i][j]){
            flag = true;
            break;
    }
    if (flag)
        printf("�������\n");
    if (!flag){
        for (j=0;j<3;j++)
            if (request[j]>Available[j]){
                flag1 = true;
                printf("����������Դ����%d�����������\n",i);
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
                    printf("�ǰ�ȫ״̬������ɹ���\n");
                    printList();
                    printf("\n");
                }
            else {
                printf("�����ڰ�ȫ���У����ǰ�ȫ״̬��\n");
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
		while(reqid>=0 && reqid<N) //������� id �Ƿ�Ϸ�
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


