#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdlib.h>
typedef struct list_base
{   struct list_node* begin;
    struct list_node* end;
    
}list_base;
typedef struct list_node
{
   struct list_node* next;
   struct list_node* pre;
    int data;
}list_node;
void list_init(list_base* list);
void list_put(list_base* list, list_node* node,int a);
void list_out(list_base* list,int a);
bool list_search(list_base* list,int num);
void list_clear(list_base* lise);


    

