#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED



#endif // FUNCTIONS_H_INCLUDED
void Add()//����ѧ����Ϣ,�õ������ļ�ĩβ�����Ϣ��
{
    //����ѧ����Ϣʱ���õĲ���Save������
    FILE *fp;
    if((fp=fopen(position,"ab+"))==NULL)
    {
        printf("cannt find target file\n");
        exit(1);
    }


    int n,i,j=1;
    printf("��������ѧ����������");
    scanf("%d",&n);
    char ch[10]=" ";
    Clear();
    Format(5);
    for(i=1;i<=n;i++)//����������Ҫд���ļ������Կ��Դ�1��ʼ��
    {
        printf("%-8d",j++);
        scanf("%lld",&arr[i].massage[0]);getchar();
        scanf("%s",arr[i].name);
        scanf("%d",&arr[i].massage[1]);getchar();
        scanf("%d",&arr[i].massage[2]);getchar();
        scanf("%d",&arr[i].massage[3]);getchar();

    }
    fwrite((void*)&arr[1],sizeof(student),n,fp);//ע�⣬���д���ļ����Ǵ��±�1��ʼ�ġ�
    fclose(fp);

    Ask();

}

void Show()//��ʾѧ����Ϣ
{
    //��ԭʼ��Ϣ���ж�ȡ�����������ж��Ƿ��Ѿ�¼��ѧ���ɼ�
    int n=Read();
    if(n==-1)
    {
        printf("\n��δ¼��ѧ���ɼ�\n");
        Ask();

    }
    else
    {
//����ܵ������˵���Ѿ�¼���ѧ���ɼ������¾���ѡ����������������ʾ��
        quick_sort(0,n,0);//����ѧ������������ʾ��
        Sum(n);
        Format(6);//���ñ�׼����ʾ.�����Ժ�����
        Print(n);
        Ask();

    }

}

void Find()//����ĳ��ѧ��
{
    int n,i;
    long long k;
    n=Read();
    Sum(n);

    printf("�����ѧ����ѧ�ţ� ");
    scanf("%lld",&k);
    getchar();

    Clear();
    i=Find_2(n,k);//

    if(i==-1) printf("���޸�ѧ����Ϣ��\n");
    else
    {
        Format(6);
        Print_2(i);
    }

    Ask();
}

void Change()//�޸�ѧ���ɼ�
{
    int n=Read(),cho;
    printf("����Ҫ�޸�ѧ����ѧ�ţ�");
    long long k;
    scanf("%lld",&k);
    getchar();

    Clear();

    int i;
    i=Find_2(n,k);//��¼����ѧ�����±ꡣ
    if(i==-1) printf("���޸�ѧ���ɼ�\n");
    else
    {
        printf("                             ��ѧ��ԭʼ�ɼ���\n");
        Format(6);
        Print_2(i);
        printf("*************************************************************************************\n\n");
        Menu_2();
        scanf("%d",&cho); getchar();
        printf("�޸ĺ�ķ�����");
        switch(cho)
        {
            case 1: scanf("%d",&arr[i].massage[1]); break;
            case 2: scanf("%d",&arr[i].massage[2]); break;
            case 3: scanf("%d",&arr[i].massage[3]); break;
        }

        Sleep(300);
        Clear();
        printf("�޸����\n");
    }

    Sum(n);
    Save(n);
    Ask();
}

void Sort()//�����ܳɼ�������ʾ���������ļ��С�
{
    int n=Read();//�õ����������±�����ֵ
    Sum(n);//���ÿ��ѧ�����ܳɼ�
//    int i,j,k;
    quick_sort(0,n,4);
//    Save_2(n); ���Ȳ�����������������Ǹ��ļ����ˣ��о�û������
 //   printf("�Ѱ��ܳɼ���������\n");
    Sleep(300);
    Clear();
//��ʾѧ���ɼ�
    Format(6);
    Print(n);
    Ask();
}

void Choose(int n)//��switch���������ò�ͬ����
{
    switch(n)
    {
    case 1 :
        Add();
        break;//����ѧ����Ϣ
    case 2 :
        Find();
        break;//����ѧ����Ϣ
    case 3 :
        Change();
        break;//�޸�ѧ����Ϣ
    case 4 :
        Sort();
        break;//��ѧ������
    case 5 :
        Delete();
        break;//ɾ��ѧ����Ϣ
    case 6 :
        Show();
        break; //�鿴ȫ��ѧ����Ϣ
    }
}

void Delete()
{
    int n=Read(),i;
    long long k;
    printf("����Ҫɾ����ѧ����ѧ�ţ�");
    scanf("%lld",&k);
    getchar();

    i=Find_2(n,k);
    if(i==-1) printf("���޸�ѧ����Ϣ\n");
    else
    {
        arr[i].record=0;
        Save(n);
        Sleep(500);
        printf("��ɾ����ѧ����Ϣ\n");
    }

    Ask();

}
void Menu()//��ʼ����
{
    printf("                 ѧ���ɼ�����ϵͳ\n");
    printf("**********************************************************\n");
    printf("***  1 ����ѧ����Ϣ                 2 ����ѧ����Ϣ     ***\n");
    printf("***  3 �޸�ѧ����Ϣ                 4 ��ѧ���ɼ�����   ***\n");
    printf("***  5 ɾ��ѧ����Ϣ                 6 �鿴ȫ��ѧ����Ϣ ***\n");
    printf("***                  0 �˳�ϵͳ                        ***\n");
    printf("**********************************************************\n");
    printf("����ѡ��\n");

    int n;//���û������ѡ��
    scanf("%d",&n);//����ѡ��
    getchar();
    int i;

    while(n<0||n>selection)
    {
        printf("��������ȷѡ�\n");
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
