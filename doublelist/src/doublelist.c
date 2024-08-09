#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void list_init(list_base* list)
{
    list->begin=(list_node*)malloc(sizeof(list_node));
    list->end=(list_node*)malloc(sizeof(list_node));
   list->begin->next=list->begin->pre=list->end;
   list->end->next=list->end->pre=list->begin;
 
}
void list_put(list_base* list, list_node* node,int a)
{
    list_node* l=list->begin;
    while(l->next!=list->end&&a-->0)
    {l=l->next;}
    node->next=l->next;
    node->pre=l;
    l->next->pre=node;
    l->next=node;
    printf("%d\n",node->data);
}

void list_out(list_base* list,int a)
   { list_node* l=list->begin;
    while(l->next!=list->end&&a-->0)
    {l=l->next;}
    list_node* def=l->next;

  def->pre->next = def->next;//断联
  def->next->pre = def->pre;
  def->next = NULL;
  def->pre = NULL;
    printf("%d\n", def->data);
    
  
}
bool list_search(list_base* list,int num)
{
    list_node* l=list->begin;
    while(l->next=!list->end)
    {
        l=l->next;
        if(l->data=num)
        {return 1;}
    }
    return 0;
}
void list_clear(list_base* list)
{
    free(list->begin);
    free(list->end);
}
int main()
{
     list_base l;

  list_node node1;
  node1.data = 1;
  list_node node2;
  node2.data = 2;
  list_node node3;
  node3.data = 3;

  list_init(&l);
  list_put(&l, &node1,0);
  list_put(&l, &node2,0);
  list_put(&l, &node3,0);

  // 3 2 1
  list_out(&l, 1);// 2 : 3 1
  list_out(&l, 0);// 3 : 1
  list_out(&l, 0);// 1

  list_clear(&l);
  return 0;
}