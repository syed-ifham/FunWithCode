#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the circular linked list
typedef struct node
{
  int pos;               // Stores the position number of the person
  struct node *next;     // Pointer to the next node (person)
} node;

// Function to print the circular linked list (for debugging/testing)
void printList(node *head)
{
  if (head == NULL)
  {
    printf("List is empty!\n");
    return;
  }

  node *ptr = head;
  printf("Printing elements:\n");

  // Since it's a circular list, we use do-while to ensure at least one element is printed
  do
  {
    printf("%d ", ptr->pos);  // Print the position
    ptr = ptr->next;          // Move to the next node
  } while (ptr != head);      // Loop ends once we circle back to the head

  printf("\n");
}

// Function to simulate the Josephus Problem
int findWinner(int n, int m)
{
  // Step 1: Create the head (first person in the circle)
  printf("creating head of the circular linked list...\n");
  node *head = (node *)malloc(sizeof(node));
  head->pos = 1;

  node *p = head;
  p->next = p;  // Point it to itself initially (single-node circular list)

  // Step 2: Create the rest of the nodes (people in the circle)
  printf("creating rest of the nodes_/\n");
  for (int i = 2; i <= n; i++)
  {
    node *temp = (node *)malloc(sizeof(node));  // Create new person
    temp->pos = i;          // Assign position number
    p->next = temp;         // Link previous person to new person
    temp->next = head;      // Complete the circular link
    p = temp;               // Move pointer forward
  }
  printf("all nodes successfully created_/\n");

  // Step 3: Start the elimination process
  printf("let's start killing...XxX\n");
  node *prev = p;     // Initially, prev points to the last node
  node *curr = head;  // Start from the first node (head)

  // Continue until only one node remains in the circle
  while (curr->next != curr)
  {
    // Move m steps ahead
    for (int counter = 0; counter < m; counter++)
    {
      prev = curr;        // Move prev forward
      curr = curr->next;  // Move curr forward
    }

    // Eliminate the m-th person (curr)
    printf("Eliminating : %d\n", curr->pos);
    prev->next = curr->next;  // Remove current node from circle
    free(curr);               // Free memory
    curr = prev->next;        // Move to next node
  }

  // The last remaining person is the winner
  int winner = curr->pos;
  free(curr);  // Free the last node
  printf("WINNER : %d", winner);
  return winner;
}

// Main function
int main()
{
  // Run the Josephus simulation with 33 people and step count of 1
  findWinner(8, 1);

  // Optional: testing other method (commented out as it’s incorrect)
  // winner(7);

  return 0;
}
