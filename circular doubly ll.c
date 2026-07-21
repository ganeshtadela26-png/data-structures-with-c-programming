#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *l,*r;
}no;
int data,n,i=1,pos;
struct node *ptr,*p,*temp,*next,*head=NULL,*tail=NULL;
void create(){
    printf("enter no of nodes:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        ptr=(no*)malloc(sizeof(no));
        printf("enter data:");
        scanf("%d",&data);
        ptr->data=data;
        ptr->l=ptr->r=NULL;
        if(head==NULL){
            ptr->l=ptr->r=ptr;
            head=tail=ptr;
        }
        else{
            tail->r=ptr;
            head->l=ptr;
            ptr->l=tail;
            ptr->r=head;
            tail=ptr;
        }
    }
}
void display(){
    temp=head;
    if(head==NULL){
        printf("no data to display");
    }
    else if(temp->r==head){
        printf("%d",head->data);
    }
    else{
        do{
            printf("%d",temp->data);
            temp=temp->r;
        }
        while(temp!=head);
    }
}
void ins_beg(){
    printf("enter data to enter at beg:");
    scanf("%d",&data);
    ptr=(no*)malloc(sizeof(no));
    ptr->data=data;
    if(head==NULL){
        ptr->l=ptr->r=ptr;
        head=tail=ptr;
    }
    else{
        ptr->r=head;
        ptr->l=tail;
        head->l=ptr;
        tail->r=ptr;
        head=ptr;
    }
}
void ins_end(){
    printf("enter data to enter at end:");
    scanf("%d",&data);
    ptr=(no*)malloc(sizeof(no));
    ptr->data=data;
    if(head==NULL){
        ptr->l=ptr->r=ptr;
        head=tail=ptr;
    }
    else{
        ptr->l=tail;
        ptr->r=head;
        head->l=ptr;
        tail->r=ptr;
        tail=ptr;
    }
}
void ins_mid(){
    temp=head;
    printf("enter the pos to insert & pos must be within the range 1(exclude) and n(exclude):");
    scanf("%d",&pos);
    printf("enter data to enter at mid:");
    scanf("%d",&data);
    ptr=(no*)malloc(sizeof(no));
    ptr->data=data;
    if(head==NULL){
        ptr->l=ptr->r=ptr;
        head=tail=ptr;
    }
    else{
        while(i<pos){
            p=temp;
            temp=temp->r;
        }
        p->r=ptr;
        temp->l=ptr;
        ptr->l=p;
        ptr->r=temp;
    }
}
void del_beg(){
    if(head==NULL){
        printf("no data to delete");
    }
    else{
        temp=head;
        head=head->r;
        head->l=tail;
        tail->r=head;
        free(temp);
        temp=NULL;
    }
}
void del_end(){
    if(tail==NULL){
        printf("no data to delete");
    }
    else{
        temp=tail;
        tail=tail->l;
        tail->r=head;
        head->l=tail;
        free(temp);
        temp=NULL;
    }
}
void del_mid(){
    printf("enter the pos to delete & range must be 1(exclude) and n(exclude)");
    scanf("%d",&pos);
    if(head==NULL){
        printf("no data to delete");
    }
    else{
        int i=1;
        temp=head;
        while(i<pos){
            p=temp;
            temp=temp->r;
            next=temp->r;
            i++;
        }
        p->r=next;
        next->l=p;
        free(temp);
        temp=NULL;
    }
}
int main(){
	printf("create a cll\n");
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
				ins_beg();
				display();
				break;
				case 2:
				ins_mid();
				display();
				break;
				case 3:
				ins_end();
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