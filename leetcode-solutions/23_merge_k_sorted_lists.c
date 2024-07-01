#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

// create new node
struct ListNode *createNode(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Append node to linked list
void appendNode(struct ListNode **head, int val)
{
    struct ListNode *node = createNode(val);
    if (*head == NULL)
    {
        *head = node;
        return;
    }
    struct ListNode *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = node;
}

struct ListNode *listToLinkedList(int *arr, int size)
{
    if (size == 0)
    {
        return NULL;
    }
    struct ListNode *head = createNode(arr[0]);
    struct ListNode *current = head;
    for (int i = 1; i < size; i++)
    {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Print linked list
void printList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to print the contents of the minHeap
void print_minHeap(struct ListNode **minHeap, int heapSize)
{
    printf("Current minHeap: ");
    for (int i = 0; i < heapSize; i++)
    {
        printf("%d ", minHeap[i]->val);
    }
    printf("\n");
}

// Comparator function for the priority queue (min-heap)
int compare(const void *a, const void *b)
{
    struct ListNode *nodeA = *(struct ListNode **)a; // Cast and dereference to get the actual ListNode* pointers
    struct ListNode *nodeB = *(struct ListNode **)b;
    return nodeA->val - nodeB->val; // Compare the val fields of the nodes
}

// Function to merge k sorted linked lists
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (listsSize == 0)
    {
        return NULL; // If there are no lists to merge, return NULL
    }

    // Create a min-heap to keep track of the smallest elements
    struct ListNode **minHeap = (struct ListNode **)malloc(listsSize * sizeof(struct ListNode *));
    int heapSize = 0;

    // Initialize the heap with the first node of each list
    for (int i = 0; i < listsSize; i++)
    {
        if (lists[i] != NULL)
        {
            minHeap[heapSize++] = lists[i]; // Copy the pointer to the first node of the list
        }
    }

    // Build the initial heap by sorting the array of ListNode* pointers
    qsort(minHeap, heapSize, sizeof(struct ListNode *), compare);

    struct ListNode *dummy = createNode(0); // Create a dummy node to simplify the merge process
    struct ListNode *current = dummy;       // Pointer to track the end of the merged list

    while (heapSize > 0)
    {
        // Extract the smallest node from the heap
        struct ListNode *smallest = minHeap[0];
        current->next = smallest; // Add the smallest node to the merged list
        current = current->next;  // Move to the next node

        // Replace the root of the heap with the next node of the extracted node
        if (smallest->next != NULL)
        {
            minHeap[0] = smallest->next; // Move to the next node in the same list
        }
        else
        {
            minHeap[0] = minHeap[--heapSize]; // Remove the last element in the heap
        }

        // Rebuild the heap by sorting the array again
        qsort(minHeap, heapSize, sizeof(struct ListNode *), compare);

        print_minHeap(minHeap, heapSize);
    }

    struct ListNode *mergedHead = dummy->next; // The merged list starts after the dummy node
    free(dummy);                               // Free the dummy node
    free(minHeap);                             // Free the heap memory
    return mergedHead;                         // Return the head of the merged list
}

int main()
{
    // int staticList[] = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    int arr1[] = {1, 4, 5};
    int arr1Size = 3;
    int arr2[] = {1, 3, 4};
    int arr2Size = 3;
    int arr3[] = {2, 6};
    int arr3Size = 2;

    // struct ListNode *head = NULL;

    struct ListNode *head_arr1 = listToLinkedList(arr1, arr1Size);
    struct ListNode *head_arr2 = listToLinkedList(arr2, arr2Size);
    struct ListNode *head_arr3 = listToLinkedList(arr3, arr3Size);

    struct ListNode *lists[] = {head_arr1, head_arr2, head_arr3};
    int listsSize = sizeof(lists) / sizeof(lists[0]);

    struct ListNode *rhead = mergeKLists(lists, listsSize);

    printList(rhead);

    return EXIT_SUCCESS;
}