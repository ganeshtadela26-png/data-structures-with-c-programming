//program for passenger check-in.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[10];
	int id;
	struct node *prev;
	struct node *next;
};

struct node *head=NULL,*tail=NULL,*ptr,*temp,*p,*p1;
char name[10];
int n,i=1,data,id;
// display
void forward_display(){
	temp=head; 
	if(head==NULL){
		printf("no nodes to dispay\n");
	}
	else{
		while(temp!=NULL){
			printf("%s-%d ,",temp->name,temp->id);
			temp=temp->next;
		}
		printf("\n");
	}
}
void backward_display(){
    temp=tail;
    if(tail==NULL){
        printf("no data to display\n");
    }
    else{
        while(temp!=NULL){
            printf("%s-%d ,",temp->name,temp->id);
            temp=temp->prev;
        }
        printf("\n");
    }
}
// insertion at beginning
void priority_checkin(){
	p=(struct node*)malloc(sizeof(struct node));
	printf("enter the name and the id\n");
	scanf("%s",name);
	scanf("%d",&id);
	strcpy(p->name,name);
    p->id=id;
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
void check_in_passenger(){

	p=(struct node*)malloc(sizeof(struct node));

	printf("enter the name and id\n");
	scanf("%s",name);
	scanf("%d",&id);
	strcpy(p->name,name);
	p->id=id;
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
void search(){
	int count=0;
	printf("enter the name and id\n");
	scanf("%s",name);
	scanf("%d",&id);
	temp=head;
	while(temp!=NULL){
		if(!strcmp(temp->name,name)&&temp->id==id){
		printf("passenger exists in the list\n");
		count=1;
	}
		temp=temp->next;
	}
	if(count==0){
		printf("no passenger exist\n");
	}
}
void cancel_booking(){
	int pos=0;
	printf("enter the name and the id to cancel\n");
	scanf("%s",name);
	scanf("%d",&id);
	if(head==NULL){
		printf("no passengers to cancel\n");
	}
	else if(!strcmp(head->name,name)&&head->id==id){
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
		printf("ticket is canceled for the passenger %s and %d \n",name,id);
		temp=NULL;
	}
	else if(!strcmp(tail->name,name)&&tail->id==id){
		temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		free(temp);
		printf("ticket is canceled for the passenger %s and %d \n",name,id);
		temp=NULL;
	}
	else{
		p=temp=head;
		while(temp!=NULL){
			if(!strcmp(temp->name,name)&&temp->id==id){
				p->next=temp->next;
				temp->next->prev=p;
				free(temp);
				temp=NULL;
				printf("ticket is canceled for the passenger %s and %d \n",name,id);
				pos=1;
			}
			p=temp;
			temp=temp->next;
		}
		if(pos==0){
			printf("no passenger exists with these details\n");
		}
	}
}
int main(){
	int n;
	while(1){
		printf("enter the number for\n1. Check-in Passenger\n2. Priority Check-in\n3. Search Passenger\n4. Cancel Booking\n5. Show Passenger List (forward)\n6. Show Passenger List (backward)\n7. Exit");
		scanf("%d",&n);
		switch(n){
			case 1:
			check_in_passenger();
			break;
			case 2:
			priority_checkin();
			break;
			case 3:
			search();
			break;
			case 4:
			cancel_booking();
			break;
			case 5:
			forward_display();
			break;
			case 6:
			backward_display();
			break;
			case 7:
			return 0;
			default:
			printf("invalid input");
		}
	}
	return 0;
}