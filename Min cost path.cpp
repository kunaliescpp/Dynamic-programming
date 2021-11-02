/*
Problem Link: https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1

Minimum Cost Path 

Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell,
we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 

Note: It is assumed that negative cost cycles do not exist in the input matrix.
 
Example 1:
Input: grid = {{9,4,9,9},{6,7,6,4}, {8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is- 9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.

Example 2:
Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.


Constraints:
1 ≤ n ≤ 500
1 ≤ cost of cells ≤ 1000
*/


class Solution{
    public:
    int minimumCostPath(vector<vector<int>>& grid){
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(m, vector<int> (n));
        
        dp[m-1][n-1] = grid[m-1][n-1];
        
        //fill last row (right to left)
        for(int j = n-2; j >= 0; j--){
            dp[m-1][j] = dp[m-1][j+1] + grid[m-1][j]; 
        }
        
        //fill last column (bottom to top)
        for(int i = m-2; i >= 0; i--){
            dp[i][n-1] = dp[i+1][n-1] + grid[i][n-1];
        }
        
        
        //fill remaining cells
        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
               dp[i][j] = min({dp[i+1][j], dp[i][j+1], dp[i][j-1], dp[i-1][j]}) + grid[i][j];
            }
        }
    
    return dp[0][0];
    }
};


