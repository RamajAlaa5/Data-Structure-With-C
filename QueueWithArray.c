#include <stdio.h>
#include <stdlib.h>

void InQueue(int arr[]);
void DeQueue(int arr[]);
void Display();

int rear,front=0;
int main(){
    int arr[6];
    InQueue(arr);
    DeQueue(arr);
    for(int i=0;i<6;i++){
        printf("Data = %d ",arr[i]);
    }
    return 0;
}

void InQueue(int arr[]){
    int value[6];
         printf("Enter Data To Be Inserted: ");
    for(int i=0;i<5;i++){
        scanf("%d ",&arr[i]);
       value[i]=arr[i]; 
    } 
   if(front==rear){
            front=0;
            rear=0;
    }
    else{
        rear++;
    }
    printf("Inserted Successfully");
}

void DeQueue(int arr[]){
    int value=arr[front];
    if(front==rear){
            front=0;
            rear=0;
    }
    else{
        front++;
    }
    printf("Deleted Successfully %d ",value);
            
}




