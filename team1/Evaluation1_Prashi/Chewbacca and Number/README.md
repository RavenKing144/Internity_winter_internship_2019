## Ques2. Chewbacca and NumberLuke 
Skywalker gave Chewbacca an integer number x. 
Chewbacca isn't good  at numbers buthe loves inverting digits in them. 
Inverting digit t means replacing it with digit 9-t.Help Chewbacca to transform the initial number x to the minimum possible positive number byinverting some (possibly, zero) digits. 
The decimal representation of the final number shouldn'tstart with a zero.
- Input FormatThe first line contains a single integer x (1≤x≤10^18) 
-  the number that Luke Skywalkergave to Chewbacca.
- Constraintsx <= 100000000000000000
- Output FormatPrint the minimum possible positive number that Chewbacca can obtain after inverting somedigits. The number shouldn't contain leading zeroes.Sample Input4545Sample Output4444ExplanationThere are many numbers form after inverting the digit. For minimum number, check if inverting digitis less than or greater than the original digit. If it is less, then invert it otherwise leave it.
