/* 11:52 2015-04-10 Friday */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"


LinkGraph **Create_Graph_List()
{
    int i = 0;
    LinkGraph **g;

    g = (LinkGraph **)malloc(N * ADDR_LEN);

    for (i = 0; i < N; i++)
    {
        g[i] = (LinkGraph *)malloc(sizeof(LinkGraph));
        g[i]->v = i;
        g[i]->next = NULL;
    }

    return g;
}

int Insert_Order_List(LinkGraph *g,VTYPE data)
{
    LinkGraph *q;
    LinkGraph *p;
    LinkGraph *new;

    q = g;
    p = g->next;

    while (p)
    {
        if (p->v > data)
        {
            break;
        }
        else
        {
            q = q->next;
            p = p->next;
        }
    }
    new = (LinkGraph *)malloc(sizeof(LinkGraph));
    new->v = data;

    new->next = q->next;
    q->next = new; 

    return 0;
}

int Input_Graph_Edge(LinkGraph **g)
{
    int i,j;

    while (scanf("<V%d,V%d>",&i,&j) == 2)
    {
        getchar();//����ո� 
        Insert_Order_List(g[i],j);
    }

    //�������
    while (getchar() != '\n');

    return 0;
}

int One_Graph_List(LinkGraph *g)
{
    while (g)    
    {
        printf("V%d ",g->v);
        g = g->next;
    }
    return 0;
}
int Print_Graph_List(LinkGraph  **g)
{

    int i = 0;

    for (i = 0; i < N; i++)
    {
        One_Graph_List(*(g+i));
        printf("\n");
    }

    return 0;
}

int visited[N];

void BFS(LinkGraph **g,VTYPE v)
{
    LinkQueue *q = create_linkqueue();
    LinkGraph *pg;
    visited[v] = 1;
    enter_linkqueue(q,v);

        printf("==========================\n");
    while (!is_empty_linkqueue(q))
    {
        v = delete_linkqueue(q);
        printf("V%d ",v);

        pg = g[v]; 
        while (pg != NULL)
        {
            if (visited[pg->v] != 1)
            {
                visited[pg->v] = 1;
                enter_linkqueue(q,pg->v);
            }
            pg = pg->next;
        }
    }
    printf("\n");
    return;
}
