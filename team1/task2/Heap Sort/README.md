## Heap Sort

1. Building Binary Heap(Max heap). Binary Heap is a complete binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. A Binary Heap is a complete Binary Tree where elements are stored left to right such that value in a parent node is greater(or smaller) than the values in its two children nodes. The former is called as max heap and the latter is called min heap. 
2. The root element contains maximum element. After that, swap this element with the last element of array and heapify the max heap excluding the last element which is already in its correct position and then decrease the length of heap by one.
3. Repeat the step 2, until all the elements are in their correct position.

### Pseudocode:

Building a Heap:
```
BUILDHEAP (array A, int n)
 1. for i ← n/2 down to 1
 2. do
 3. HEAPIFY (A, i, n)
```
Max-Heapify: 
```
MAX-HEAPIFY (A, i)
 1. l ← left [i]
 2. r ← right [i]
 3. if l≤ heap-size [A] and A[l] > A [i]
 4. then largest ← l
 5. Else largest ← i
 6. If r≤ heap-size [A] and A [r] > A[largest]
 7. Then largest ← r
 8. If largest ≠ i
 9. Then exchange A [i]    A [largest]
 10. MAX-HEAPIFY (A, largest)
```

Heap Sort Algorithm:
```
HEAP-SORT (A)
 1. BUILD-MAX-HEAP (A)
 2. For I ← length[A] down to Z
 3. Do exchange A [1] ←→ A [i]
 4. Heap-size [A] ← heap-size [A]-1
 5. MAX-HEAPIFY (A,1)
```

### Analysis
- Time Complexity:
maximum levels O(log n). At each level,comparison is done which  takes O(1). The total time for heapify is O(log n). Build max-heap takes O(n) running time. 
The total running time of Heap-Sort is O(nlog(n)).

Best case is O(n) when everything in the input is identical.

- Space Complexity: O(1)
