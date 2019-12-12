#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED



#endif // HEAD_H_INCLUDED
#define N 600//学生总数
#define selection 6//选择项数
//#define position "C:\\Users\\123\\Desktop\\C_Homework2\\bin\\Debug\\数据\\stu.data"
#define position "C:\\Users\\ACM\\Desktop\\C_Homework2\\bin\\Debug\\数据\\stu.data"
char slep[]= "..........";
//int book[N]={0};//用该数组记录被删除的arr数组的下标，为1则视为该数组元素被删除。

typedef struct
{
    char name[20];
    long long massage[5];//0是学号。1是C成绩。2是java成绩。3是force成绩。4是学生的三科总成绩。
    int record;//用于记录学生是否被删除。1为存在状态，0为被删除状态。
} student;

student arr[N];//定义全局变量数组，存储学生信息。

void quick_sort(int low,int high,int b)//快排，按照给定的下标b的含义排序。
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
void In()//将学生状态置为已读入
{
    int i;
    for(i=0; i<N; i++)
        arr[i].record=1;
}

void Back()//功能类函数：退出系统的界面
{
    system("cls");
    printf("\n\n\n");
    printf("        正在退出系统");
    int i;
    for(i=1; i<=6; i++)
    {
        Sleep(300);
        printf("%c",slep[i]);
    }
}

void Ask()//功能类函数：询问用户是否要继续。注意，每用完一个功能，就要询问用户是否继续。
{
    int key;
    printf("是否要退出？(按“0”退出，按“1”返回主菜单)\n");
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

int Read()//功能类函数：读取文件中的学生信息。这个函数返回的是arr最后一个元素的下标。
{
    FILE *fp;
    if((fp=fopen(position,"rb"))==NULL)
    {
        printf("cannt find target file\n");
        exit(1);
    }
    int i=0;
    while(fread((void *)&arr[i],sizeof(student),1,fp)!=0)//如果fread函数什么也没有读到，就结束读取学生信息。
    {
        i++;
    }
    fclose(fp);

    return i-1;//这个函数还有统计文件中学生信息数的功能。
}


void Save(int n)//功能类函数，将内存里的信息写到文件里。这里的n是最后有信息的数组下标。
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

void Format(int i)//功能类函数，显示表头。
{
    char str[][50]={"序号","学号","姓名","C语言","Java","理论力","总成绩"};
    if(i==6)
    printf("%-8s%-15s%-15s%-11s%-9s%-10s%-10s\n",str[0],str[1],str[2],str[3],str[4],str[5],str[6]);
    else
    printf("%-8s%-15s%-15s%-11s%-9s%-10s\n",str[0],str[1],str[2],str[3],str[4],str[5]);
}
void Clear()//功能类函数，清屏专用。
{
    system("cls");
}
void Print(int n)//功能类函数，用于输出全部学生信息。
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

void Sum(int n)//功能类函数，用于求每位学生的三科总成绩。
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

int Find_2(int n,long long num)//用于查找某个学生。形参分别是学生总数量和要找的学号。
{
    int i;
    for(i=0;i<=n;i++)
    {
        if(num==arr[i].massage[0]&&arr[i].record==1)
            return i;//返回该学生的下标。
    }

    if(i==n+1) return -1;//表示没有找到该学生。
}
void Print_2(int i)//用于显示某个学生信息。形参是那个学生的下标。
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
        printf("该学生已被删除\n");
}
void Menu_2()
{
    printf("请输入要修改的科目：\n");
    printf("1 C语言   2 Java   3 理论力学\n");

}
