/*
Problem Link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

0 - 1 Knapsack Problem 

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value 
in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with 
N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of 
val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick
the complete item or don’t pick it (0-1 property).

Example 1:
Input: N = 3, W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

Example 2:
Input: N = 3, W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0


Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000
*/

class Solution{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int dp[n+1][W+1];
        
        //fill 1st row and 1st col with 0
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 1; j <= W; j++) dp[0][j] = 0;
    
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= W; j++){
              
                //agr itni balls he hi mhi jisme curr player batting karta he to 
                if(wt[i-1] > j) dp[i][j] = dp[i-1][j];     //piche vale player ki value daldo
                
                else{
                    dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]); 
                }
            
            }
        }
       
    return dp[n][W];
    }
};


