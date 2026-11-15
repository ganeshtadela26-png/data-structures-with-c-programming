#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int top=-1;
char stack[100];

	int priority(char temp)
	{
		if(temp=='(')
		return 0;
		else if(temp=='+'||temp=='-')
		return 1;
		else if(temp=='*'||temp=='/')
		return 2;
		else 
		return 0;
	}
	char pop()
		{
			if(top==-1){
				printf("Error !");
				exit(0);
			}
			else
			return stack[top--];
		}
void push(char temp ){
	top++;
	stack[top]=temp;
}
void main()
{
	char string[100],*ptr,x;
	printf("enter the infix Expression :");
	fgets(string,100,stdin);
	ptr=string;
	while(*ptr!='\0')
	{
		if(isalnum(*ptr))
		printf("%c",*ptr);
		else if(*ptr=='(')
		push(*ptr);
		else if(*ptr==')')
		{
			while(top!=-1 && (x=pop())!='(')
			printf("%c",x);
		}
		else
		{
			while(top!=-1 && priority(stack[top])>=priority(*ptr)){
				printf("%c",pop());
			} 
			push(*ptr);
		}
		ptr++;
	}
	while(top!=-1){
		printf("%c",pop());
	}
}
