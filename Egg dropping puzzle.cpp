/*
Problem Link: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

Egg Dropping Puzzle 

You are given N identical eggs and you have access to a K-floored building from 1 to K.
There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or 
below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again. A broken egg must be discarded. The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:
Input: N = 1, K = 2
Output: 2
Explanation: 
1. Drop the egg from floor 1. If it  breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
   
Example 2:
Input: N = 2, K = 10
Output: 4

Constraints:
1 <= N <= 200
1 <= K <= 200
*/

class Solution{

  public:
  //find the critical floor.
  int eggDrop(int n, int k){    // k = floor, n = bricks

      vector<vector<int>> dp(n+1, vector<int> (k+1));   // brick vs floor

      //fill remaining cells
      for(int i = 1; i <= n; i++){
          for(int j = 1; j <= k; j++){
              if(i == 1) dp[i][j] = j;
              else if(j == 1) dp[i][j] = 1;
              else{
                  int mini = INT_MAX;
                  int pj = 0;
                  for(int nj = j-1; nj >= 0; nj--){
                      int v1 = dp[i][nj];    //egg survives
                      int v2 = dp[i-1][pj];  //egg breaks
                      int val = max(v1, v2);
                      mini = min(mini, val);
                      pj++; //egg breaks
                      int val = max(v1, v2);
                      mini = min(mini, val);
                      pj++;
                  }
                  dp[i][j] = mini+1;
              }
          }
      }
  return dp[n][k];
  }
};


