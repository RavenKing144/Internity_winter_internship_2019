## Ques1. Painter's Partition Problem
Given ​K​ painters to paint ​N​ boards where each painter takes 1 unit of time to paint 1 unit ofboards i.e. if the length of a particular board is 5, it will take 5 units of time to paint the board.
Compute the minimum amount of time to paint all the boards.
Note that:
- Every painter can paint only contiguous segments of boards.
- A board can only be painted by 1 painter at maximum.
- Input FormatFirst line contains
- K​ which is the number of painters. 
- Second line contains ​N​ which indicates thenumber of boards. 
- Third line contains N space separated integers representing the length ofeach board.
- Constraints 1 <= K <= 101 <= N <= 101<= Length of each Board <= 10^8Output 
Format Output the minimum time required to paint the board.
Sample 
Input
- 2
- 2
- 1 10
- Sample Output 10
