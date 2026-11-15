// creating a doubly linked list AND insertion
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head=NULL,*tail=NULL,*ptr,*temp,*p,*p1;

int n,i=1,data,pos;

// creating doubly linked list
void create(){
	printf("enter no of nodes: ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		ptr=(struct node*)malloc(sizeof(struct node));

		printf("enter data: ");
		scanf("%d",&data);

		ptr->data=data;
		ptr->prev=NULL;
		ptr->next=NULL;

		if(head==NULL){
			head=ptr;
			tail=ptr;
		}
		else{
			tail->next=ptr;
			ptr->prev=tail;
			tail=ptr;
		}
	}
}

// display
void display(){
	temp=head;

	if(head==NULL){
		printf("no nodes\n");
	}
	else{
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

// insertion at beginning
void inse_begin(){

	p=(struct node*)malloc(sizeof(struct node));

	printf("enter the data for ins at beg: ");
	scanf("%d",&data);

	p->data=data;
	p->prev=NULL;
	p->next=NULL;

	if(head==NULL){
		head=tail=p;
	}
	else{
		p->next=head;
		head->prev=p;
		head=p;
	}
}

// insertion at end
void inse_end(){

	p=(struct node*)malloc(sizeof(struct node));

	printf("enter the data for ins at end: ");
	scanf("%d",&data);

	p->data=data;
	p->prev=NULL;
	p->next=NULL;

	if(head==NULL){
		head=tail=p;
	}
	else{
		tail->next=p;
		p->prev=tail;
		tail=p;
	}
}

// insertion at middle
void inse_mid(){

	int i=1;

	printf("enter the position to insert: ");
	scanf("%d",&pos);

	if(pos<=1){
		inse_begin();
		return;
	}

	p=(struct node*)malloc(sizeof(struct node));

	printf("enter the data for middle: ");
	scanf("%d",&data);

	p->data=data;
	p->prev=NULL;
	p->next=NULL;

	temp=head;

	while(i<pos-1 && temp!=NULL){
		temp=temp->next;
		i++;
	}

	if(temp==NULL){
		printf("invalid position\n");
		free(p);
		return;
	}

	// inserting before temp->next
	p->next=temp->next;
	p->prev=temp;

	if(temp->next!=NULL){
		temp->next->prev=p;
	}
	else{
		tail=p;
	}

	temp->next=p;
}

// deletion at beginning
void del_beg(){

	if(head==NULL){
		printf("no data\n");
	}
	else{
		p=head;

		head=head->next;

		if(head!=NULL){
			head->prev=NULL;
		}
		else{
			tail=NULL;
		}

		free(p);
	}
}

// deletion at end
void del_end(){

	if(head==NULL){
		printf("no data\n");
	}
	else if(head==tail){
		free(head);
		head=NULL;
		tail=NULL;
	}
	else{
		p=tail;
		tail=tail->prev;
		tail->next=NULL;
		free(p);
	}
}

// deletion at middle
void del_mid(){

	int i=1;

	printf("enter the pos: ");
	scanf("%d",&pos);

	if(head==NULL){
		printf("no data\n");
		return;
	}

	if(pos==1){
		del_beg();
		return;
	}

	temp=head;

	while(i<pos && temp!=NULL){
		temp=temp->next;
		i++;
	}

	if(temp==NULL){
		printf("invalid position\n");
		return;
	}

	if(temp==tail){
		del_end();
		return;
	}

	// connect previous node with next node
	temp->prev->next=temp->next;

	// connect next node with previous node
	temp->next->prev=temp->prev;

	free(temp);
}

// display in reverse
void reverse_display(){

	temp=tail;

	if(tail==NULL){
		printf("no nodes\n");
	}
	else{
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->prev;
		}
		printf("\n");
	}
}

int main(){
	int a=8;
    printf("%d",++2);
	printf("create a doubly linked list\n");
	create();

	while(1){

		int n,sub;

		printf("\nenter the no\n");
		printf("1.insertion\n");
		printf("2.deletion\n");
		printf("3.display reverse\n");
		printf("4.quit\n");

		scanf("%d",&n);

		switch(n){

			case 1:

				printf("enter the sub number:\n");
				printf("1.insertion_beg\n");
				printf("2.inse_middle\n");
				printf("3.inse_end\n");

				scanf("%d",&sub);

				switch(sub){

					case 1:
						inse_begin();
						display();
						break;

					case 2:
						inse_mid();
						display();
						break;

					case 3:
						inse_end();
						display();
						break;
				}

				break;

			case 2:

				printf("enter the sub number:\n");
				printf("1.del_beg\n");
				printf("2.del_middle\n");
				printf("3.del_end\n");

				scanf("%d",&sub);

				switch(sub){

					case 1:
						del_beg();
						display();
						break;

					case 2:
						del_mid();
						display();
						break;

					case 3:
						del_end();
						display();
						break;
				}

				break;

			case 3:

				printf("reverse display: ");
				reverse_display();
				break;

			case 4:

				printf("quit\n");
				return 0;
		}
	}

	return 0;
}