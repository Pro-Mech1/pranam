#include<stdio.h>
#include<string.h>
typedef struct{
    char cityname[20];
    char degree[200];
    char humidity[200];
}weather;

void adddetails(weather weathers[],int n){
    for(int i=0;i<n;i++){
        printf("enter the weather(city name degree humidity\n");
        printf("city %d",i+1);
        scanf("%s %s %s",weathers[i].cityname,weathers[i].degree,weathers[i].humidity);
    }
}

void savesweather(weather weathers[],int n){
  FILE* file= fopen("weather.txt","w");
  if(file==NULL){
      printf("error creating file\n");
      return;
  }
  for(int i=0;i<n;i++){
       fprintf(file,"%s %s %s",weathers[i].cityname,weathers[i].degree,weathers[i].humidity);
  }
  fclose(file);
}


void loadweather(weather weathers[],int n){
   FILE* file= fopen("weather.txt","r");
  if(file==NULL){
      printf("error creating file\n");
      return;
  }
  for(int i=0;i<n;i++){
       fscanf(file,"%s %s %s",weathers[i].cityname,weathers[i].degree,weathers[i].humidity);
  }
  fclose(file);
}
     
void searchcity(weather weathers[],int n){
char search[20];
int found=0;
printf("enter the city name to search\n");
scanf("%s",search);

for(int i=0;i<n;i++){
if(strcmp(weathers[i].cityname,search)==0){
    found =1;
    printf( "weather in: %s %s humidty %s degree",weathers[i].cityname,weathers[i].degree,weathers[i].humidity);
}
}
if(!found){
    printf("no order found\n");
}
}


int main(){
   int n;
   printf("enter the number of city to search\n");
   scanf("%d",&n);

    weather weathers[n];
   adddetails(weathers,n);
   searchcity(weathers,n);
   savesweather(weathers,n);
   loadweather(weathers,n);
  return 0;
}