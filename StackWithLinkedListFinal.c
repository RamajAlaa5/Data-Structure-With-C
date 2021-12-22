#include <stdio.h>
#include <stdlib.h>
void push(int item);
void pop(void);
struct Stack
{
    int data;
    struct Stack* Next;
};
    struct Stack* Tail;
    struct Stack* Head;


int main(){
    int item,data;
    printf("Enter Data to be Inserted:\n");
    scanf("%d",&item);
    push(item);
     pop();
    return 0;
}

void push(int item){
    struct Stack*ptr=(struct Stack*)malloc(sizeof(struct Stack));
    ptr->data=item;
    if(Head==NULL){ //nolist
        ptr->Next=NULL;
       Head=ptr;
    }
    else{
        ptr->Next=Head;
         Head=ptr;
    }
printf("Success!!") ;
}

void pop(){ //delete
   int item;
   struct Stack*ptr;
     ptr=Head;
        if(Head==NULL){
            printf("Stack UnderFlow");
        }

else{
  
    Head=Head->Next;
    free(ptr);
    printf("Data Deleted %d ",ptr->data);

}

}