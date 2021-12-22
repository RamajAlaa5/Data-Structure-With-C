#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// queue using array
// enqueue
// dequeue
// exit
struct Student {
    int id;
    char FirstName[10];
    char LastName[10];
    char FullName[40];
};
struct Student fillStudent();
void printMenu();
void printStudent(struct Student student);
void shiftArray(struct Student * students, int count);
struct Student stdToSearch[3];
int main()
{
    struct Student students[100];
    int studentsCount = 0;
    int userEntry;
    struct Student student;
    do {
        userEntry = 0;
        printMenu();
        printf("Choose an option from the menu: ");
        scanf("%d", &userEntry);
        switch(userEntry) {
            case 1:
                // enqueue
                if (studentsCount != 100) {
                    student = fillStudent();
                    students[studentsCount] = student;
                    studentsCount++;
                    printf("Student enqueued successfully!\n");
                } else {
                    printf("No space left in the queue\n");
                }
                break;
            case 2:
                // dequeue
                if (studentsCount != 0) {
                    student = students[0];
                    shiftArray(students, studentsCount);
                    studentsCount--;
                    printStudent(student);
                } else {
                    printf("The queue is empty\n");
                }
                break;
            case 0:
                // exit
                break;
            default:
                // default
                printf("Invalid choice\n\n");
                userEntry = -1;
                break;
        }
    } while (userEntry != 0);
    return 0;
}
void shiftArray(struct Student * students, int count) {
    int i;
    for (i = 0; i < (count - 1); i++) {
        *(students + i) = *(students + i + 1);
    }
}
struct Student fillStudent() {
    char tempFirstName[10];
    char tempLastName[10];
    int i;
    struct Student student;
    printf("Enter student ID: ");
    scanf("%d", &student.id);
    do {
        printf("Enter student First name: ");
        scanf("%s", tempFirstName);
          printf("Enter student Last name: ");
        scanf("%s", tempLastName);
        if (strlen(tempFirstName) > 9 && strlen(tempLastName) > 9) {
            printf("Invalid name length, must be less than 10 characters\n");
        } else {
            strcpy(student.FullName,tempFirstName);
            strcat(student.FullName," ");
            strcat(student.FullName,tempLastName);
        }
    } while (strlen(tempFirstName) > 9 && strlen(tempLastName) > 9);
   
    return student;
};
void printStudent(struct Student student) {
    // print student details
    int i;
    printf("\n\n******\n\n");
    printf("Student ID: %d\n", student.id);
    printf("Student Full Name: %s\n", student.FullName);


    printf("\n\n******\n\n");
}
void printMenu() {//Print menu of options to user
    printf("\n\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("0. Exit\n\n");
}


int BinarySearch(struct Student std[],int low,int high,int id){
    int mid;
    int loc=-1;
    while (low<=high && loc==-1)
    {
        mid=(low+high)/2;
        if(std[mid].id==id){
             loc=mid;
        }
        else if (std[mid].id<id)
        {
           low=mid+1; 
        }
        else{
            high=mid-1;
        }
    }
    return loc;   
}




// merge by name
void Merge( struct Student std[],int low,int mid,int high){
    char FullName[40];
   struct Student temp[40];
    int list1,list2,i;
    i=low;
    list1=low;
    list2=mid+1;
    while(list1<=mid && list2<=high){
        if(std[list1].FullName<std[list2].FullName){
           temp[i]=std[list1];
            list1++;
            i++;
        }

         else{
                temp[i]=std[list2];            
                list2++;
                 i++;
        }
    }

     while(list1<=mid ){
      
           temp[i]=std[list1];
            list1++;
            i++;
     }

 while(list2<=high ){
      
           temp[i]=std[list2];
            list2++;
            i++;
     }

     for(int i=low;i<=high;i++){
       std[i]=temp[i];
     }
}
void MergeSort( struct Student std[], int low, int high)
{
    int mid = 0;

    if(low == high)
    {
        return;
    }
    else
    {
        mid = (low + high) / 2;

        MergeSort(std, low, mid);

        MergeSort(std, mid + 1, high);

        Merge(std, low, mid, high);
    }
}


void BubbleSort(void){
int i,j;
struct Student stdSearch;
int swapped=1;
for(i=0;i<2;i++){
    swapped=0;
    for(j=0;j<2-i;j++){
        if(stdToSearch[j].id>stdToSearch[j+1].id){
            stdSearch=stdToSearch[j];
            stdToSearch[j]= stdToSearch[j+1];
             stdToSearch[j+1]=stdSearch;
             swapped=1;
        }
    }
}
}