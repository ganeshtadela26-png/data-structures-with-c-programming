#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char stack[100];
int top = -1;
void push (char ch )
{
    top++;
    stack[top] = ch;
}
char pop()
{
	if(top!= -1)
	return stack[top--];
	else
	{
		printf("Error");
		exit(1);
	}
}
int priority(char temp)
	{
		if(temp =='(')
		return 0;
		else if(temp=='+'||temp =='-')
		return 1;
		else if(temp=='*'|| temp=='/')
		return 2;
		else if(temp=='^')
		return 3;
		else 
		return 0;
	}
int main()
{
	char string[100], *ptr, x;
	printf("Enter the expression: ");
	gets(string);
	ptr=string;
	while(*ptr!='\0')
	    {
		if(isalnum(*ptr))
		    printf("%c", *ptr);
		    else if(*ptr=='(')
		    push(*ptr);
		    else if(*ptr==')'){	
		    while (( x=pop())!='(')
			    {
		            printf("%c", x);
	            } 
	    }	
	    else 
	    {
		    while(priority(stack[top])>= priority(*ptr))
			    {
			        printf("%c", pop());
			        
		        }
		        push(*ptr);
	    }
	    ptr++;
	}
	while(top!= -1)
	    {
		    printf("%c", stack[top]);
		    top--;
	    }
}
