#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdlib.h>
#define len 10                      //重定义长度
typedef struct queue               //重定义
{
    int arr[len];
    char start,over;
}queue;
void queue_init(queue* queue);    //函数声明
bool queue_empty(queue* queue);
bool queue_full(queue* queue);
bool queue_put(queue* queue,int* value);
bool queue_out(queue* queue,int* value);