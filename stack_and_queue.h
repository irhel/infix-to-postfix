#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "boolean.h"
#define STACKSIZE 1000
struct stack
{
		int size;
		int stack_buffer[STACKSIZE];
};
typedef struct stack* stack;

void push(stack p, int x)
{
		if(p->size == STACKSIZE)
		{
				fputs("Error, stack overflow.\n",stderr);
				abort();
		}
		p->stack_buffer[p->size++] = x;
}
int pop(stack p)
{
		if(p->size == 0)
		{
				fputs("Error, stack underflow.\n",stderr);
				abort();
		}
		return p->stack_buffer[--p->size];
}
bool empty_s(stack p)
{
		if(p->size==0)
				return true;
		return false;
}
stack init_stack(void)
{
		stack p = (stack)malloc(sizeof(struct stack));
		assert(p!=NULL);
		p->size = 0;
		return p;
}
int peek(stack p)
{
		if(p->size > 0)
		{
				int x = p->size - 1;
				return p->stack_buffer[x];
		}
		return -1;
}
#define MAXSIZE 1000
struct queue
{
		char queue_buffer[MAXSIZE];
		int front,count;
};
typedef struct queue * queue;
void enqueue(queue q, int x)
{
		if(q->count == MAXSIZE)
		{
				fputs("Queue overflow.\n",stderr);
				abort();
		}
		else
		{
				q->queue_buffer[(q->front+q->count)%MAXSIZE] = x;
				q->count++;
		}
}
char dequeue(queue q)
{
		if(q->count == 0)
		{
				fputs("Queue underflow.\n",stderr);
				abort();
		}
		else
		{
				char val = q->queue_buffer[q->front];
				q->front++;
				q->count--;
				if(q->front == MAXSIZE)
						q->front = 0;
				return val;		
		}
}
queue init_queue(void)
{
		queue p = (queue)malloc(sizeof(struct queue));
		assert(p!=NULL);
		p->count = 0;
		p->front = 0;
		return p;
}
bool empty_q(queue q)
{
		if(q->count==0)
				return true;
		return false;
}
