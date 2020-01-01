Costly - Pop operation
The new element to be added should be at the front of queue. Therefore two queues are used to implement the stack. q1 to store the data and q2 to store the data temporarily.

## Analysis:
- push: O(1) (Need to add one element )
- pop: O(n) (Need to move elements from one queue to another queue)

