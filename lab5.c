/*  WAP to Implement Singly Linked List with following operations
a) Create a linked list.
b) Insertion of a node at first position, at any position and at end of list.
c) Display the contents of the linked list. */



#include<stdio.h>
#include<stdlib.h>
struct node{
    int x;
    struct node* next;
};
struct node* head=NULL;


void main(){
    int ch,internal,internal2;
    while(1){
        printf("\n1-->Add");
        printf("\n2-->show");
        printf("\n4-->Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\n1->>Add at Begining");
                   printf("\n2->>Add at End");
                   printf("\n3->>Add at position\n");
                   scanf("%d",&internal);
                   switch(internal){
                       case 1:add_beg();
                              break;
                       case 2:add_end();
                              break;
                       case 3:add_pos();
                              break;
                       default:printf("\nInvalid choice");
                              break;
                   }
                   break;
            case 2:show();
                   break;
            case 3:exit(1);
                   break;
            default:printf("\nInvalid choice");
                   break;
               }
       }
}            
            
void add_beg(){
    int id;
    struct node* new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nid:\t");
    scanf("%d",&id);
    new_node->x=id;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        head->next=NULL;
        printf("\nSuccess");
    }
    else{
        new_node->next=head;
        head=new_node;
        printf("\nSuccess");
    }
}
void add_end(){
    int id;
    struct node* new_node;
    struct node* last;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nid:\t");
    scanf("%d",&id);
    new_node->x=id;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        printf("\nSuccess");
    }
    else{
        last=head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=new_node;
        printf("\nSuccess");
    }
}
void add_pos(){
    int id,pos,i=1,j=1;
    struct node* new_node;
    struct node* target;
    struct node* prev;
    struct node* temp;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nid:\t");
    scanf("%d",&id);
    new_node->x=id;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        head->next=NULL;
        printf("\nSuccess");
    }
    else{
        printf("\nEnter the position where the new node to be inserted\t");
        scanf("%d",&pos);
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            i++;
        }
        if(pos>i){
            printf("\nInvalid position");
        }
        else{
            target=head;
            while(j<pos){
                prev=target;
                target=target->next;
                j++;
            }
            new_node->next=target;
            prev->next=new_node;
            printf("\nSuccess");
        }
    }
}
void show(){
    struct node* temp;
    temp=head;
    printf("\n");
    while(temp!=NULL){
        printf("\t%d",temp->x);
        temp=temp->next;
    }
}
