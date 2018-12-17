
// C code to implement Priority Queue 
// using Linked List 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>





// Node

typedef struct node {
    int data;
    double time;
    struct node* next;

} Node;
Node* newNode(int d, int p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->time = p;
    temp->next = NULL;

    return temp;
}
// Function to Create A New Node 
void event_initialize(struct node *Node){
  Node = malloc(sizeof(Node));
    Node->data = 0;
    Node->time = 0.0;
    Node->next = 0;

    //return temp;
}

// Return the value at head 
int peek(Node** head)
{
    return (*head)->data;
}

// Removes the element with the 
// highest priority form the list 
void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
  //  free(temp);
}

// Function to push according to priority Neue dateien
void event_store(Node** head, int d, int p)
{
    Node* start = (*head);

    // Create new Node 
    Node* temp = newNode(d, p); //Erstellen eines neuen knotens

    // Special Case: The head of list has lesser 
    // priority than new node. So insert new 
    // node before head node and change head node. 
    if ((*head)->time > p) {

        // Insert New Node before head 
        temp->next = *head;
        (*head) = temp;
    }
    else {

        // Traverse the list and find a 
        // position to insert new node 
        while (start->next != NULL &&
               start->next->time < p) {
            start = start->next;
        }

        // Either at the ends of the list 
        // or at required position 
        temp->next = start->next;
        start->next = temp;
    }
}

// Function to check is list is empty 
int isEmpty(Node** head)
{
    return (*head) == NULL;
}

// Driver code 
int main()
{
    srand(time(NULL));
    // Create a Priority Queue 
    // 7->4->5->6
    int i;
    long id ;
    int n = 100;
  //  for (i=0;i<n;i++) {
   //     event_store (rand()%100,myrand()*10);

// Ereignisliste fuellen
// Zufallstyp (1..100)
// Zeit : in 0..10 sec .
 //   }

    Node* head;
    event_initialize(&head);// 1 repräsentiert die priorität
    event_store(&head, 5, rand () % 100);
    event_store(&head, 6, rand () % 100);
    event_store(&head, 7, rand () % 100);

    while (!isEmpty(&head)) {
        printf("%d ", peek(&head));
        pop(&head);
    }

    return 0;
}
