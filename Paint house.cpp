/*
Problem Link: https://www.lintcode.com/problem/516/
 
Paint House

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a
certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is 
the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find 
the minimum cost to paint all houses.

Example 1: 
Input: costs = [[14,2,11],[11,14,5],[14,3,10]]
Output: 10
Explanation: The three house use color [1,2,1] for each house. The total cost is 10.

Example 2
Input: costs = [[5]]
Output: 5
Explanation: There is only one color and one house.
*/


class Solution {
public:
   
    int minCostII(vector<vector<int>> &costs) {
        
        int m = costs.size();
        int n = costs[0].size();
        int dp[m][n];
      
        int mini = -1, sec_mini = -1;
        for(int j = 0; j < n; j++){                           //filling 1st row
            dp[0][j] = costs[0][j];

            if(mini >= dp[0][j]){
                sec_mini = mini;
                mini = dp[0][j];
            } 
            else if(sec_mini >= dp[0][j]){
                sec_mini = dp[0][j];
            }
        }

        for(int i = 1; i < m; i++){
            int nmini = -1, nsec_mini = -1;
            for(int j = 0; j < n; j++){
               
               if(mini == dp[i-1][j]){
                   dp[i][j] = costs[i][j] + mini;
               } else{
                   dp[i][j] = costs[i][j] + sec_mini;
               }

               if(nmini >= dp[i][j]){
                   nsec_mini = nmini;
                   nmini = dp[i][j];
               } 
               else if(nsec_mini >= dp[i][j]){
                   nsec_mini = dp[i][j];
               }

               mini = nmini;
               sec_mini = nsec_mini;
            }
        }

    return mini;
    }

};


