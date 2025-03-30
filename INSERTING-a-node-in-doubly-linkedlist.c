#include <stdio.h>
#include <stdlib.h>

// Define structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    // Special case: Insert at the beginning
    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // Traverse to the desired position
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // Insert the node
    if (temp != NULL) {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) temp->next->prev = newNode;
        temp->next = newNode;
    } else {
        printf("Position out of bounds\n");
        free(newNode);
    }
}

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                printf("Enter the position to insert the node: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}