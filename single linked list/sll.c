#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head =NULL;

void insertfirst(){
    struct node*temp =(struct node*)malloc(sizeof(struct node));
    if(!temp){
        printf("memory overflow\n");
        return;
    }
    printf("enter the element to insert :");
    scanf("%d",&temp->data);
    temp->next=head;
    head=temp;
}

void insertend(){
    struct node*temp =(struct node*)malloc(sizeof(struct node));
    if(!temp){
        printf("memory overflow\n");
        return;
    }
    printf("enter the element to insert at end :");
    scanf("%d",&temp->data);
    temp->next=NULL;
    
    if(head==NULL){
        head=temp;
    }else{
        struct node*ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void insertatany(){
    int key;
    printf("enter the element to insert:");
    scanf("%d",&key);
    struct node*temp =(struct node*)malloc(sizeof(struct node));
    if(!temp){
        printf("memory overflow\n");
        return;
    }
    temp->data=key;
    int pos;
     printf("enter the position at to insert:");
    scanf("%d",&pos);
    
    if(pos==1){
        temp->next=head;
        head=temp;
        return;
    }
    struct node*ptr=head;
    for(int i=1;i<pos-1&&ptr!=NULL;i++){
        ptr=ptr->next;
    }
    if(ptr==NULL){
        printf("position out of bound\n");
        free(temp);
    }else{
        temp->next=ptr->next;
        ptr->next=temp;
    }
}
void deletefront(){
    if(head==NULL){
        printf("underflow\n");
        return;
    }
    struct node *temp=head;
    head=head->next;
    free(temp);
}
void deleteend(){
    if (head==NULL){
        printf("underflow\n");
        return; 
    }
    struct node *ptr =head;
    struct node *temp =NULL;
    
    if(ptr->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    while(ptr->next!=NULL){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
    free(ptr);
}
void deleteanypos(){
    int pos;
     printf("enter the position at to insert:");
    scanf("%d",&pos);
    if (head==NULL){
        printf("underflow\n");
        return; 
    }
    struct node*ptr=head;
    if(pos==1){
        head=head->next;
        free(ptr);
        return;
    }
    struct node*prev=NULL;
    for(int i=1;i=pos-1&&ptr!=NULL;i++){
        prev=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL){
        printf("out of ");
        return;
    }
    prev->next=ptr->next;
    free(ptr);
}
void display(){
    struct node *ptr=head;
    if(ptr==NULL){
        printf("list is empty");
        return;
    }
    printf("list is :");
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
        if(ptr!=NULL){
            printf("->");
        }
    }
    printf("  -> NULL\n");
}
int main(){
    int choice;
    while(1){
       printf("\n1: Insertion\n2: Deletion\n3: Display\n4: Exit\nChoice: ");
        scanf("%d", &choice);
        int pos;
        switch(choice){
            case 1: printf("Select Position:\n1: Front\n2: End\n3: Between Nodes\nChoice: ");
                scanf("%d", &pos);
                if(pos==1) insertfirst();
                else if (pos ==2) insertend();
                else if (pos==3) insertatany();
                else printf("fuck off\n");
                break;
            case 2: printf("Select Position:\n1: Front\n2: End\n3: Between Nodes\nChoice: ");
                scanf("%d", &pos);
                if(pos==1) deletefront();
                else if (pos ==2) deleteend();
                else if (pos==3) deleteanypos();
                else printf("fuck off\n");
                break;
            case 3:
                display();
                break;

            case 4:
                printf("Exited!\n");
                exit(0);

            default:
                printf("Wrong Choice!\n");
                break;
        }
    }
    return 0;
}
   
    
    

    

