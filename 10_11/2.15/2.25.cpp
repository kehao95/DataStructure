//链表结构线性表
//////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*定义List与Node*/
#define ElemType char
struct LNode
{
    ElemType data;
    struct LNode *next;
};//结构体LNode定义结束
typedef LNode* LinkList;

/*定义所有异常状态*/
typedef int State;
#define OK          1
#define ERROR       0
#define OVERFLOW    -1


/*基本操作*/
//初始化操作

State initList(LinkList &L);
//无
//创建一个表

//销毁操作

State destroyList(LinkList &L);
//表存在
//销毁表 L==NULL

//加工型操作

State clearList(LinkList &L);
//表存在
//清空表至一个空头节点   
State pushbackElem(LinkList &L, ElemType e);
//表存在
//元素插入表末端
State insertElem(LinkList &L,ElemType e, int n);
//表存在,0 <= N <= ListLength 
//元素插入第N个元素后

//引用型操作

int getLength(LinkList L);
//表存在
//返回表长度
ElemType getElem(LinkList L, int N);
//表存在 1<= N <= listLength 
//返回第N元素
void castList(LinkList L);
//表存在
//输出表第一行表的元素数目 第二行表的实际元素
LinkList getLastNode(LinkList L);
//表存在
//返回表的最后一个节点的地址若无节点则返回NULL
LinkList getNode(LinkList L,int n);
//表存在
//返回第N个节点 若节点不存在或数字错误则返回空指针
LinkList findElem(LinkList L,ElemType e);
//表存在
//返回包含此元素的节点指针若不存在则返回NULL



State init(LinkList &L)
{
    L = new LNode;
    if (NULL == L)
    {
        return OVERFLOW;
    }
    L->next = NULL;
    return OK;
}

State destroyList(LinkList &L)
{
    while (L != NULL)
    {//node >0
        while (L->next != NULL)
        {//node > 1 则删除最后一个节点
            LinkList p = L;
            while (p->next->next != NULL)
            {//p不指向倒数第二个
                p = p->next;
            }
            delete p->next;
            p->next = NULL;
        }
        delete L;
        L = NULL;
    }
    return OK;
}

State clearList(LinkList &L)
{
    destroyList(L);
    init(L);
    return OK;
}
State pushbackElem(LinkList &L, ElemType e)
{
    if (NULL == L)
    {
        return ERROR;
    }
    LinkList p = L;
    while (NULL != p->next)  
    {
        p = p->next;
    }
    p->next = new struct LNode;
    p->next->data = e;
    p->next->next = NULL;
    return OK;
}
State insertElem(LinkList &L,ElemType e, int n)
{
    LinkList p;
    p = getNode(L,n);
    if (p == NULL)
    {
        return ERROR;
    }
    else
    {
        p->data = e;
        return OK;
    }
}

int getLength(LinkList L)
{
    int n = 0;
    if (NULL == L)
    {
        return -1;
    }
    LinkList p = L;
    while (p->next != NULL )
    {
        p = p->next;
        n++;
    }
    return n;
}
ElemType getElem(LinkList L, int N)
{

    int length = getLength(L);
    if (N < 1)
    {
        N = 1;
    }
    if (N > length)
    {
        N = length;
    }
    int i = 0;
    LinkList p = L->next;
    for (i = 1;i < N;i++)
    {
        p= p->next;
    }
    return p->data;
}
void castList(LinkList L)
{
    LinkList  p = L;
    int n = 0;
    p = p->next;
    if (p == NULL)
    {
        //        printf("0");
    }
    else
    {
        //       cout<<getLength(L)<<endl;
    }
    for (n = 0;p != NULL;n++)
    {
        cout<<(p->data)<<" ";
        p = p->next;
    }

}
LinkList getLastNode(LinkList L)
{
    if (NULL == L)
    {
        return NULL;
    }
    LinkList p = L;
    while (NULL != p->next)  
    {
        p = p->next;
    }
    return p;
}
LinkList getNode(LinkList L,int n)
{
    if ((n <= 0)||(n > getLength(L)))
    {
        return NULL;
    }
    int i = 0;
    LinkList p= L;
    for (i = 0;i < n;i++)
    {
        p = p->next;
    }
    return p;
}
LinkList findElem(LinkList L,ElemType e)
{
    if (NULL == L)
    {
        return NULL;
    }
    LinkList p = L->next;
    while(p != NULL)
    {
        if (e == p->data )
        {
            return p;
        }
    }
    return p;
}

int main()
{
    LinkList L1,L2;
    init(L1);
    init(L2);

    int length;
    ElemType temp;
    
    cin>>length;
    for (int i = 0; i < length; i++)
    {
        cin>>temp;
        pushbackElem(L1,temp);
    }

    cin>>length;
    for (int i = 0; i < length; i++)
    {
        cin>>temp;
        pushbackElem(L2,temp);
    }

   LinkList L,p1,p2;
   p1 = L1->next;
   p2 = L2->next;
   init(L);
   while ((p1 != NULL)&&(p2 != NULL))
   {
	   ElemType e1 = p1->data;
	   ElemType e2 = p2->data;
	   if (e1 == e2)
	   {
		   pushbackElem(L,e2);
		   if (p1->next != NULL)
		   {
			   p1 = p1->next;
		   }
           if (p2->next != NULL)
           {
               p2 = p2->next;
           }
           continue;
	   } 
	   else if(e1 <= e2)
	   {
		   if(p1->next == NULL) break;
           p1 = p1->next;
		   continue;
       }else
       {
           if(p2->next == NULL) break;
           p2 = p2->next;
           continue;
       }       

   }


    castList(L);
    destroyList(L1);
    destroyList(L2);
	destroyList(L);
}











