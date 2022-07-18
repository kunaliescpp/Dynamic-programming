/* Problem Link: https://leetcode.com/problems/pizza-with-3n-slices/submissions/

Pizza With 3n Slices

There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.

Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum
possible sum of slice sizes that you can pick.

Example 1:
Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with 
size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.

Example 2:
Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.
 
 
Constraints:
3 * n == slices.length
1 <= slices.length <= 500
1 <= slices[i] <= 1000
*/

class Solution {
public:
    
    int solver(int i, int j, int k, vector<int>& v, vector<vector<vector<int>>>& dp){
        
        if(i > j) return 0;
        if(k == 0) return 0;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        int ans = max(solver(i, j-1, k, v, dp), solver(i, j-2, k-1, v, dp) + v[j]);
        
        dp[i][j][k] = ans;
        
    return dp[i][j][k]; 
    }
    
    int maxSizeSlices(vector<int>& v) {
        int n = v.size(), k = n/3;
        
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(k+1, -1)));
        
        int ans = max(solver(0, n-2, k, v, dp), solver(1, n-1, k, v, dp));
    
    return ans;
    }
};


