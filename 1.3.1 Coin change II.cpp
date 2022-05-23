/*
Problem Link: https://leetcode.com/problems/coin-change-2/

Coin Change 2

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
Input: amount = 10, coins = [10]
Output: 1
 
Constraints:
1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        sort(coins.begin(), coins.end());
        int n = coins.size();
        for(int i = n-1; i >= 0; i--){
            if(coins[i] > amount){
                coins.resize(i+1);
                break;
            }
        }
      
        n = coins.size();
        vector<vector<int>> dp(2, vector<int>(amount+1,0));
        for(int i = 0, ptr = 0; i < n; i++, ptr^=1){
            for(int j = 1; j <= amount; j++){
                dp[ptr][j] = dp[1-ptr][j];
                if(j-coins[i] > 0)
                    dp[ptr][j] += dp[ptr][j-coins[i]];
                if(j-coins[i] == 0)
                    dp[ptr][j]++;
            }
        }
     return dp[1-(n%2)][amount];
    }
};


