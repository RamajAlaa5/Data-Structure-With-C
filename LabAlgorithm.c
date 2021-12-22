#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Student {
    int id;
    char Name[10];
  
};
struct Student fillStudent();
void printMenu();
void printStudent(struct Student student);
void shiftArray(struct Student * students, int count);
int BinarySearch(struct Student std[],int low,int high,int id);
void Merge( struct Student std[],int low,int mid,int high);
void MergeSort( struct Student std[], int low, int high);
void BubbleSort(struct Student stdToSort[],int n);



struct Student stdToSearch[3];
int main()
{
    struct Student students[100];
    int userEntry;
     int studentsCount = 0;
    int low=0,high=0;
    struct Student student;
    int stdID;
    int searchResult;
    do {
        userEntry = 0;
        printMenu();
        printf("Choose an option from the menu: ");
        scanf("%d", &userEntry);
        switch(userEntry) {
            case 1:
                // Add Student
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
                // DeQueue A Student
                if (studentsCount != 0) {
                    student = students[0];
                    shiftArray(students, studentsCount);
                    studentsCount--;
                    printStudent(student);
                } else {
                    printf("The queue is empty\n");
                }
                break;
            case 3:
              //MergeSort
              MergeSort(students,low,studentsCount);
              for(int i=1;i<=studentsCount;i++){
                  printf("Student ID= %d Student Name=%s \n",students[i].id,students[i].Name);
              }
                break;

            case 4:
            //Bubble Sort
              BubbleSort(students,studentsCount);
              for(int i=0;i<studentsCount;i++){
                  printf(" Student Name= %s \n",students[i].Name);
              }
                break;
            case 5:
                // binary search
                 printf("Enter Student ID: ");
                 scanf("%d", &stdID);
                 searchResult=BinarySearch(students,0,studentsCount,stdID);
                if(searchResult!=-1){
                    printf("Student Sucessfully Found With Location = %d ",searchResult);
                }
                else{
                     printf("Failed To Find a Student with ID= %d",stdID);
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
    char stdName[10];
   
    int i;
    struct Student student;
    printf("Enter student ID: ");
    scanf("%d", &student.id);
    do {
        printf("Enter student  name: ");
        scanf("%s", stdName);
       
        if (strlen(stdName) > 9) {
            printf("Invalid name length, must be less than 10 characters\n");
        } else {
             strcpy(student.Name, stdName);
         
        }
    } while (strlen(stdName) > 9);
   
    return student;
};
void printStudent(struct Student student) {
    // print student details
    int i;
    printf("\n\n******\n\n");
    printf("Student ID: %d\n", student.id);
    printf("Student Full Name: %s\n", student.Name);


    printf("\n\n******\n\n");
}
void printMenu() {//Print menu of options to user
    printf("\n\n1. ADD Student\n");
    printf("2. DeQueue Student\n");
    printf("3. Merge Sort By ID \n");
    printf("4. Bubble Sort By Name \n");
    printf("5. Binary Search By ID \n");
    printf("0. Exit\n\n");
}

// search By ID
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




// Merge BY ID
void Merge( struct Student std[],int low,int mid,int high){
   int ID;
   struct Student temp[3];
    int list1,list2,i;
    i=low;
    list1=low;
    list2=mid+1;
    while(list1<=mid && list2<=high){
        if(std[list1].id<std[list2].id){
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

// By NAME
void BubbleSort(struct Student stdToSort[],int n){ 
int i,j;
char temp[10];
int swapped=1;
for(i=0;i<n-1;i++){
    swapped=0;
    for(j=0;j<n-1-i;j++){
        if(strcmp(stdToSort[j].Name,stdToSort[j+1].Name)>0){
        strcpy(temp,stdToSort[j].Name);
	    strcpy(stdToSort[j].Name,stdToSort[j+1].Name);
	    strcpy(stdToSort[j+1].Name,temp);
            swapped=1;
        }
    }
}
}