#include <stdio.h>
#include <stdlib.h>

int top;
int arr[5];
void push(int item);
int pop();
// void Display(int stack[]);
int main(){
    
    int item,data;
  printf("Enter value of item: ");

  for(int i=0;i<5;i++){
  scanf("%d",&arr[i]);
  item=arr[i];
  }
push(item);
data=pop();
printf("Deleted Item:%d ",data);
 
    return 0;
}

void push(int item){

        if(top>=5){
            printf("Stack Is OverFlow ");
        }
        else{
              top++;
            arr[top]=item;
            printf("Item Added Successfully ");

        }

}

int pop(){
 int item;   
     if(top==-1){
         printf("UnderFlow");
     }
     else{
         item=arr[top];
         top--;
     }
  return item;
}


