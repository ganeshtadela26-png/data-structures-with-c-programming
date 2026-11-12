//creating a liked list AND insertion
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *head=NULL,*tail=NULL,*ptr,*temp,*p,*link,*p1;
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
//insertion at begin
void inse_begin(){
    p=(struct node*)malloc(sizeof(struct node));
    printf("enter the data for ins at beg:");
    scanf("%d",&data);
    p->data=data;
    p->link=NULL;
    if(head==NULL){
    	head=tail=p;
	}
	else{
		p->link=head;
		head=p;
	}
}
// insertion at end
void inse_end(){
	p=(struct node*)malloc(sizeof(struct node));
    printf("enter the data for ins at end:");
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
//insertion at middle
void inse_mid(){
	int pos,i=1;
	printf("enter the position to insert");
	scanf("%d",&pos);
	p=(struct node*)malloc(sizeof(struct node));
    printf("enter the data for middle:");
    scanf("%d",&data);
    p->data=data;
    p->link=NULL;
    temp=head;
	while(i<pos){
    	p1=temp;
    	temp=temp->link;
    	i++;
	}
    p1->link=p;
    p->link=temp;
	}
//deletion at begin
void del_beg(){
	if(head==NULL){
		printf("no data");
	}
	else{
		p=head;
		head=head->link;
		free(p);
	}
}
//deletion at end
void del_end(){
	temp=head;
    while(temp->link!=NULL){
		p=temp;
		temp=temp->link;
    	
	}
	p->link=NULL;
	free(temp);

}	
// deletion at middle
void del_mid(){
	int i=1;
	printf("enter the pos");
	scanf("%d",&pos);
	temp=head;
	while(i<pos){
		p=temp;
		temp=temp->link;
		i++;
	}
	p->link=temp->link;
	free(temp);
}
int main(){
	printf("create a sll");
	create();
	while(1){
		int n,sub;
		printf("enter the no\n1.insertion\n2.deletion\n3.quit:");
		scanf("%d",&n);
		switch(n){
			case 1:
			printf("enter the sub number:\n1.insertion_beg\n2.inse_middle\n3.inse_end:");
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
			case 2:
			printf("enter the sub number:\n1.del_beg\n2.del_middle\n3.del_end");
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
			case 3:
			printf("quit");
			break;
		}
	}
	return 0;
}
