/*
Problem Link: https://leetcode.com/problems/super-egg-drop/

Super Egg Drop

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n. You know that there exists 
a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below 
floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer 
use it. However, if the egg does not break, you may reuse it in future moves. Return the minimum number of moves that you need 
to determine with certainty what the value of f is.

Example 1:
Input: k = 1, n = 2
Output: 2
Explanation: Drop the egg from floor 1. If it breaks, we know that f = 0. Otherwise, drop the egg from floor 2. If it breaks, we 
know that f = 1. If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

Example 2:
Input: k = 2, n = 6
Output: 3
Example 3:

Input: k = 3, n = 14
Output: 4
 
Constraints:
1 <= k <= 100
1 <= n <= 10^4
*/

class Solution{

 public:
   
 int solver(vector<vector<int>>& dp, int n, int k){
     if(k == 1) return n;
     else if(n == 0 || n == 1) return n;

     if(dp[k][n] != -1) return dp[k][n]; 

     int l = 1, r = n;
     int ans = 1e9;
     while(l <= r){
         int mid = (l+r)/2;

         int cand1 = solver(dp, mid-1, k-1);    // broke (check below)
         int cand2 = solver(dp, n-mid, k);      // unbroken (check above)

         if(cand1 < cand2) l = mid+1;
         else r = mid-1; 

         ans = min(ans, max(cand1+1, cand2+1));
     }

     dp[k][n] = ans;
    
 return dp[k][n];
 }

 int superEggDrop(int k, int n) {

     vector<vector<int>> dp(k+1, vector<int> (n+1, -1));   // brick vs floor
     int ans = solver(dp, n, k);
 return ans;  
 }
};


