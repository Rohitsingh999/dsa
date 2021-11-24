#include<stdio.h>
#include<malloc.h>
typedef struct node{

 int data;
  struct node *next;
  struct node *prev;

}node;

 void f_insert(node **start,node **last){ 
	 node *p;
 	 p= (node*)malloc(sizeof(node));

 	 printf("enter the data\n");
	 scanf("%d",&p->data);
	 p->next=p;
	 p->prev=p;

	 if(*start==NULL){
  	 *start=p;
     *last=p;

     }
	 else{
     p->next=*start;
     (*start)->prev=p;
     p->prev=*last;
     *start=p;
     (*last)->next=*start;
     }
  }
void l_insert(node **start,node **last){ 
	 node *p;
 	 p= (node*)malloc(sizeof(node));

 	 printf("enter the data\n");
	 scanf("%d",&p->data);
	 p->next=p;
	 p->prev=p;

    
	 if(*start==NULL){
  	 *start=p;
     *last=p;
 
      }
     else{
     p->prev=*last;
     (*last)->next=p;
     p->next=*start;
     *last=p;
     
     }
  }
  
 void dis(node *start){
   node *t;
   t=start;
	while(t->next!=start){
    printf("%d ",t->data);
    t=t->next;
   
   }
    printf("%d \n",t->data);
}

 void del( node **start, node **last){
     
     int key;
    
    printf("enter the key");
    scanf("%d",&key);
    
    if(key==(*start)->data){
     printf("start->data=%d",(*start)->data);    
     node *s=*start;
     *start=(*start)->next;
   
     (*start)->prev=*last;
     (*last)->next=*start;
      free(s);
    }
    else if(key==(*last)->data){
     printf("last->data=%d",(*last)->data);    
     node *l=*last;
     *last=(*last)->prev;
     (*last)->next=*start;
     (*start)->prev=*last;
      free(l);
   }
   else if(key!=(*start)->data||key==(*last)->data){
    
    node *temp;
    temp=*start;
     while(temp->data!=key){
        temp=temp->next;

     }
    node *t=temp;
     temp->prev->next=temp->next->prev;
     temp->next->prev=temp->prev->next;
     free(t);
  }
}


int main(){
    int n=1,opt;
    node *start=NULL,*last=NULL;

 
	 while(n!=0){
     
     printf("1=insert first\n2=for insert last\n3=display\n4=delete\n5=EXIT..\n");
     scanf("%d",&opt);
     switch(opt){

     case 1: f_insert(&start,&last);
            break;
     case 2: l_insert(&start,&last);
            break;
     case 3:dis(start);
            break;
     case 4:del(&start,&last);
           break;
     case 5: n=0;
            printf("EXIT.....");
            break;
     default: printf("invalid number\n");

        break;
    }
 }
 return 0;
}

 

     
