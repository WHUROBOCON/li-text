
#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdlib.h>
#include "inc/queue.h"
void queue_init(queue* queue)
{
    queue->arr[len]=(int*)malloc(4*len);//分配内存
    queue->start=queue->over=0;//初始化队列的r w
}
bool queue_empty(queue* queue)
{
    if(queue->over%len==queue->start%len==0)//判断队列是否空
    {return 1;}
    return 0;
}
bool queue_full(queue* queue)
{
    if(queue->over%len-queue->start%len==9)//判断队列是否满
    {return 1;}
    return 0;
}
bool queue_put(queue* queue,int* value)
{   
    if(queue->over%len-queue->start%len==9)//判断队列是否满
    {return 1;}
    queue->arr[queue->over%len]=*value;//放
    queue->over++;                      //w++
    return 0;
}
bool queue_out(queue* queue,int* value)
{
    if(queue->over%len==queue->start%len==0)//判断队列是否空
    {return 1;}
    *value=queue->arr[queue->start%len];//拿
    queue->start++;//R++
}
int main()
{
    int a=10;
    int b=20;
    int c=30;
    queue queue_t;//创建结构体
    queue_init(&queue_t);
    queue_put(&queue_t,&a);
    queue_put(&queue_t,&b);
    queue_put(&queue_t,&c);
    queue_out(&queue_t,&c);
    queue_out(&queue_t,&b);
    queue_out(&queue_t,&a);
    printf("%d %d %d",a,b,c);//打印
    return 0;
}
