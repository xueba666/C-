#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED



#endif // FUNCTIONS_H_INCLUDED
void Add()//增加学生信息,用的是在文件末尾添加信息。
{
    //保存学生信息时，用的不是Save函数。
    FILE *fp;
    if((fp=fopen(position,"ab+"))==NULL)
    {
        printf("cannt find target file\n");
        exit(1);
    }


    int n,i,j=1;
    printf("输入增加学生的人数：");
    scanf("%d",&n);
    char ch[10]=" ";
    Clear();
    Format(5);
    for(i=1;i<=n;i++)//这里由于是要写入文件，所以可以从1开始。
    {
        printf("%-8d",j++);
        scanf("%lld",&arr[i].massage[0]);getchar();
        scanf("%s",arr[i].name);
        scanf("%d",&arr[i].massage[1]);getchar();
        scanf("%d",&arr[i].massage[2]);getchar();
        scanf("%d",&arr[i].massage[3]);getchar();

    }
    fwrite((void*)&arr[1],sizeof(student),n,fp);//注意，这个写入文件，是从下标1开始的。
    fclose(fp);

    Ask();

}

void Show()//显示学生信息
{
    //对原始信息进行读取，进而可以判断是否已经录入学生成绩
    int n=Read();
    if(n==-1)
    {
        printf("\n还未录入学生成绩\n");
        Ask();

    }
    else
    {
//如果能到这里，则说明已经录入过学生成绩。以下就是选择按照怎样的条件显示。
        quick_sort(0,n,0);//按照学号排名进行显示。
        Sum(n);
        Format(6);//调用标准化显示.功能性函数。
        Print(n);
        Ask();

    }

}

void Find()//查找某个学生
{
    int n,i;
    long long k;
    n=Read();
    Sum(n);

    printf("输入该学生的学号： ");
    scanf("%lld",&k);
    getchar();

    Clear();
    i=Find_2(n,k);//

    if(i==-1) printf("暂无该学生信息。\n");
    else
    {
        Format(6);
        Print_2(i);
    }

    Ask();
}

void Change()//修改学生成绩
{
    int n=Read(),cho;
    printf("输入要修改学生的学号：");
    long long k;
    scanf("%lld",&k);
    getchar();

    Clear();

    int i;
    i=Find_2(n,k);//记录下来学生的下标。
    if(i==-1) printf("暂无该学生成绩\n");
    else
    {
        printf("                             该学生原始成绩：\n");
        Format(6);
        Print_2(i);
        printf("*************************************************************************************\n\n");
        Menu_2();
        scanf("%d",&cho); getchar();
        printf("修改后的分数：");
        switch(cho)
        {
            case 1: scanf("%d",&arr[i].massage[1]); break;
            case 2: scanf("%d",&arr[i].massage[2]); break;
            case 3: scanf("%d",&arr[i].massage[3]); break;
        }

        Sleep(300);
        Clear();
        printf("修改完毕\n");
    }

    Sum(n);
    Save(n);
    Ask();
}

void Sort()//按照总成绩排序，显示并保存在文件中。
{
    int n=Read();//得到的是数组下标的最大值
    Sum(n);//求出每个学生的总成绩
//    int i,j,k;
    quick_sort(0,n,4);
//    Save_2(n); 我先不把它保存在排序的那个文件中了，感觉没有意义
 //   printf("已按总成绩降序排序\n");
    Sleep(300);
    Clear();
//显示学生成绩
    Format(6);
    Print(n);
    Ask();
}

void Choose(int n)//用switch函数来调用不同功能
{
    switch(n)
    {
    case 1 :
        Add();
        break;//增加学生信息
    case 2 :
        Find();
        break;//查找学生信息
    case 3 :
        Change();
        break;//修改学生信息
    case 4 :
        Sort();
        break;//按学号排序
    case 5 :
        Delete();
        break;//删除学生信息
    case 6 :
        Show();
        break; //查看全部学生信息
    }
}

void Delete()
{
    int n=Read(),i;
    long long k;
    printf("输入要删除的学生的学号：");
    scanf("%lld",&k);
    getchar();

    i=Find_2(n,k);
    if(i==-1) printf("暂无该学生信息\n");
    else
    {
        arr[i].record=0;
        Save(n);
        Sleep(500);
        printf("已删除该学生信息\n");
    }

    Ask();

}
void Menu()//开始界面
{
    printf("                 学生成绩管理系统\n");
    printf("**********************************************************\n");
    printf("***  1 增加学生信息                 2 查找学生信息     ***\n");
    printf("***  3 修改学生信息                 4 按学生成绩排序   ***\n");
    printf("***  5 删除学生信息                 6 查看全部学生信息 ***\n");
    printf("***                  0 退出系统                        ***\n");
    printf("**********************************************************\n");
    printf("输入选项\n");

    int n;//让用户输入的选项
    scanf("%d",&n);//输入选项
    getchar();
    int i;

    while(n<0||n>selection)
    {
        printf("请输入正确选项！\n");
        scanf("%d",&n);
        getchar();
    }
    if(n==0)
    {
        return;
    }
    else if(n>=1&&n<=selection)
    {
        system("cls");
        Choose(n);
    }

}
