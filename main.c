#include<stdio.h>
#include<string.h>
typedef struct{
    int id;
    char name[50];
    float salary;
    char department[50];
}employee;

void reademployees( employee employees[],int n);
void displayemployees(employee employees[],int n);
employee findhighest(employee employees[],int n);
void savemployees(employee employees[],int n);
void loademployees(employee emplyees[],int n);

int main(){
    int n;
    float high;
    printf("enter the number of employees\n");
    scanf("%d",&n);


    employee employees[1000];

    reademployees(employees,n);
    displayemployees(employees,n);
    employee result = findhighest(employees,n);
    savemployees(employees,n);
    loademployees(employees,n);

    printf("highestsalary%d %s %f %s",result.id,result.name,result.salary,result.department);

return 0;
}
void reademployees( employee employees[],int n){
     for(int i=0;i<n;i++){
      printf("enter the Id,name,salary,department\n");
       scanf("%d %s %f %s",&employees[i].id,employees[i].name,&employees[i].salary,employees[i].department);
    }
 }
 void displayemployees(employee employees[],int n){
    printf("**employee details are**");
    for(int i=0;i<n;i++){
         printf("%d %s %f %s",employees[i].id,employees[i].name,employees[i].salary,employees[i].department);
    }
 }


 void savemployees(employee employees[],int n){
   FILE* file= fopen("employees.txt","w");
   if(file==NULL){
       printf("error creating file\n");
       return;
   }
   for(int i=0;i<n;i++){
        fprintf(file,"%d %s %f %s ",employees[i].id,employees[i].name,employees[i].salary,employees[i].department);
   }
   fclose(file);
 }


 void loademployees(employee employees[],int n){
    FILE* file= fopen("employees.txt","r");
   if(file==NULL){
       printf("error creating file\n");
       return;
   }
   for(int i=0;i<n;i++){
        fscanf(file,"%d %s %f %s",&employees[i].id,employees[i].name,&employees[i].salary,employees[i].department);
   }
   fclose(file);
 }
 



  employee findhighest(employee employees[],int n){
     employee high = employees[0];
       for(int i=1;i<n;i++){
             if(employees[i].salary>high.salary){
                high.salary= employees[i].salary;
             }
             return high;
        }
        
       }
