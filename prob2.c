#include<stdio.h>
#include<string.h>
typedef struct{
    char orderid[10];
    char name[200];
    char product[200];
    int amount;  
}customer;

void adddetails(customer customers[],int n){
    for(int i=0;i<n;i++){
        printf("enter the students details(order id,name,product,amount\n");
        printf("student %d",i+1);
        scanf("%s %s %s %d",customers[i].orderid,customers[i].name,customers[i].product,&customers[i].amount);
    }
}

void savescustomer(customer customers[],int n){
  FILE* file= fopen("customers.txt","w");
  if(file==NULL){
      printf("error creating file\n");
      return;
  }
  for(int i=0;i<n;i++){
       fprintf(file,"%s %s %s %d ",customers[i].orderid,customers[i].name,customers[i].product,customers[i].amount);
  }
  fclose(file);
}


void loadcustomer(customer customers[],int n){
   FILE* file= fopen("customers.txt","r");
  if(file==NULL){
      printf("error creating file\n");
      return;
  }
  for(int i=0;i<n;i++){
       fscanf(file,"%s %s %s %d",customers[i].orderid,customers[i].name,customers[i].product,&customers[i].amount);
  }
  fclose(file);
}
     
void searchsustomerid(customer customers[],int n){
char search[20];
int found=0;
printf("enter the order id to search\n");
scanf("%s",search);

for(int i=0;i<n;i++){
if(strcmp(customers[i].orderid,search)==0){
    found =1;
    printf("order found :%s %s %s %d",customers[i].orderid,customers[i].name,customers[i].product,customers[i].amount);
}
}
if(!found){
    printf("no order found\n");
}
}


int main(){
   int n;
   printf("enter the number of orders\n");
   scanf("%d",&n);

    customer customers[n];
   adddetails(customers,n);
   searchsustomerid(customers,n);
   savescustomer(customers,n);
   loadcustomer(customers,n);
  return 0;
}