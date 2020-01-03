
# Quick Sort #

Quick sort is an example of a divide-and-conquer algorithmc technique. It is also called *partition exchange sort*.
It uses recursive calls for sorting the elements.  
*Divide*: The array is partitioned into two non-empty sub arrays arr[low..q] and arr[q+1..high] such that
each element of arr[low..q] is less than or equal to each element of arr[q+1..high]. Tbe index q is computed as a part of 
partitioning procedure.   
*Conquer*: The two sub arrays are sorted by recursive calls to Quick sort.  

### Algorithm: ###  
1. If there are one or no elements in the array to be sorted, return.  
2. Pick an element in the array to serve as the "*pivot*" point.  
3. Split the array into two parts- one with elements larger than the pivot and the other with elements smaller than the pivot.  
4. Recursively, repeat the algorithm for both halves of the original array.   
 
### Analysis: ###
* Best case: Each partition splits array in halves.  
T(n) = 2T(n/2) + O(n) = O(n log n). 
* Worst case: Each partition gives unbalanced splits.  
T(n) = T(n-1) + O(n) = O(n^2). 
* Average case: In this case ,we dont know where the split occurs. So we take all possible values.  
T(n) = O(n log n) 
* Worst case space complexity: O(1)








