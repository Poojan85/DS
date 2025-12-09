#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to create a linked list
void createList(int n) {
    struct node *newnode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("\nLinked list created successfully.\n");
}

void deleteFirst(){
    struct node *temp=head;
    if(head==NULL){
        printf("Empty List\n");
        return;
    }
    head=head->next;
    printf("Deleted element : %d\n",temp->data);
    free(temp);
}

void deleteSpecified(int val){
    struct node *temp=head,*prev=NULL;
    if(head==NULL){
        printf("Empty List\n");
        return;
    }
    if(head->data==val){
        head=head->next;
        printf("Element %d deleted\n",val);
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=val){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Element %d not found\n",val);
        return;
    }
    prev->next=temp->next;
    printf("Element %d deleted\n",val);
    free(temp); 
}

void deleteLast(){
    struct node *temp=head,*prev=NULL;
    if(head==NULL){
        printf("Empty List\n");
        return;
    }
    if(head->next==NULL){
        printf("Deleted element %d\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    printf("Deleted %d\n",temp->data);
    prev->next=NULL;
    free(temp);
}

void displayList() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, val;
    printf("\n-- Singly Linked List Operations --\n");
        printf("1. Create Linked List\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete Any Value\n");
        printf("4. Delete at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

    while (1) {
       

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                printf("Enter value : ");
                scanf("%d",&val);
                deleteSpecified(val);
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                displayList();
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
           

           
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}