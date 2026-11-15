//queue using array
#include<stdio.h>
#include<stdlib.h>
#define max 100
int front=-1;
int rear=-1;
int data;
int queue[max];
void enqueue(){
	if(rear==max-1){
		printf("queue overflow\n");
	}
	else{
		printf("enrer data to push:\n");
		scanf("%d",&queue[++rear]);
		if(front==-1)
		front++;
	}
}
void dequeue(){
	if(front==-1)
	printf("queue underflow\n");
	else if(front==rear){
		printf("data deleted is %d\n",queue[front]);
		front=rear=-1;
	}
	else{
		printf("data deleted is %d\n",queue[front]);
		front++;
		
	}
}
void display(){
	if(front==-1){
		printf("no data to display\n");
	}
    else{
    	while(front<=rear){
		printf("%d",queue[front]);
		front++;
	}
	front=rear=-1;
	}
}
int main(){
    int n;
    while(1){
    	printf("enter number:\n1.enqueue,2.dequeue,3.display,4.quit:\n");
    	scanf("%d",&n);
    	switch(n){
    		case 1:
    			enqueue();
    			break;
    		case 2:
    			dequeue();
    			break;
    		case 3:
    			display();
    			break;
    		case 4:
    			printf("quit\n");
    			return 0;
    		default:
    			printf("invalid input\n");
    			break;
		}
	}
	return 0;
}