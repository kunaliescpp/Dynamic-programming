/* 
Problem Link: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1/

Knapsack with Duplicate Items 

Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with 
weight limit W. The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Example 1:
Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explanation: 
1.Pick the 2nd element thrice.
2.Total profit = 1 + 1 + 1 = 3. Also the total weight = 1 + 1 + 1  = 3 which is <= W.
 
Example 2:
Input: N = 4, W = 8
val[] = {1, 4, 5, 7}
wt[] = {1, 3, 4, 5}
Output: 11
Explanation: The optimal choice is to pick the 2nd and 4th element.


Constraints:
1 ≤ N, W ≤ 1000
1 ≤ val[i], wt[i] ≤ 100
*/

int knapSack(int n, int W, int val[], int wt[]){

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            int curr_val = val[i-1], curr_wt = wt[i-1];
            if(j-curr_wt < 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-curr_wt] + curr_val);
        }
    }

return dp[n][W]; 
}


