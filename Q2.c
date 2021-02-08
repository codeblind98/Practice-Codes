#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
 }nodetype;
 
 nodetype* push(nodetype*);
 void display(nodetype*);

 int main(){
 	nodetype *top=NULL;
    char choice;
    int opt;
 	
 	do
 	{
 	  printf("\nEnter your choice \n1 Push \n2 Display \nAny key to Exit \nEnter your choice :");
	   scanf("%d",&opt);
	   
	  switch(opt){
	   case 1:
	      top = push(top);
	      break;
	   case 2:
	       display(top);
		   break;
	   default :
	       break; 
     }
	
    }while(opt<=2&&opt>0);
  
   return 0;
 }
 
 nodetype* push(nodetype *top){
 	int num;
 	nodetype *p;
 	printf("\nEnter the element to be pushed :");
 	scanf("%d",&num);
 	p=(nodetype*)malloc(sizeof(nodetype));
    	if(p!=NULL){
    		p->data=num;
    		p->next=top;
    		top=p;
		}
		else{
		   printf("\nMemory not allocated");
 	}
 	return top;
 }
 
 void display(nodetype *top){
 	 if(top!=NULL){
 	 	display(top->next);
        printf("%d\n",top->data);
   }
 }
