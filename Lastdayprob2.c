#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CALLS 5  

typedef struct {
    int call_id;
    char customer_name[50];
} Call;

typedef struct {
    Call queue[MAX_CALLS];
    int front, rear, size;
} CallQueue;

// Function to initialize queue
void initQueue(CallQueue *q) {
    q->front = q->rear = -1;
    q->size = 0;
}

int isFull(CallQueue *q) {
    return q->size == MAX_CALLS;
}

int isEmpty(CallQueue *q) {
    return q->size == 0;
}

void addCall(CallQueue *q, int call_id, char *customer_name) {
    if (isFull(q)) {
        printf("Call queue is full. Cannot add new calls.\n");
        return;
    }

    if (q->rear == MAX_CALLS - 1) 
        q->rear = -1;
    
    q->queue[++q->rear].call_id = call_id;
    strcpy(q->queue[q->rear].customer_name, customer_name);
    q->size++;
    
    printf("New Call Added: Call %d from %s\n", call_id, customer_name);
}


void processCall(CallQueue *q) {
    if (isEmpty(q)) {
        printf("No calls to process.\n");
        return;
    }

    printf("Processing Call: %d from %s\n", q->queue[q->front + 1].call_id, q->queue[q->front + 1].customer_name);
    q->front = (q->front + 1) % MAX_CALLS;
    q->size--;
}

void displayQueue(CallQueue *q) {
    printf("\nRemaining Calls: ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + 1 + i) % MAX_CALLS;
        printf("%d from %s  ", q->queue[index].call_id, q->queue[index].customer_name);
    }
    printf("\n");
}

int main() {
    CallQueue callQueue;
    initQueue(&callQueue);

    addCall(&callQueue, 101, "Alice");
    addCall(&callQueue, 102, "Bob");
    addCall(&callQueue, 103, "Charlie");

    displayQueue(&callQueue);

    processCall(&callQueue);  
    displayQueue(&callQueue);

    processCall(&callQueue);  // Process Bob's call
    displayQueue(&callQueue);

    return 0;
}
