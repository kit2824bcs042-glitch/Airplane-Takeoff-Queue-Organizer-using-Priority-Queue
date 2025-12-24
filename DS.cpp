#include <stdio.h>
#include <string.h>

#define MAX 10

struct Airplane {
    char flightNo[10];
    int priority;
};

struct Airplane pq[MAX];
int size = 0;

void enqueue(char flightNo[], int priority) {
    int i;
    if (size == MAX) {
        printf("Queue is full!\n");
        return;
    }

    strcpy(pq[size].flightNo, flightNo);
    pq[size].priority = priority;
    i = size;
    size++;

    while (i > 0 && pq[i].priority > pq[i - 1].priority) {
        struct Airplane temp = pq[i];
        pq[i] = pq[i - 1];
        pq[i - 1] = temp;
        i--;
    }
}

void dequeue() {
    if (size == 0) {
        printf("No airplanes in queue!\n");
        return;
    }

    printf("Takeoff: Flight %s (Priority %d)\n",
           pq[0].flightNo, pq[0].priority);

    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

void display() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("\nAirplane Takeoff Queue:\n");
    for (int i = 0; i < size; i++) {
        printf("Flight: %s | Priority: %d\n",
               pq[i].flightNo, pq[i].priority);
    }
}

int main() {
    enqueue("AI101", 3);
    enqueue("EM911", 5);
    enqueue("VIP007", 4);
    enqueue("CG303", 2);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}

