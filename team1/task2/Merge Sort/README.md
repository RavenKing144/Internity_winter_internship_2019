## Merge Sort 

Merge Sort is a divide and conquer algorithm that divides the array in half till we get the base case(single element), sorts each of those halves recursively, and then merges them back together with merge function. Each of those halves has the same sorting algorithm applied to it. Eventually, you are merging just two single element arrays. 
The merge function copy all the elements from the target array segment into a helper array(second array) while keeping track of where the start of the left and right halves should be.
We then iterate through helper, copying the smaller element from each half into the array. At the end, we
copy any remaining elements into the target array.

### Pseudocode:

* A : input array
* p : starting index of array
* r : ending index of array 

```
MergeSort(A, p, r) {
    if(p<r) {
        q=(p+r)/2
        MergeSort(A, p, q)
        MergeSort(A, q+1, r)
        merege(A, p, q, r)
}
merge(A, p, q, r) {
    Left[] <- A[p....q], Right[] <- A[q+1......r]
    i = 0, j = 0, k = p
    while(i < q-p+1 && j < r-q) {
        if(Left[i] < Right[j] {
            A[k] <- Right[j]
            i++
        else
            A[k] <- Right[j]
            j++
        k++
    while(i < q-p+1) {
        A[k] <- Left[i]
        k++
        i++
    while(j < r-q) {
        A[k] <- Right[j]
        k++
        j++
    }
}
```

### Analysis:

* Time Complexity: O(nlog(n))

Best, Average and Worst Case same time complexity 

Recurrence Relation T(n)=2T(n/2)+O(n)

* Space Complexity: O(n)

Because second array is required with the same size as the array to be sorted.
