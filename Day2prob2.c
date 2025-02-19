#include<stdio.h>
#include<string.h>

typedef struct{
    char name[100];
    int age;
    char destination[100];
}Passenger;

int addDetails(int n,Passenger passengers[]){
    for(int i = 0;i < n;i++){
        printf("Passenger %d: \n",i+1);
        printf("Enter Name: ");
        scanf("%s",passengers[i].name);

        printf("Enter Age: ");
        scanf("%d",&passengers[i].age);

        printf("Enter destination: ");
        scanf("%s",passengers[i].destination);
    }
}

void sortPassengers(Passenger passengers[], int n) {
    Passenger temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(passengers[i].destination, passengers[j].destination) > 0) {
                temp = passengers[i];
                passengers[i] = passengers[j];
                passengers[j] = temp;
            }
        }
    }
}

void sortedPassengers(Passenger passengers[], int n) {
    printf("\nSorted List (by destination):\n");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%s - Destination: %s\n", passengers[i].name,passengers[i].destination);
    }
}

void searchDestination(char* search, Passenger passengers[], int n) {
    printf("\nEnter destination to search: ");
    scanf("%s", search);
    printf("Passengers travelling to %s:\n", search);
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (strcmp(passengers[i].destination, search) == 0) {
            printf("%s\n", passengers[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers found traveling to %s\n", search);
    }
}

int main(){
    int n,choice;
    char search[50];
    printf("Enter the number of passengers: ");
    scanf("%d",&n);
    Passenger passengers[n];
    addDetails(n,passengers);
    sortPassengers(passengers, n);
    sortedPassengers(passengers, n);
    searchDestination(search,passengers,n);
    return 0;
} 
