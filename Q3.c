#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
 }nodetype;
 
 nodetype* push(nodetype*);
 nodetype* removeNode(nodetype*);
 void display(nodetype*);


 int main(){
 	nodetype *top=NULL;
    char choice;
    int opt;
 	
 	do
 	{
 	  printf("\n1 Push \n2 Remove Node using Key \nAny key to Exit \nEnter your choice : ");
	   scanf("%d",&opt);
	   
	  switch(opt){
	   case 1:
	      top = push(top);
	      break;
	   case 2:
	      top =	removeNode(top);
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
 
  nodetype* removeNode(nodetype *top){
  	int key,flag=0;
 	nodetype *keyNode=NULL , *keyNodePrevious=NULL;
    printf("\nEnter the key : ");
    scanf("%d",&key);
    keyNode=top;
    
    while((keyNode->next==NULL)){
    	if(keyNode->data==key){
		  flag = 1;
		  break;
	    }
           keyNodePrevious = keyNode;                                  //Locating the node with key value      
		   keyNode = keyNode->next;
	  }
	 //  printf("------------just checking-----------");
	  if(flag==1){
			if(keyNode == top)
                top=top->next;   
	        else
	            keyNodePrevious->next=keyNode->next;
	    }
	  else{
	  	    if(keyNode->data==key)
		    	keyNodePrevious->next=NULL;
		    else
			    printf("\n Key not found");	
	    }
	printf("\n Linked list after desired not deleted or not found");
	display(top);
	free(keyNode);
	return top; 
 }
 
  void display(nodetype *top){ 
 		if(top!=NULL){
 			while(top!=NULL){
 			  printf("\n%d",top->data);
 			  top=top->next;
 		   }
		}
		else{
		   printf("\nstack is empty");
 	}
 }

  
