#include <stdio.h>
#include <stdlib.h>

struct Node{
struct Node* Next;
int Data;
};
struct Node *Head;
struct Node* Tail;

void InQueue();
void DeQueue(void);
void Display(void);
int main(){
    int data;
printf("Enter Data To Be Inserted: \n");
   scanf("%d",&data);

 InQueue(data);
   printf("\n\n");
 DeQueue();
  printf("\n\n");
    Display();
   
    return 0;
}



void InQueue(int data){
struct Node*ptr=(struct Node*)malloc(sizeof(struct Node*));
if(ptr){ // create new Node

ptr->Data=data;
ptr->Next=NULL;

if(Head==NULL){ //nolist
Head=Tail=ptr;
}
else{ // there is alist
Tail->Next=ptr;
Tail=ptr;
}
}
printf("Successfully Added ");
}


void DeQueue(void){ // print from first element
int value=-1;
struct Node* ptr;
if(ptr){
    if(Head==NULL){ // no list
       printf(" Queue Is Empty ");
    }
    else{
        value=Head->Data;
        ptr=Head;
        Head=Head->Next;
        free(ptr); // delete node
    }
}
printf("Successfuly Deleted ");
}

void Display(void){
    struct Node* ptr;
     ptr=Head;
   if(Head==NULL){ // no list
       printf("Queue Is Empty ");
   }

printf("Printig Values:\n");
 while(ptr != NULL){
     printf("Queue Data = %d ",ptr->Data);
     ptr=ptr->Next;
 }
   
}


