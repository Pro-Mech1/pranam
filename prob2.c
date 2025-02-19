#include<stdio.h>
#include<string.h>

void vehicleToll(int numvehicles,char vehicle[]){
      float total_charge=0.0f,car_charge=0.0f,truck_charge=0.0f,bike_charge=0.0f,bus_charge=0.0f;
      int vehicletype=-1;
      if(strcmp(vehicle,"car")==0){
        vehicletype=1;
      }
      else if(strcmp(vehicle,"truck")==0){
        vehicletype=2;
      }
      else if(strcmp(vehicle,"bike")==0){
        vehicletype=3;
      }
      else if(strcmp(vehicle,"bus")==0){
        vehicletype=4;
      }
      switch(vehicletype){
        case 1:
        car_charge=car_charge+50.0f;
        break;
        case 2:
        truck_charge=truck_charge+100.0f;
        break;
        case 3:
        bike_charge=bike_charge+20.0f;
        break;
        case 4:
        bus_charge=bus_charge+80.0f;
        break;
      }
        printf("total charge:%f%f%f%f",car_charge+truck_charge,bike_charge,bus_charge);
}

int main(){
       int numvehicles;
       char vehicle[100],i;

       printf("enter the number of vehicles\n");
       scanf("%d",&numvehicles);

       printf("enter the vehicle type(car/truck/bike)\n");
       for(i=0;i<numvehicles;i++){
       scanf("%s",vehicle);
     vehicleToll(numvehicles,vehicle);
       }
  return 0;

}