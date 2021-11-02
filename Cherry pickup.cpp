/*
Problem Link: https://leetcode.com/problems/cherry-pickup/

Cherry Pickup

You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.
0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
 

Example 1:
Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.

Example 2:
Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0
 

Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 50
grid[i][j] is -1, 0, or 1.
grid[0][0] != -1
grid[n - 1][n - 1] != -1
*/


class Solution {
public:
    
    int solver(int r1, int c1, int r2, vector<vector<int>>& arr, vector<vector<vector<int>>>& dp){
        
        int m = arr.size(), n = arr[0].size();
        int c2 = r1+c1-r2;
        if(r1 >= m || r2 >= m || c1 >= n || c2 >= n || arr[r1][c1] == -1 || arr[r2][c2] == -1) return INT_MIN;
        if(r1==n-1 && c1==m-1) return arr[r1][c1];
        if(r2==n-1 && c2==m-1) return arr[r2][c2];
        if(dp[r1][c1][r2] != 0) return dp[r1][c1][r2];
        
        int cherries = 0;
        if(r1 == r2 && c1 == c2){
            cherries += arr[r1][c1];
        } else{
            cherries += arr[r1][c1] + arr[r2][c2];
        }
        
        int p1 = solver(r1, c1+1, r2+1, arr, dp);    //h, h
        int p2 = solver(r1+1, c1, r2,  arr, dp);    //v, h
        int p3 = solver(r1+1, c1, r2+1, arr, dp);    //v, v
        int p4 = solver(r1, c1+1, r2, arr, dp);    //h, v
    
        cherries += max({p1, p2, p3, p4});
        dp[r1][c1][r2] = cherries;
        
    return cherries;
    }  
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)) );
        
        int ans = solver(0, 0, 0, grid, dp);
        if(ans < 0) return 0;
        
    return ans;
    }
};


