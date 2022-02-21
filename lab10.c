/*
Write a program
a) To construct a binary Search tree.
b) To traverse the tree using all the methods i.e., in-order, preorder and post
order
c) To display the elements in the tree.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int x;
    struct node *left,*right;
};
struct node *root=NULL;

void main(){
    int ch;
    while(1){
        printf("\n1-->Add,\n2-->preorder\n3-->inorder\n4-->postorder\n5-->exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: add();
            break;
            case 2: preorder(root);
            break;
            case 3: inorder(root);
            break;
            case 4: postorder(root);
            break;
            case 5: exit(1);
            break;
            default:printf("\nInvalid choice");
            break;
        }
    }
}
void add(){
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->left=new->right=NULL;
    printf("\nDATA:\t");
    scanf("%d",&new->x);
    if(root==NULL){
        root=new;
    }
    else{
        insert(root,new);
    }
}
void insert(struct node *root,struct node *new){
    if(new->x < root->x){
        if(root->left!=NULL){
            insert(root->left,new);
        }
        else{
            root->left=new;
        }
    }
    else{
        if(root->right!=NULL){
            insert(root->right,new);
        }
        else{
            root->right=new;
        }
    }
}

void preorder(struct node* temp){
    if(temp!=NULL){
        printf("%d,",temp->x);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(struct node* temp){
    if(temp!=NULL){
        inorder(temp->left);
        printf("%d,",temp->x);
        inorder(temp->right);
    }
}
void  postorder(struct node* temp){
    if(temp!=NULL){
        postorder(temp->left);
        postorder(temp->right);
        printf("%d,",temp->x);
    }
}
