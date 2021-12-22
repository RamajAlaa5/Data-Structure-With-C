#include <stdio.h>
#include <stdlib.h>

int Queue[5];
void InQueue(int item);
int DeQueue();
void Display();

int front=0;
int rear=0;
int main(){
    int item;
    int DeQuedItem;
    printf("Enter Item: ");
    // scanf("%d",&item);

    for(int i=0;i<5;i++){
        scanf("%d",&Queue[i]);
        item=Queue[i];
    }
   InQueue(item);

   DeQuedItem=DeQueue();
    printf("Deleted Item: %d ",DeQuedItem);

    return 0;
}

void InQueue(int data){
if(rear<5){
     rear++;
 Queue[rear]=data;
 printf("Added Successfully \n");

}
else{
printf("Queue Is OverFlow");
}

 
}

int DeQueue(){
    int value=-1;
    if(front>rear){
        printf("UnderFlow");
    }
 else{
     value=Queue[front];
     front=front+1;
 }
   return value;           
}






