#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdlib.h>
typedef unsigned int stack_size_t;
typedef struct stack_t
{   int* stack_start;
    int* stack_over;
    stack_size_t size;

} stack_t;
void stack_init(stack_t* stack,stack_size_t size);
bool stack_empty(stack_t* stack);
bool stack_full(stack_t* stack);
bool stack_put(stack_t* stack,int* value,int stack_size_t);
bool stack_out(stack_t* stack,int* value,int stack_size_t);
