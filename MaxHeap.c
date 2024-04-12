#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int capacity;
    int curr_size;
} max_heap;

int parent(max_heap h, int i) {
    return (i - 1) / 2;
}

int left(max_heap h, int i) {
    return 2 * i + 1;
}

int right(max_heap h, int i) {
    return 2 * i + 2;
}

void print(max_heap p) {
    for (int i = 0; i < p.curr_size; i++)
        printf("%d ", p.arr[i]);
    printf("\n");
}

void heapifyUp(max_heap* h, int index) {
    int parentIndex = parent(*h, index);
    while (index > 0 && h->arr[index] > h->arr[parentIndex]) {
        int temp = h->arr[index];
        h->arr[index] = h->arr[parentIndex];
        h->arr[parentIndex] = temp;
        index = parentIndex;
        parentIndex = parent(*h, index);
    }
}

void heapifyDown(max_heap* h, int index) {
    int maxIndex = index;
    int leftChild = left(*h, index);
    int rightChild = right(*h, index);

    if (leftChild < h->curr_size && h->arr[leftChild] > h->arr[maxIndex])
        maxIndex = leftChild;

    if (rightChild < h->curr_size && h->arr[rightChild] > h->arr[maxIndex])
        maxIndex = rightChild;

    if (maxIndex != index) {
        int temp = h->arr[index];
        h->arr[index] = h->arr[maxIndex];
        h->arr[maxIndex] = temp;
        heapifyDown(h, maxIndex);
    }
}

void insert(max_heap* h, int value) {
    if (h->curr_size == h->capacity) {
        printf("Heap is full. Cannot insert any more elements.\n");
        return;
    }

    h->arr[h->curr_size] = value;
    heapifyUp(h, h->curr_size);
    h->curr_size++;
}

int extractMax(max_heap* h) {
    if (h->curr_size == 0) {
        printf("Heap is empty. Cannot extract maximum element.\n");
        return -1;
    }

    int maxElement = h->arr[0];
    h->arr[0] = h->arr[h->curr_size - 1];
    h->curr_size--;
    heapifyDown(h, 0);

    return maxElement;
}

void deleteValue(max_heap* h, int value) {
    int index = -1;

    // Find the index of the value in the heap
    for (int i = 0; i < h->curr_size; i++) {
        if (h->arr[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Value not found in the heap.\n");
        return;
    }

    // Replace the value with the last element
    h->arr[index] = h->arr[h->curr_size - 1];
    h->curr_size--;

    // Perform heapify operations to restore the heap property
    heapifyUp(h, index);
    heapifyDown(h, index);
}

int main() {
    max_heap heap;
    heap.capacity = 10;
    heap.curr_size = 0;
    heap.arr = (int*)malloc(heap.capacity * sizeof(int));

    insert(&heap, 5);
    insert(&heap, 3);
    insert(&heap, 7);
    insert(&heap, 1);
    insert(&heap, 9);

    printf("Heap elements before deletion: ");
    print(heap);

    deleteValue(&heap, 3);

    printf("Heap elements after deletion: ");
    print(heap);

    free(heap.arr);

    return 0;
}
