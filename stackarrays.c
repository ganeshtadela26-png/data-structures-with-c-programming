//stack using arrays we are not deleting just assuming
#include<stdio.h>
#include<stdlib.h>
#define max 9
int top=-1;
int stack[max];
void push(){
        if(top==max){
        	printf("stack overflow");
		}
		else{
			printf("enter data to push");
			scanf("%d",&stack[top+1]);
			top++;
		}
    }
void pop(){
	if(top==-1)
	printf("stack underflow");
	else{
		printf("data deleted is %d",stack[top]);
		top--;
	}
}
void display(){
    int x=top;
	if(top==-1){
		printf("no data to display");
	}
	else{
		while(top!=-1){
			printf("%d",stack[top]);
			top--;
		}
	}
    top=x;
}
int main(){
	int n;
    while(1){
    printf("enter the number:\n1.push\n2.pop\n3.display\n4.quit\n");
    scanf("%d",&n);
    switch(n){
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        display();
        break;
        case 4:
        printf("quit");
        return 0;
        default:
        printf("invalid input");
        break;
    }
    }
	return 0;
}