#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

void printLinkedList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
    return;
}

// Function to create a new node
struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void appendNode(struct ListNode **head, int val)
{
    struct ListNode *newNode = createNode(val);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct ListNode *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    struct ListNode *cur = dummy;

    while (list1 && list2)
    {
        if (list1->val > list2->val)
        {
            cur->next = list2;
            list2 = list2->next;
        }
        else
        {
            cur->next = list1;
            list1 = list1->next;
        }
        cur = cur->next;
    }

    cur->next = list1 ? list1 : list2;

    return dummy->next;
}

int main()
{
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;
    // Initialize list1 = [1, 2, 4]
    appendNode(&list1, 1);
    appendNode(&list1, 2);
    appendNode(&list1, 4);

    // Initialize list2 = [1, 3, 4]
    appendNode(&list2, 1);
    appendNode(&list2, 3);
    appendNode(&list2, 4);
    struct ListNode *result = mergeTwoLists(list1, list2);
    printLinkedList(result);
    return EXIT_SUCCESS;
}