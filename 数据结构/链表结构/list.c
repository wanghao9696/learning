#include<stdlib.h>

typedef struct
{
    char key[10];
    char name[20];
    int age;
}Data;

typedef struct Node
{
    Data nodeData;
    struct Node * nextNode;  
}CLType;

CLType *CLAddEnd(CLType *head, Data nodeData)
{
    CLType *node, *htemp;
    // 先判断申请内层是否成功
    if(!(node = (CLType *)malloc(sizeof(CLType))))
    {
        printf("分配内存失败!\n");
        return NULL;
    }
    else
    {
        // 给要添加的尾结点数据部分和指针部分赋值
        node->nodeData = nodeData;
        node->nextNode = NULL;
        // 判断原始链表是否为空链表
        if(head == NULL)
        {
            head = node;
            return head;
        }
        htemp = head;
        // 从头部开始遍历，一直找到指针为空的尾结点的前一个结点
        while (htemp->nextNode != NULL)
        {
            htemp = htemp->nextNode;
        }
        // 将新的结点指针，赋值给原始链表的尾指针
        htemp->nextNode = node;
        return head;      
    }
}

CLType *CLAddHead(CLType *head, Data nodeData)
{
    CLType *node;
    if(!(node = (CLType *)malloc(sizeof(CLType))))
    {
        printf("申请内存失败！");
        return NULL;
    }
    node->nodeData = nodeData;
    node->nextNode = head;

    return node;
}

CLType *CLFindNode(CLType *head, char *key)
{
    CLType *htemp;
    htemp = head;
    while(htemp)
    {
        if(htemp->nodeData.key == key)
        {
            return htemp;
        }
        htemp = htemp->nextNode; 
    }
    return NULL;
}