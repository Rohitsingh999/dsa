#include<stdio.h>
#include<malloc.h>
struct node{

int data;
struct node *next;

};

struct node *head=NULL;;

void insert(){
int n;
struct node *temp;
 temp=(struct node*)malloc(sizeof(struct node));
 
 printf("\nenter the data in node\n");
 scanf("%d",&n);
 temp->data=n;
 temp->next=NULL;
 if(head==NULL){
   head=temp;
 }
 else{
 struct node *t;
 t=head;
  
 while(t->next!=NULL){
     t=t->next;
 }
  t->next=temp;
}
}
void print(){

struct node *p;

p=head;
while(p->next!=NULL){


printf("%d ",p->data);
 p=p->next;
 }
 printf("%d ",p->data);
}
 void delete(){
 int key;
 struct node *del=head;
  printf("enter the key to delete that data\n");
  scanf("%d",&key);
  if(head->data==key)
 {
   head=head->next;
 
 }
 else{

 struct node *privious;
 while(key!=del->data){
     privious=del;
    del=del->next;
 }
 privious->next=del->next;
 
 }

}

int main(){

int o=1;
int opt;
while(o!=4){
printf("\nenter \n1.) for made node..\n2.)for print node...\n3.)\n3.)for delete node...\n4.) for  exit\n");
scanf("%d",&opt);
 
switch(opt){

case 1: insert();
        break;
case 2: print();
        break;
case 3: delete();
        break;
case 4: o=4;
        break;
default : printf("\ninvalid option\n");
} 
 
}
return 0;
}
