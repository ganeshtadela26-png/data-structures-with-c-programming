//queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *head=NULL,*tail=NULL,*ptr,*temp,*p,*link,*p1;
int n,i=1,data,pos;
void display(){
	temp=head;
	if(head==NULL)
	printf("no data to display\n");
	else{
		while(temp!=NULL){
			printf("%d",temp->data);
			temp=temp->link;
		}
	}
	printf("\n");
}
//enqueue
void enqueue(){
	p=(struct node*)malloc(sizeof(struct node));
    printf("enter the data for ins at end:\n");
    scanf("%d",&data);
    p->data=data;
    p->link=NULL;
    if(head==NULL){
    	head=tail=p;
    }
    else{
    	tail->link=p;
    	tail=p;
	}
}
//dequeue
void dequeue(){
	if(head==NULL){
		printf("queue underflow\n");
	}
	else{
		p=head;
		head=head->link;
		free(p);
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