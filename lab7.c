/*
WAP Implement Single Link List with following operations
a) Sort the linked list.
b) Reverse the linked list.
c) Concatenation of two linked lists
*/



#include<stdio.h>
#include<stdlib.h>
struct node{
    int x;
    struct node* next;
};
struct node* head1=NULL;
struct node* head2=NULL;

void main(){
    int ch,internal,internal2;
    while(1){
        printf("\n1-->Add");
        printf("\n2-->Show");
        printf("\n3-->Concatinate");
        printf("\n4-->Sort_single");
        printf("\n5-->Reverse");
        printf("\n6-->Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:add_end();
                   break;
            case 2:show();
                   break;
            case 3:Concatinate();
                   break;
            case 4:Sort_single();
                   break;
            case 5:reverse();
                   break;
            case 6:exit(1);
                   break;
            default:printf("\nInvalid choice");
                  break;
        }
    }
}

void add_end(){
    int id,ch;
    struct node* new_node;
    struct node* last;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nid:\t");
    scanf("%d",&id);
    new_node->x=id;
    new_node->next=NULL;
    printf("\n1-->Add to first Linked List");
    printf("\n2-->Add to Second Linked List\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
               if(head1==NULL){
               head1=new_node;
               head1->next=NULL;
               printf("\nSuccess");
               }
               else{
                last=head1;
                while(last->next!=NULL){
                    last=last->next;
                }
                last->next=new_node;
                printf("\nSuccess");
               }
               break;
        case 2:
               if(head2==NULL){
               head2=new_node;
               head2->next=NULL;
               printf("\nSuccess");
               }
               else{
                    last=head2;
                    while(last->next!=NULL){
                    last=last->next;
                    }
                    last->next=new_node;
                    printf("\nSuccess");
                }
                break;
        default:printf("\nInvalid choice");
                break;
    }
}
void show(){
    int ch;
    struct node* temp;
    struct node* last;
    if(head1==NULL && head2==NULL){
        printf("\n Linked list are Empty");
    }
    else{
    printf("\n1-->Show first Linked List");
    printf("\n2-->Show Second Linked List");
    scanf("%d",&ch);
    switch(ch){
        case 1:
               temp=head1;
               printf("\n");
               while(temp!=NULL){
                   printf("\t%d",temp->x);
                   temp=temp->next;
               }
               break;
        case 2:
               temp=head2;
               printf("\n");
               while(temp!=NULL){
                   printf("\t%d",temp->x);
                   temp=temp->next;
               }
               break;
        default:printf("\nInvalid choice");
                break;
         }
    }
}
void Concatinate(){
    struct node* temp;
    int ch;
    if(head1==NULL||head2==NULL){
        printf("\nLinked lists are Empty");
    }
    else{
    printf("\n1-->Conacatinate first to Second Linked lists tale");
    printf("\n2-->Conacatinate Second to first Linked lists tale\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:temp=head2;
               while(temp->next!=NULL){
                   temp=temp->next;
               }
               temp->next=head1;
               printf("\nSuccess");
              break;
        case 2:temp=head1;
               while(temp->next!=NULL){
                   temp=temp->next;
               }
               temp->next=head2;
               printf("\nSuccess");
              break;
        default:printf("\nInvalid choice");
              break;      
         }
    }
}
void Sort_single(){
    int t,ch;
    struct node *first,*sec;
    if(head1==NULL||head2==NULL){
        printf("\nLinked lists are Empty");
    }
  else{
    printf("\n1-->sort first Linked lists");
    printf("\n2-->sort first Linked lists\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:first=head1;
             while(first->next!=NULL){
             sec=first->next;
        while(sec!=NULL){
            if(first->x>sec->x){
                t=first->x;
                first->x=sec->x;
                sec->x=t;
            }
            sec=sec->next;
        }
        first=first->next;
    }
        break;
      case 2:first=head2;
            while(first->next!=NULL){
        sec=first->next;
        while(sec!=NULL){
            if(first->x>sec->x){
                t=first->x;
                first->x=sec->x;
                sec->x=t;
              }
            sec=sec->next;
           }
        first=first->next;
        }
        break;
        default:printf("\nInvalid choice");
              break; 
      }
   }
}
void reverse(){
    struct node* curr;
    struct node* prev;
    struct node* next;
  int ch;
  printf("\n1-->Reverse first Linked list");
  printf("\n2-->Reverse second Linked list\n");
  scanf("%d",&ch);
  switch(ch){
    case 1:curr=head1;
          prev=NULL;
    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head1 = prev;
        break;
    case 2:
      curr=head2;
    prev=NULL;
    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head1 = prev;
     break;
      default:printf("\nInvalid choice");
              break; 
  }
}
