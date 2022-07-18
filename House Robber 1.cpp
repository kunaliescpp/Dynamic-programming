/* Problem Link: https://leetcode.com/problems/house-robber/submissions/

House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can 
rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3). Total amount you can rob = 1 + 3 = 4.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

class Solution {
public:
    
    int solver(vector<int>& v, vector<int>& dp, int i){
        
        if(i < 0) return 0; 
        if(dp[i] != -1) return dp[i];
        
        int ans = max(solver(v, dp, i-1), solver(v, dp, i-2)+v[i]);
    
        dp[i] = ans;
        
    return dp[i];
    }
    
    int rob(vector<int>& v) {
        int n = v.size();
        
        vector<int> dp(n, -1);
        int ans = solver(v, dp, n-1);
        
    return ans;
    }
};
