#include<stdio.h>
#include<string.h>

#define MAXLEN 100

typedef struct
{
    char key[10];
    char name[20];
    int age;
}DATA;

typedef struct
{
    DATA ListData[MAXLEN + 1];
    int ListLen;
}SLType;

void SLInit(SLType* SL)
{
    SL->ListLen = 0;
}

int SLLength(SLType* SL)
{
    return SL->ListLen;
}

int SLInsert(SLType* SL, int n, DATA data)
{
    if(SL->ListLen >= MAXLEN)
    {
        printf("顺序表已满，不能插入结点！\n");
        return 0;
    }
    if(n<1 || n>SL->ListLen)
    {
        printf("插入元素序号错误，插入失败！\n");
        return 0;
    }
    for(int i=SL->ListLen; i>=n; i--)
    {
        SL->ListData[i+1] = SL->ListData[i];
    }
    SL->ListData[n] = data;
    SL->ListLen++;
    return 1;
}

int SLAdd(SLType* SL, DATA data)
{
    if(SL->ListLen >= MAXLEN)
    {
        printf("顺序表已满，不能插入结点！\n");
        return 0;
    }
    SL->ListData[SL->ListLen] = data;
    SL->ListLen++;
    return 1;
}

int SLDelete(SLType* SL, int n)
{
    if(n<1 || n>SL->ListLen)
    {
        printf("删除元素序号错误，删除失败！\n");
        return 0;
    }
    for(int i=n; i<SL->ListLen; i++)
    {
        SL->ListData[i] = SL->ListData[i+1];
    }
    SL->ListLen--;
    return 1;
}

DATA* SLFindByNum(SLType* SL, int n)
{
    if(n<1 || n>SL->ListLen)
    {
        printf("结点序号错误，返回结点失败！\n");
        return 0;
    }
    return &(SL->ListData[n]);
}

int SLFindByCont(SLType* SL, char* key)
{
    for(int i=0; i<=SL->ListLen; i++)
    {
        if(strcmp(SL->ListData[i].key, key) == 0)
        {
            return i;
        }
    }
    return 0;
}

int SLAll(SLType* SL)
{
    for(int i=0; i<=SL->ListLen; i++)
    {
        printf("(%s, %s, %d)\n", SL->ListData[i].key, SL->ListData[i].name, SL->ListData[i].age);
    }
    return 0;
}

int main()
{
    int i;
    SLType SL;
    DATA data;
    DATA* pdata;
    char key[10];

    printf("顺序表操作演示：\n");
    SLInit(&SL);
    printf("顺序表初始化完成！\n");

    return 0;
}
