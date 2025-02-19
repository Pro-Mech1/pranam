#include<stdio.h>
#include<string.h>
void eligibility(int age,int salary,char choice[]){
    if(age>18 && age<60 )
        if(strcmp(choice,"no")==0 &&salary>=25000){
        printf("patient eligible\n ");
    }
    else{
        printf("not eligible\n");
    }
    else{
        printf("not eligible");
}
}



int main(){
    int age,salary;
    char choice[10];
    printf("enter the age\n");
    scanf("%d",&age);
    
    printf("enter the salary\n");
    scanf("%d",&salary);


    printf("any preexisting condition{yes/no}");
    scanf("%s",choice);

    eligibility(age,salary,choice);
    return 0;
}
    // if(choice==no){
    //  int res=
    // }
    // else{
    //     printf("not eligible\n");
    // }
