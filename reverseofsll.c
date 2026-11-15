#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *head=NULL,*tail=NULL,*ptr,*temp,*p,*link,*next;
int n,i=1,data,pos;
void create(){
	printf("enter no of nodes");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		ptr=(struct node*)malloc(sizeof(struct node));
		printf("enter data:");
		scanf("%d",&data);
		ptr->data=data;
		ptr->link=NULL;
		if(head==NULL){
			head=ptr;
			tail=ptr;
		}
	    else{
	    	tail->link=ptr;
	    	tail=ptr;
	    	
		}
}
}
void display(){
	temp=head;
	if(head==NULL)
	printf("no nodes");
	else{
		while(temp!=NULL){
			printf("%d",temp->data);
			temp=temp->link;
		}
	}
	
}
void rev()
{
    if (head == NULL || head->link == NULL)
        return;

    temp = head;
    p = temp;
    temp = temp->link;
    next = temp->link;

    while (temp != NULL)
    {
        temp->link = p;
        p = temp;
        temp = next;
        if (temp != NULL)
            next = temp->link;
    }

    head->link = NULL;
    tail = head;
    head = p;
}
int main(){
    create();
    display();
    rev();
    display();
    return 0;
}