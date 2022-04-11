/*
Problem Link: https://leetcode.com/problems/coin-change/

Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total
amount of money. Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made 
up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0
 
Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       
        int *dp = new int [amount + 1];                     // 1 to 11
        dp[0] = 0;                                          // 0, -1, ... -1;
        for(int i = 1; i <= amount; i++){
            dp[i] = -1;
        }
        
        // dp[total amount-coin] + coin amount where we put coin amount = 1, because we find no. of coins
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if( i >= coins[j] && dp[i-coins[j]] != -1){       
                   if(dp[i] == -1) dp[i] = 1 + dp[i-coins[j]];          //4 may contains 1rs and 2rs coins: for 1
                   else dp[i] = min(dp[i-coins[j]]+1, dp[i]);           // for 2 
                }                                           
            }
        }
    return dp[amount];
    }
};
