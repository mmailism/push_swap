#include <stdio.h>
#include <stdlib.h>

// กำหนดโครงสร้างข้อมูลของโหนดสำหรับ linked list
typedef struct node {
    int             data;
    struct node*    next;
} l_node;

// ฟังก์ชันสร้างโหนดใหม่
l_node* createNode(int data) {
    l_node* newNode = (l_node*)malloc(sizeof(l_node));
    if (newNode == NULL) {
        printf("การจองหน่วยความจำล้มเหลว!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return (newNode);
}

// ฟังก์ชันสำหรับพิมพ์องค์ประกอบในสแต็ก
void printStack(l_node *top) {
    printf("สแต็ก: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

l_node *findLastNode(l_node *head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return NULL;
    }

    while (head->next != NULL) {
        head = head->next;
    }

    return head;
}

void sortStack(l_node **top) {
    if (*top == NULL || (*top)->next == NULL) {
        // If the stack has zero or one element, it is already sorted
        return;
    }

    l_node *current = *top;
    l_node *prev = NULL;
    l_node *next = NULL;
    l_node *last = NULL;
    int temp;
    int swapped;

    // Swap first and second elements if necessary
    if (current->data > current->next->data) {
        temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;
        printStack(*top);
    }

    // Find the last element and its previous
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    last = current;

    // Swap first and last elements if necessary
    if ((*top)->data > last->data) {
        temp = (*top)->data;
        (*top)->data = last->data;
        last->data = temp;
        printStack(*top);
    }

    // Move the pointer back to the beginning
    current = *top;

    // Swap last element with its previous
    while (current->next != last) {
        current = current->next;
    }
    if (current->data > last->data) {
        temp = current->data;
        current->data = last->data;
        last->data = temp;
        printStack(*top);
    }
}

l_node *push(l_node *top, int data) {
    l_node *newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

// ลบโหนดบนสุดของสแต็ก
l_node *pop(l_node *top) {
    if (top == NULL) {
        printf("สแต็กว่างเปล่า\n");
        return NULL;
    }
    l_node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

int main() {
    l_node *top = createNode(3);
    top->next = createNode(1);
    top->next->next = createNode(4);
    top->next->next->next = createNode(2);

    // พิมพ์สแต็กเริ่มต้น
    printf("สแต็กเริ่มต้น ");
    printStack(top);

    // สลับสององค์ประกอบบนสุดของสแต็ก
    sortStack(&top);

    // พิมพ์สแต็กหลังจากการสลับ
    printf("หลังจากสลับ ");
    printStack(top);

    // คืนค่าหน่วยความจำ
    free(top);
    return 0;
}