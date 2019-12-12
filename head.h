#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED



#endif // HEAD_H_INCLUDED
#define N 600//ѧ������
#define selection 6//ѡ������
//#define position "C:\\Users\\123\\Desktop\\C_Homework2\\bin\\Debug\\����\\stu.data"
#define position "C:\\Users\\ACM\\Desktop\\C_Homework2\\bin\\Debug\\����\\stu.data"
char slep[]= "..........";
//int book[N]={0};//�ø������¼��ɾ����arr������±꣬Ϊ1����Ϊ������Ԫ�ر�ɾ����

typedef struct
{
    char name[20];
    long long massage[5];//0��ѧ�š�1��C�ɼ���2��java�ɼ���3��force�ɼ���4��ѧ���������ܳɼ���
    int record;//���ڼ�¼ѧ���Ƿ�ɾ����1Ϊ����״̬��0Ϊ��ɾ��״̬��
} student;

student arr[N];//����ȫ�ֱ������飬�洢ѧ����Ϣ��

void quick_sort(int low,int high,int b)//���ţ����ո������±�b�ĺ�������
{
    if(low>=high)
        return ;
    int i,j;
    student tmp,k;
    i=low;
    j=high;
    k=arr[low];
    while(i<j)
    {


        while(arr[j].massage[b]<=k.massage[b]&&j>i)
            j--;
        while(arr[i].massage[b]>=k.massage[b]&&j>i)
            i++;

        if(j>i)
        {
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
        }
    }
    arr[low]=arr[i]; arr[i]=k;
    quick_sort(low,i-1,b);
    quick_sort(i+1,high,b);
    return ;
}
void In()//��ѧ��״̬��Ϊ�Ѷ���
{
    int i;
    for(i=0; i<N; i++)
        arr[i].record=1;
}

void Back()//�����ຯ�����˳�ϵͳ�Ľ���
{
    system("cls");
    printf("\n\n\n");
    printf("        �����˳�ϵͳ");
    int i;
    for(i=1; i<=6; i++)
    {
        Sleep(300);
        printf("%c",slep[i]);
    }
}

void Ask()//�����ຯ����ѯ���û��Ƿ�Ҫ������ע�⣬ÿ����һ�����ܣ���Ҫѯ���û��Ƿ������
{
    int key;
    printf("�Ƿ�Ҫ�˳���(����0���˳�������1���������˵�)\n");
    scanf("%d",&key);
    getchar();

    if(key==0)
        return;
    else
    {
        system("cls");
        Menu();
    }
}

int Read()//�����ຯ������ȡ�ļ��е�ѧ����Ϣ������������ص���arr���һ��Ԫ�ص��±ꡣ
{
    FILE *fp;
    if((fp=fopen(position,"rb"))==NULL)
    {
        printf("cannt find target file\n");
        exit(1);
    }
    int i=0;
    while(fread((void *)&arr[i],sizeof(student),1,fp)!=0)//���fread����ʲôҲû�ж������ͽ�����ȡѧ����Ϣ��
    {
        i++;
    }
    fclose(fp);

    return i-1;//�����������ͳ���ļ���ѧ����Ϣ���Ĺ��ܡ�
}


void Save(int n)//�����ຯ�������ڴ������Ϣд���ļ�������n���������Ϣ�������±ꡣ
{
    FILE *fp;
    if((fp=fopen(position,"wb"))==NULL)
    {
        printf("cannt find file");
        exit(1);
    }
    else
        fwrite((void *)arr,sizeof(student),n+1,fp);

    fclose(fp);
}

void Format(int i)//�����ຯ������ʾ��ͷ��
{
    char str[][50]={"���","ѧ��","����","C����","Java","������","�ܳɼ�"};
    if(i==6)
    printf("%-8s%-15s%-15s%-11s%-9s%-10s%-10s\n",str[0],str[1],str[2],str[3],str[4],str[5],str[6]);
    else
    printf("%-8s%-15s%-15s%-11s%-9s%-10s\n",str[0],str[1],str[2],str[3],str[4],str[5]);
}
void Clear()//�����ຯ��������ר�á�
{
    system("cls");
}
void Print(int n)//�����ຯ�����������ȫ��ѧ����Ϣ��
{
    int j=1,i;
    for(i=0; i<=n; i++)
    {
        if(arr[i].record == 1)
        {
            printf("%-8d",j++);
            printf("%-15lld",arr[i].massage[0]);
            printf("%-15s",arr[i].name);
            printf("%-11d",arr[i].massage[1]);
            printf("%-11d",arr[i].massage[2]);
            printf("%-9d",arr[i].massage[3]);
            printf("%-11d\n",arr[i].massage[4]);
        }

    }

}

void Sum(int n)//�����ຯ����������ÿλѧ���������ܳɼ���
{
    int i,j;
    for(i=0;i<=n;i++)
        arr[i].massage[4]=0;
    for(i=0;i<=n;i++)
        for(j=1;j<=3;j++)
        {
            arr[i].massage[4]+=arr[i].massage[j];
        }
}

int Find_2(int n,long long num)//���ڲ���ĳ��ѧ�����βηֱ���ѧ����������Ҫ�ҵ�ѧ�š�
{
    int i;
    for(i=0;i<=n;i++)
    {
        if(num==arr[i].massage[0]&&arr[i].record==1)
            return i;//���ظ�ѧ�����±ꡣ
    }

    if(i==n+1) return -1;//��ʾû���ҵ���ѧ����
}
void Print_2(int i)//������ʾĳ��ѧ����Ϣ���β����Ǹ�ѧ�����±ꡣ
{
    int j;
    if(arr[i].record==1)
    {
        j=1;
        printf("%-8d",j++);
        printf("%-15lld",arr[i].massage[0]);
        printf("%-15s",arr[i].name);
        printf("%-11d",arr[i].massage[1]);
        printf("%-11d",arr[i].massage[2]);
        printf("%-9d",arr[i].massage[3]);
        printf("%-11d\n",arr[i].massage[4]);
    }
    else
        printf("��ѧ���ѱ�ɾ��\n");
}
void Menu_2()
{
    printf("������Ҫ�޸ĵĿ�Ŀ��\n");
    printf("1 C����   2 Java   3 ������ѧ\n");

}
