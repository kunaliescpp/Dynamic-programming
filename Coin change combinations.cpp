/*
Problem Link: https://leetcode.com/problems/coin-change-2/

Coin change combinations 

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

 
Constraints:
1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/

int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

    for(int i = 1; i <= n; i++){
        int val = coins[i-1];
        dp[i][0] = 1;
        for(int j = 1; j <= amount; j++){
            if(val <= j) dp[i][j] = dp[i][j-val] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
return dp[n][amount];
}

// => 1D-dp approach

//         int change(int amount, vector<int>& coins) {
//         int n = coins.size();

//         vector<int> dp(amount+1, 0);
//         dp[0] = 1;
//         for(int i = 0; i < n; i++){
//             int val = coins[i];
//             for(int j = val; j <= amount; j++){
//                 dp[j]+= dp[j-val];
//             }
//         }
//     return dp[amount];


