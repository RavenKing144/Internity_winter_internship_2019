## Merge Sort 

Merge sort divides the array in half till we get the base case(single element), sorts each of those halves recursively, and then merges them back together with merge function. Each of those halves has the same sorting algorithm applied to it. Eventually, you are merging just two single element arrays. 
The merge function copy all the elements from the target array segment into a helper array(second array) while keeping track of where the start of the left and right halves should be.
We then iterate through helper, copying the smaller element from each half into the array. At the end, we
copy any remaining elements into the target array.

### Pseudocode:



### Analysis:

* Time Complexity: O(nlog(n)))

Reccurence Relation T(n)=2T(n/2)+O(n)

* Space Complexity: O(n)

Because second array is required with the same size as the array to be sorted.
