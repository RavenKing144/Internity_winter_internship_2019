The first two approaches could be optimized if we use only one queue, instead of two queues.

Push:
When we push an element into a queue, it will be stored at back of the queue due to queue's properties. But we need to implement a stack, where last inserted element should be in the front of the queue, not at the back. To achieve this we can invert the order of queue elements when pushing a new element.

- Time complexity : O(n) removes n elements and inserts n + 1 elements to q1 , where n is the stack size.
- Space complexity : O(1)

Pop: 
The last inserted element is always stored at the front of q1 and we can pop it for constant time.

- Time complexity : O(1).
- Space complexity : O(1).
