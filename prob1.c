#include<stdio.h>
#include<string.h>
typedef struct{
    char rollno[10];
    char name[200];
    char branch[200];
    int marks;  
}student;

void addstudents(student students[],int n){
    for(int i=0;i<n;i++){
        printf("enter the students details(roll no,name,course,marks\n");
        printf("student %d",i+1);
        scanf("%s %s %s %d",students[i].rollno,students[i].name,students[i].branch,&students[i].marks);
    }
}

void savestudent(student students[],int n){
  FILE* file= fopen("students.txt","w");
  if(file==NULL){
      printf("error creating file\n");
      return;
  }
  for(int i=0;i<n;i++){
       fprintf(file,"%s %s %s %d ",students[i].rollno,students[i].name,students[i].branch,students[i].marks);
  }
  fclose(file);
}


void loadstudent(student students[],int n){
   FILE* file= fopen("students.txt","r");
  if(file==NULL){
      printf("error creating file\n");
      return;
  }
  for(int i=0;i<n;i++){
       fscanf(file,"%s %s %s %d",students[i].rollno,students[i].name,students[i].branch,&students[i].marks);
  }
  fclose(file);
}
     
void searchstudent(student students[],int n){
char search[20];
int found=0;
printf("enter the roll number to search\n");
scanf("%s",search);

for(int i=0;i<n;i++){
if(strcmp(students[i].rollno,search)==0){
    found =1;
    printf("student data found :%s %s %s %d",students[i].rollno,students[i].name,students[i].branch,students[i].marks);
}
}
if(!found){
    printf("no record found\n");
}
}


int main(){
   int n;
   printf("enter the number of students\n");
   scanf("%d",&n);

   student students[n];
   addstudents(students,n);
   searchstudent(students,n);
   savestudent(students,n);
   loadstudent(students,n);
  return 0;
}