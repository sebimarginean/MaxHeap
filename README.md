# Max Heap Implementation in C

## Overview
This repository contains a C implementation of a max heap data structure. A max heap is a complete binary tree where the value of each node is greater than or equal to the values of its children. This property makes max heaps useful for implementing priority queues, where the highest priority element is always at the front.

## Features
- **Insertion**: Insert elements into the heap while maintaining the max heap property.
- **Extraction**: Extract the maximum element from the heap.
- **Deletion**: Delete a specific element from the heap.
- **Heapify**: Maintain the heap property after insertion or deletion.
- **Print**: Display the current elements in the heap.

## Requirements
- A standard C compiler like GCC or Clang.
- Basic C programming knowledge.

## Compilation and Execution
To compile and run the max heap program, use the following commands:

```bash
gcc -o maxHeap maxHeap.c
./maxHeap
