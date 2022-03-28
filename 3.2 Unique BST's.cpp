/*
Problem Link: https://leetcode.com/problems/unique-binary-search-trees/

Unique BST's 

Given an integer. Find how many structurally unique binary search trees are there that stores the values from 1 to that integer 
(inclusive). 

Example 1:
Input: N = 2
Output: 2
Explanation: for N = 2, there are 2 unique BSTs
     1               2  
      \            /
       2         1
       
Example 2:
Input: N = 3
Output: 5
Explanation: for N = 3, there are 5 possible BSTs
  1           3     3       2     1
    \        /     /      /  \     \
     3      2     1      1    3     2
    /      /       \                 \
   2      1         2                 3

Constraints:
1 <= N <= 1000
*/

class Solution {
public:
    int numTrees(int n) {
        
        int *dp = new int [n+1];
        dp[0] = 1;                       // 0 node se 1 bst ho sakta he i.e. jisme 1 bhi node na ho
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            int l = 0;
            int r = i-1;
            dp[i] = 0;
            
            while( l <= i-1){
                dp[i]+= dp[l]*dp[r];
                l++;
                r--;
            }
        }
    return dp[n];
    }
};


