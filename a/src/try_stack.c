// #include <stdio.h>
// #include <stdlib.h>

// // กำหนดโครงสร้างข้อมูลของโหนดสำหรับ linked list
// typedef struct node {
//     int             data;
//     struct node*    next;
// } l_node;

// typedef struct l_list {
    
// }

// // ฟังก์ชันสร้างโหนดใหม่
// l_node* createNode(int data) {
//     l_node* newNode = (l_node*)malloc(sizeof(l_node));
//     if (newNode == NULL) {
//         printf("การจองหน่วยความจำล้มเหลว!\n");
//         exit(EXIT_FAILURE);
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     return (newNode);
// }

// // ฟังก์ชันสำหรับพิมพ์องค์ประกอบในสแต็ก
// void printStack(l_node *top) {
//     printf("สแต็ก: ");
//     while (top != NULL) {
//         printf("%d ", top->data);
//         top = top->next;
//     }
//     printf("\n");
// }

// l_node *findLastNode(l_node *head) {
//     if (head == NULL) {
//         printf("Linked list is empty.\n");
//         return NULL;
//     }

//     while (head->next != NULL) {
//         head = head->next;
//     }

//     return head;
// }

// void sortStack(l_node **top) {
//     if (*top == NULL || (*top)->next == NULL) {
//         // If the stack has zero or one element, it is already sorted
//         return;
//     }

//     l_node *current = *top;
//     l_node *prev = NULL;
//     l_node *next = NULL;
//     l_node* last = NULL;
//     int temp;
//     int swapped;

//     // Swap first and second elements if necessary
//     if (current->data > current->next->data) {
//         temp = current->data;
//         current->data = current->next->data;
//         current->next->data = temp;
//         printStack(*top);
//         printf("sa\n");
//     }

//     // Move first node to last position
//     if (current->data > current->next->data)
//     {
//         last = *top;
//         while (last->next != NULL) {
//             last = last->next;
//         }
//         last->next = *top;
//         *top = (*top)->next;
//         last->next->next = NULL;
//         printStack(*top);
//         printf("ra\n");
//     }
// }

// l_node *push(l_node *top, int data) {
//     l_node *newNode = createNode(data);
//     newNode->next = top;
//     return newNode;
// }

// // ลบโหนดบนสุดของสแต็ก
// l_node *pop(l_node *top) {
//     if (top == NULL) {
//         printf("สแต็กว่างเปล่า\n");
//         return NULL;
//     }
//     l_node *temp = top;
//     top = top->next;
//     free(temp);
//     return top;
// }

// int main() {
//     l_node *top = createNode(3);
//     top->next = createNode(2);
//     top->next->next = createNode(4);
//     top->next->next->next = createNode(1);
//     top->next->next->next->next = createNode(5);

//     // พิมพ์สแต็กเริ่มต้น
//     printf("สแต็กเริ่มต้น ");
//     printStack(top);

//     // สลับสององค์ประกอบบนสุดของสแต็ก
//     sortStack(&top);

//     // พิมพ์สแต็กหลังจากการสลับ
//     printf("หลังจากสลับ ");
//     printStack(top);

//     // คืนค่าหน่วยความจำ
//     free(top);
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // Structure for a node in the linked list
// typedef struct node {
//     int data;
//     struct node* next;
// } l_node;

// // Function to create a new node
// l_node* createNode(int data) {
//     l_node* newNode = (l_node*)malloc(sizeof(l_node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed!\n");
//         exit(EXIT_FAILURE);
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to print the elements of the linked list
// void printList(l_node *head) {
//     printf("Linked list: ");
//     while (head != NULL) {
//         printf("%d ", head->data);
//         head = head->next;
//     }
//     printf("\n");
// }

// // Function to swap the first two elements and move the first element to the end
// void swapAndMove(l_node **head) {
//     if (*head == NULL || (*head)->next == NULL) {
//         // If the list is empty or has only one element, no swapping is needed
//         return;
//     }
    
//     // Swap the first two elements
//     l_node *first = *head;
//     l_node *second = (*head)->next;
//     *head = second;
//     first->next = second->next;
//     second->next = first;
    
//     // Move the first element to the end
//     l_node *last = *head;
//     while (last->next != NULL) {
//         last = last->next;
//     }
//     last->next = first;
//     first->next = NULL;
// }

// int main() {
//     // Create the linked list with the given input
//     l_node *head = createNode(5);
//     head->next = createNode(4);
//     head->next->next = createNode(1);

//     // Print the initial linked list
//     printf("Initial ");
//     printList(head);

//     // Perform the required operations
//     swapAndMove(&head);

//     // Print the modified linked list
//     printf("Modified ");
//     printList(head);

//     // Free the allocated memory
//     while (head != NULL) {
//         l_node *temp = head;
//         head = head->next;
//         free(temp);
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure of a node
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function to find the maximum value in the linked list
// int findMax(struct Node* head) {
//     // Initialize max_val to store the maximum value found so far
//     int max_val = head->data; // assuming the list is not empty
    
//     // Traverse the linked list
//     while (head != NULL) {
//         // Update max_val if the current node's value is greater
//         if (head->data > max_val) {
//             max_val = head->data;
//         }
//         // Move to the next node
//         head = head->next;
//     }
    
//     return max_val;
// }

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // Main function
// int main() {
//     // Create a sample linked list: 3 -> 7 -> 2 -> 9 -> 5
//     struct Node* head = createNode(3);
//     head->next = createNode(7);
//     head->next->next = createNode(2);
//     head->next->next->next = createNode(9);
//     head->next->next->next->next = createNode(5);

//     // Find the maximum value in the linked list
//     int max_val = findMax(head);

//     // Print the maximum value
//     printf("The maximum value in the linked list is: %d\n", max_val);

//     // Free memory allocated for nodes
//     while (head != NULL) {
//         struct Node* temp = head;
//         head = head->next;
//         free(temp);
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// // Define the structure of a node
// typedef struct s_stack {
//     int nb;
//     struct s_stack *next;
// } t_stack;

// // Function to create a new node
// t_stack *new_node(int nb) {
//     t_stack *node = (t_stack *)malloc(sizeof(t_stack));
//     if (node == NULL) {
//         fprintf(stderr, "Memory allocation failed\n");
//         exit(EXIT_FAILURE);
//     }
//     node->nb = nb;
//     node->next = NULL;
//     return node;
// }

// // Function to push a node onto the stack
// void push(t_stack **stack, int nb) {
//     t_stack *node = new_node(nb);
//     if (*stack == NULL || nb < (*stack)->nb) {
//         node->next = *stack;
//         *stack = node;
//     } else {
//         t_stack *current = *stack;
//         while (current->next != NULL && nb > current->next->nb) {
//             current = current->next;
//         }
//         node->next = current->next;
//         current->next = node;
//     }
// }

// // Function to print the stack
// void print_stack(t_stack *stack) {
//     printf("Stack: ");
//     while (stack != NULL) {
//         printf("%d ", stack->nb);
//         stack = stack->next;
//     }
//     printf("\n");
// }

// int main() {
//     srand(time(NULL));

//     t_stack *stack = NULL;

//     // Display stack before sorting
//     printf("Before sorting:\n");
//     print_stack(stack);
//     printf("\n");

//     // Generate and push 100 random integers onto the stack
//     for (int i = 0; i < 100; i++) {
//         int num = rand() % 1000; // Generating random integers between 0 and 999
//         push(&stack, num);
//     }

//     // Display stack after pushing
//     printf("After pushing:\n");
//     // print_stack(stack);
//     printf("\n");

//     return 0;
// }

