/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

void swap(struct ListNode **a, struct ListNode **b) {
    struct ListNode *t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(struct ListNode *heap[], int idx) {
    while (idx > 0) {
        int p = (idx - 1) / 2;
        if (heap[p]->val <= heap[idx]->val)
            break;
        swap(&heap[p], &heap[idx]);
        idx = p;
    }
}

void heapifyDown(struct ListNode *heap[], int size, int idx) {
    while (1) {
        int smallest = idx;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;

        if (l < size && heap[l]->val < heap[smallest]->val)
            smallest = l;

        if (r < size && heap[r]->val < heap[smallest]->val)
            smallest = r;

        if (smallest == idx)
            break;

        swap(&heap[idx], &heap[smallest]);
        idx = smallest;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;

    struct ListNode *heap[10000];
    int heapSize = 0;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i]) {
            heap[heapSize] = lists[i];
            heapifyUp(heap, heapSize);
            heapSize++;
        }
    }

    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;

    while (heapSize > 0) {
        struct ListNode *minNode = heap[0];

        tail->next = minNode;
        tail = tail->next;

        if (minNode->next) {
            heap[0] = minNode->next;
        } else {
            heap[0] = heap[--heapSize];
        }

        heapifyDown(heap, heapSize, 0);
    }

    return dummy.next;
}