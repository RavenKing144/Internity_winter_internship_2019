## Costly - Push operation

The new element to be added should be at the front of queue. Therefore two queues are used to implement the stack. 
q1 to store the data and q2 to store the data temporarily.

### Analysis:
- push: ** Time Complexity : O(n) (Need to move all elements of q1 to q2)
** Space Complexity: O(1)
- pop: ** Time Complexity : O(1) (Need to remove one element for q1)
** Space Complexity : O(1)
