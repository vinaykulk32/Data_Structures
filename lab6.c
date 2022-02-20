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
        printf("\n3-->Delete");
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
            case 3:printf("\n1-->Delete the first node");
                   printf("\n2-->Delete the last node");
                   printf("\n3-->Delete a specific node by its content\n");
                   scanf("%d",&internal2);
                   switch(internal2){
                       case 1:del_first();
                              break;
                       case 2:del_last();
                              break;
                       case 3:del_specific();
                              break;
                        default:printf("\nInvalid choice");
                              break;
                   }
                   break;
            case 4:exit(1);
                   break;
            default:printf("\nInvalid choice");
                   breal;
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
    if(head==NULL){
        printf("\nLinked list is Empty");
    }
    else{
        temp=head;
        printf("\n");
        while(temp!=NULL){
            printf("\t%d",temp->x);
            temp=temp->next;
        }
    }
}
void del_first(){
    struct node* prev;
    if(head==NULL){
        printf("\nLinked list is Empty");
    }
    else{
        prev=head;
        head=head->next;
        free(prev);
        printf("\nSuccess");
    }
    
}
void del_last(){
    struct node* last;
    struct node* prev;
    last=head;
    if(head==NULL){
        printf("\nLinked list is Empty");
    }
    else{
        while(last->next!=NULL){
            prev=last;
            last=last->next;
        }
        free(last);
        prev->next=NULL;
        printf("\nSuccess");
        }
}
void del_pos(){
    int pos,i=1,j=1; 
    struct node* prev;
    struct node* target;
    struct node* temp;
    if(head==NULL){
        printf("\nLinked list is Empty");
    }
    else{
        printf("\nEnter the position where the node to be deleted\t");
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
         prev->next=target->next;
         free(target);
         printf("\nSuccess");
        }
    }
}
void del_all(){
    struct node* path;
    if(head==NULL){
        printf("\nLinked list is Empty");
    }
    else{
        while(head!=NULL){
        path=head;
        head=head->next;
        free(path);
        }
        printf("\nSuccess");
    }
}
void del_specific(){
    int key;
    struct node *target,*prev;
    if(head==NULL){
        printf("\nLinked list is Empty");
    }
    else{
        printf("\nEnter the the specific element that need to be deleted : \t");
        scanf("%d",&key);
        target=head;
        while(target->x!=key){
            prev=target;
            target=target->next;
        }
        if(target->x==key){
            prev->next=target->next;
            free(target);
            printf("\nSuccess");
        }
        else{
            printf("\nThe element does not exist in the linked list");
        }
    }
}
