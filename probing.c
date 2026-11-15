#include<stdio.h>
#include<stdlib.h>
void insert(int arr[],int k){
    int h=k%10;
    if(arr[h]==-1){
        arr[h]=k;
    }
    else{
        for(int i=0;i<5;i++){
            int index=(h+i)%10;
            if(arr[index]==-1){
                arr[index]=k;
            }
        }
    }
}
void display(int ar[]){
    for(int i=0;i<5;i++){
        printf("%d",ar[i]);

    }
}
int main(){
    int table[5];
    int key,n=5;
    for(int i=0;i<n;i++){
        table[i]=-1;
    }
    for(int i=0;i<n;i++){
        printf("enter the key:");
        scanf("%d",&key);
        insert(table,key);
    }
    display(table);
    return 0;
}
