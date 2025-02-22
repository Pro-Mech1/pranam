#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPACITY 2  // Change this value to set train capacity
#define MAX_WAITLIST 5  // Change this value to set waiting list size

typedef struct {
    char name[50];
} Passenger;

typedef struct {
    Passenger queue[MAX_CAPACITY];
    int front, rear, size;
} ReservationQueue;

typedef struct {
    Passenger queue[MAX_WAITLIST];
    int front, rear, size;
} WaitingQueue;

void initQueue(ReservationQueue *q) {
    q->front = q->rear = -1;
    q->size = 0;
}

void initWaitingQueue(WaitingQueue *q) {
    q->front = q->rear = -1;
    q->size = 0;
}


int isFull(ReservationQueue *q) {
    return q->size == MAX_CAPACITY;
}

int isEmpty(ReservationQueue *q) {
    return q->size == 0;
}

int isWaitingFull(WaitingQueue *q) {
    return q->size == MAX_WAITLIST;
}

void addReservation(ReservationQueue *rQueue, WaitingQueue *wQueue, char *name) {
    if (!isFull(rQueue)) {
        if (rQueue->rear == MAX_CAPACITY - 1) 
            rQueue->rear = -1;
        strcpy(rQueue->queue[++rQueue->rear].name, name);
        rQueue->size++;
        printf("Booking Confirmed: %s\n", name);
    } else {
        if (!isWaitingFull(wQueue)) {
            if (wQueue->rear == MAX_WAITLIST - 1) 
                wQueue->rear = -1;
            strcpy(wQueue->queue[++wQueue->rear].name, name);
            wQueue->size++;
            printf("Waiting List: %s\n", name);
        } else {
            printf("No available seats, and waiting list is full.\n");
        }
    }
}

void processBooking(ReservationQueue *rQueue, WaitingQueue *wQueue) {
    if (!isEmpty(rQueue)) {
        printf("Ticket Processed: %s\n", rQueue->queue[rQueue->front + 1].name);
        rQueue->front = (rQueue->front + 1) % MAX_CAPACITY;
        rQueue->size--;
      
        if (wQueue->size > 0) {
            strcpy(rQueue->queue[rQueue->rear + 1].name, wQueue->queue[wQueue->front + 1].name);
            rQueue->rear = (rQueue->rear + 1) % MAX_CAPACITY;
            rQueue->size++;

            printf("Booking Confirmed from Waiting List: %s\n", wQueue->queue[wQueue->front + 1].name);

            wQueue->front = (wQueue->front + 1) % MAX_WAITLIST;
            wQueue->size--;
        }
    } else {
        printf("No reservations to process.\n");
    }
}

void displayStatus(ReservationQueue *rQueue, WaitingQueue *wQueue) {
    printf("\nCurrent Reservations: ");
    for (int i = 0; i < rQueue->size; i++) {
        int index = (rQueue->front + 1 + i) % MAX_CAPACITY;
        printf("%s ", rQueue->queue[index].name);
    }
    printf("\nWaiting List: ");
    for (int i = 0; i < wQueue->size; i++) {
        int index = (wQueue->front + 1 + i) % MAX_WAITLIST;
        printf("%s ", wQueue->queue[index].name);
    }
    printf("\n");
}

int main() {
    ReservationQueue reservations;
    WaitingQueue waitingList;

    initQueue(&reservations);
    initWaitingQueue(&waitingList);

    addReservation(&reservations, &waitingList, "Alice");
    addReservation(&reservations, &waitingList, "Bob");
    addReservation(&reservations, &waitingList, "Charlie"); 
    addReservation(&reservations, &waitingList, "David");    

    displayStatus(&reservations, &waitingList);

    processBooking(&reservations, &waitingList); 
    processBooking(&reservations, &waitingList); 
    processBooking(&reservations, &waitingList); 
    displayStatus(&reservations, &waitingList);

    return 0;
}
