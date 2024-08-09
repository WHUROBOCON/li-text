
#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "inc/stack.h"
void stack_init(stack_t* stack,stack_size_t size)
{
    stack->stack_over=stack->stack_start=(int*)(malloc(size)+size);//分配内存并初始化栈顶与栈底
    stack->size=size;//定义大小
}
bool stack_empty(stack_t* stack)
{
    if(stack->stack_over=stack->stack_start)//判断是否空
    {return 1;}
    return 0;
}
bool stack_full(stack_t* stack)
{
    if(stack->stack_start-stack->stack_over==stack->size)//判断是否满
    {return 1;}
    return 0;
}
bool stack_put(stack_t* stack,int* value,int stack_size_t)
{
    if(stack->stack_over-(stack->stack_over-stack->stack_start)<stack_size_t)//判断是否满
    {return 1;}
    stack->stack_start-=stack_size_t;//移动
    *stack->stack_start=*value;//赋值
    return 0;
}
bool stack_out(stack_t* stack,int* value,int stack_size_t)
{
    if((stack->stack_start+stack_size_t)>stack->stack_over)//判断是否空
    {return 1;}
    *value=*stack->stack_start;//赋值
    stack->stack_start+=stack_size_t;//移动
    return 0;
}
int main()
{
    int a=10;
    int b=20;
    int c=30;
    stack_t stack;
    stack_init(&stack,12);
    stack_put(&stack,&a,1);
    stack_put(&stack,&b,1);
    stack_put(&stack,&c,1);
    stack_out(&stack,&a,1);
    stack_out(&stack,&b,1);
    stack_out(&stack,&c,1);
    printf("%d\n %d\n %d\n",a ,b ,c);
    return 0;
}