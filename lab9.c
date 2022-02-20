/*
WAP Implement doubly link list with primitive operations
a) Create a doubly linked list.
b) Insert a new node to the left of the node.
c) Delete the node based on a specific value
d) Display the contents of the list
*/


#include<stdio.h>
#include<stdlib.h>
struct node{
    int x;
    struct node* right;
    struct node* left;
};
struct node* head=NULL;


void main(){
    int ch;
    while(1){
        printf("\n1-->Add");
        printf("\n2-->show");
        printf("\n3-->delete");
        printf("\n4-->exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:add();
                  break;
            case 2:show();
                  break;
            case 3:delete();
                  break;
            case 4:exit(1);
                  break;
            default:printf("\nInvalid choice");      
        }
    }
}

void add(){
  struct node *new,*temp;
  new=(struct node*)malloc(sizeof(struct node));
  printf("\nid:\t");
  scanf("%d",&new->x);
  new->left=new->right=NULL;
  if(head==NULL){
    head=new;
    printf("\nSuccess");
  }
  else{
    new->right=head;
    head->left=new;
    head=new;
    printf("\nSuccess");
  }
}
void delete(){
  struct node *target,*prev,*Next;
  int key;
  printf("\nEnter id refering to which you want to delete the node :\t");
  scanf("%d",&key);
  target=head;
  i=0;
  prev=NULL;
  while(target!=NULL){
    if(head->id==key){
      temp=head;
      head=head->right;
      free(temp);
      head->left=NULL;
      i=1;
      printf("\nDeleted the node which contains the id %d",key);
            }
      if(target->right==NULL && target->id==key){
      last=head;
       while(last->right!=NULL){
       prev=last;
       last=last->right;
           }
       prev->right=NULL;
       free(last);
       i=1;
       printf("\nDeleted the node which contains the id %d",key);
           }
         if(target->id==key){
           prev->right=target->right;
           Next=target->right;
           Next->left=target->left;
           free(target);
           i=1;
               }
           else{
              prev=target;
              target=target->right;
                }
            }
            if(i!=1){
                printf("\nValue not found");
             }
}
void show(){
  struct node* temp;
  if(head==NULL){
    printf("\nLinked list is empty");
  }
  else{
    temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->x);
        temp=temp->right;
      }
   }
}
