/* 
problem Link: https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1

Nth catalan number 

Given a number N. The task is to find the Nth catalan number.
The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
Note: Positions start from 0 as shown above.

Example 1:
Input: N = 5
Output: 42

Example 2:
Input: N = 4
Output: 14


Constraints:
1 <= N <= 100
*/


class Solution{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        cpp_int dp[n+1];                               // ||cpp_int|| is necessary
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            dp[i] = 0;                                 // dp[i] = 0 is necessary
           for(int j = 0; j < i; j++){
               dp[i] += dp[j]*dp[i-j-1];               
           }
        }
    
    return dp[n];
    }
};


