#include <stdio.h>
#include <stdlib.h>

#define size 50

int queue[size];
int rear = -1;
int front = -1;
void insert() {
    int item;

    if (rear == size - 1 && (rear+1)%size==front) {
        printf("Queue Overflow \n");
    } else {
        if (front == -1) {
            front = 0;
        }

        printf("Enter the element to insert in queue: ");
        scanf("%d",item);
        rear = (rear+1)%size;
        queue[rear] = item;
        printf("Element %d inserted.\n", item);
    }
}
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow \n");
        return;
    } else {
        printf("Deleted Element is: %d\n", queue[front]);
        front = (front+1)%size;
    }
}
void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty ");
    } else {
        printf("Queue is: \n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice;

    while (1) {
        printf("select the operation:");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice \n");
                
        }
    }

    return 0 ;
}