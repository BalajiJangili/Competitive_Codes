Problem Statement:
Kohli is playing with cricket balls arranged in n numbered sets. The sets are numbered from 1 to n, where set i contains balls[i] cricket balls initially.
Kohli can perform the following operation any number of times:
Take one ball from set i and two balls from set (i+1) in any order, where 1 ≤ i ≤ n-1
This operation can only be performed if set i has at least 1 ball and set (i+1) has at least 2 balls
Kohli starts with 0 balls and wants to maximize the total number of cricket balls he can collect.

Input Format:
First line: t (1 ≤ t ≤ 10^4) - number of test cases
For each test case:
* First line: n (2 ≤ n ≤ 10^5) - number of sets
* Second line: n space-separated integers balls[1], balls[2], ..., balls[n] 
              (0 ≤ balls[i] ≤ 100) - initial cricket balls in each set

Example:

Input:
3 
3

1 4 4 
5
3 0 6 1 0
3
2 6 8

Output:
9
0
15  

Note:

In the first testcase, there are two possible sequences of operations:
From set 2 and 3: take (1,2) → [[1],[1,1]]
From set 1 and 2: take (1,2) → [[1,1],[1]]
In both cases, we can form groups of 3 balls per operation.
So the maximum balls Kohli can collect is:9 (2 operations from sets 2–3 and 1 operation from sets 1–2)

In the second testcase, No valid grouping is possible since for every pair (i, i+1), either balls[i] < 1 or balls[i+1] < 2.
Hence, Kohli cannot perform any operations.
So the maximum balls collected is: 0