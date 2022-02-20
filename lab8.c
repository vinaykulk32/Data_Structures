/*WAP to implement Stack & Queues using Linked Representation*/


#include<stdio.h>
#include<stdlib.h>
struct node{
    int x;
    struct node* next;
};
struct node* stack=NULL;
struct node* queue=NULL;

void main(){
int ch;
while(1){
printf("\n1-->Satck\n2-->Queue\n");
scanf("%d",&ch);
switch(ch){
  case 1:stack();
    break;
  case 2:queue();
    break;
  default:printf("\nInavalid choice");
    break;
      }
   }
}

void stack(){
  int ch;
printf("\n1-->push\n2-->pop\n3-->display");
scanf("%d",&ch);
switch(ch){
  case 1:push();
    break;
  case 2:pop();
    break;
  case 3:display();
    break;
  default:pirntf("\nInvalid choice"); 
      }
}
void push(){
struct node *new;
new=(struct node*)malloc(sizeof(struct node));
printf("\nDATA:\t");
scanf("%d",&new->x);
new->next=null;
if(stack==null){
stack=new;
printf("\nSuccess");}
else{
new->next=stack;
stack=new;
printf("\nSuccess"); 
   }
}
void pop(){
  struct node *temp;
  if(stack=='\0'){
    printf("\nStack is Empty");
  }
  else{
    temp=stack;
    stack=stack->next;
    free(temp);
    printf("\nSuccess");
  }
}
void display(){
  struct node* temp;
  if(stack=='\0'){
    printf("\nStack is Empty");
  }
  else{
    temp=stack;
    while(temp!=NULL){
      peintf("%d\n",temp->x);
      temp=temp->next;
    }
  }
}
void queue(){
  int ch;
printf("\n1-->enqueue\n2-->dequeue\n3-->display");
scanf("%d",&ch);
switch(ch){
  case 1:enqueue();
    break;
  case 2:dequeue();
    break;
  case 3:show();
    break;
  default:pirntf("\nInvalid choice"); 
      }
}
void enqueue(){
struct node *new;
new=(struct node*)malloc(sizeof(struct node));
printf("\nDATA:\t");
scanf("%d",&new->x);
new->next=null;
if(queue==null){
queue=new;
printf(""\nSuccess);}
else{
new->next=stack;
queue=new;
printf("\nSuccess"); 
   }
}
void dequeue(){
  struct node *temp;
  if(queue=='\0'){
    printf("\nqueue is Empty");
  }
  else{
    temp=queue;
    queue=queue->next;
    free(temp);
    printf("\nSuccess");
  }
}
void show(){
  struct node* temp;
  if(queue=='\0'){
    printf("\nqueue is Empty");
  }
  else{
    temp=queue;
    while(temp!=NULL){
      peintf("%d\n",temp->x);
      temp=temp->next;
    }
  }
}
