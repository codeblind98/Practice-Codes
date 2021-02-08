#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
 }nodetype;
 
 nodetype* push(nodetype*);
 void count(nodetype*);
 int palindrome(int);


 int main(){
 	nodetype *top=NULL;
    char choice;
    int opt;
 	
 	do
 	{
 	  printf("\n1 Push \n2 Count nodes having palindrome data \nAny key to Exit \nEnter your choice : ");
	   scanf("%d",&opt);
	   
	  switch(opt){
	   case 1:
	      top = push(top);
	      break;
	   case 2:
	      count(top);
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
 
  void count(nodetype *top){
  	int counting=0;
  	while(top!=NULL){
  		 if(palindrome(top->data)==1)
  		    counting++;
  		  
  	    top=top->next;
	  }
	printf("\nTotal no. of nodes having palindrome data is %d ",counting);
}

int palindrome(int num){
	int reverseNum=0,originalNum=num;
	while(num!=0){
		reverseNum=(reverseNum*10)+(num%10);
		num=num/10;
	}
	if(reverseNum==originalNum)
	return 1;
	else
	return 0;
}
  
