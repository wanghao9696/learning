#include<stdlib.h>
#include<stdio.h>

#define MANLEN 20

typedef char DATA;
// typedef struct
// {
//     char ch;
// }DATA;
typedef struct CBT
{
    DATA data;
    struct CBT * left;
    struct CBT * right;
}CBTType;

// 初始化二叉树
CBTType * InitTree()
{
    CBTType * node;

    if(node = (CBTType *)malloc(sizeof(CBTType)))
    {
        printf("请先输入一个根结点数据：\n");
        scanf("%s", &node->data);
        node->left = NULL;
        node->right = NULL;
        if(node != NULL)
        {
            return node;
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
}

// 添加结点
void AddTreeNode(CBTType * treeNode)
{
    CBTType *pnode, *parent;
    DATA data;
    char menusel;

    if(pnode=(CBTType *)malloc(sizeof(CBTType)))
    {
        printf("请先输入一个二叉树结点数据：\n");
        fflush(stdin);
        scanf("%s", &data);
    }
}