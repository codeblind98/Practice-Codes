#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int data;
   struct node *next;
 }nodetype;

nodetype* insert(nodetype*);
void display(nodetype*);

int main(){
    nodetype *front=NULL,*rear=NULL;
    int ch;
    do{
       printf("\n1 Insert \n2 Display \nAny key to Exit \n Enter your choice :");
       scanf("%d",&ch);
       switch(ch){
          case 1: 
             rear = insert(rear);
             if(front==NULL)
              front=rear;	
             break;
          case 2: 
             display(front);
             break;
          default: 
             break;
        }
       
    }while(ch<=2&&ch>0);
return 0;
}

nodetype* insert(nodetype *rear){
      nodetype *p=NULL;
      int num;
      printf("\nEnter the value to be inserted :");
      scanf("%d",&num);
    
      p=(nodetype*)malloc(sizeof(nodetype));
      if(p!=NULL)
         p->data=num;
      else
         printf("\nmemory not allocated");
      if(rear==NULL)
         rear=p;
      else{
          rear->next=p;
          rear=p;
        }
      rear->next=NULL;

  return rear;      
 }


 void display(nodetype *left){
 	 if(left!=NULL){
 	   //	left=left->next;
 	 	display(left->next);
        printf("%d\n",left->data);
   }
 }

























