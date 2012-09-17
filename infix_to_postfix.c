#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack_and_queue.h"
bool operand(char x)
{
		if(x == '*' || x == '-' || x == '/' || x == '+')
				return false;
		return true;
}
short higher_precedence(char o1, char o2)
{
		if(o1 == '*' || o1 == '/')
		{
				if(o2 == '/' || o2 == '*')
						return 0;
				return 1;	
		}
		if(o1 == '+' || o1 == '-')
		{
				if(o2 == '*' || o2 == '/')
						return -1;
				return 0;		
		}
		return -1;
}	
int main(void)
{
		char val;
		char input[1000];
		fgets(input, 1000, stdin);
		input[strlen(input)-1] = '\0'; 
		char *token = strtok(input, " ");
		queue input_queue,output_queue;
		input_queue = init_queue();
		output_queue = init_queue();
		stack operators = init_stack();
		while(token!=NULL)
		{
				enqueue(input_queue,0[token]);
				token = strtok(NULL," ");
		}
		while(!empty_q(input_queue))
		{
				val = dequeue(input_queue);
				if(operand(val))
				{
						enqueue(output_queue,val);
				}
			    else
				{
						
						if((higher_precedence(peek(operators),val)==1) || (higher_precedence(peek(operators),val)==0))
						{
								while(!empty_s(operators))
								{
										enqueue(output_queue,pop(operators));
								}
						}
						push(operators,val);
				}
		}
		while(!empty_s(operators))
		{
				enqueue(output_queue,pop(operators));
		}
		while(!empty_q(output_queue))
		{
				printf("%c",dequeue(output_queue));
		}
		printf("\n");
		free(input_queue);
		free(output_queue);
		free(operators);
		return 0;
}
/*
NOTE:
@Change the name of is_empty() to empty(). DONE
@Add a empty() function to queue.h. DONE
@Write a makefile for compilation. 
@Add a function calculate to calculate the expression. 
*/

