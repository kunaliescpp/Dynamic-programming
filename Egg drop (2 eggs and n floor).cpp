/*
Problem Link: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

Egg Drop With 2 Eggs and N Floors

You are given two identical eggs and you have access to a building with n floors labeled from 1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg 
dropped at or below floor f will not break.
In each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer 
use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:
Input: n = 2
Output: 2
Explanation: We can drop the first egg from floor 1 and the second egg from floor 2. If the first egg breaks, we know that f = 0.
If the second egg breaks but the first egg didn't, we know that f = 1. Otherwise, if both eggs survive, we know that f = 2.

Example 2:
Input: n = 100
Output: 14
Explanation: One optimal strategy is:
- Drop the 1st egg at floor 9. If it breaks, we know f is between 0 and 8. Drop the 2nd egg starting from floor 1 and going up one
  at a time to find f within 7 more drops. Total drops is 1 + 7 = 8.
- If the 1st egg does not break, drop the 1st egg again at floor 22. If it breaks, we know f is between 9 and 21. Drop the 2nd egg 
  starting from floor 10 and going up one at a time to find f within 12 more
  drops. Total drops is 2 + 12 = 14.
- If the 1st egg does not break again, follow a similar process dropping the 1st egg from floors 34, 45, 55, 64, 72, 79, 85, 90, 94, 
  97, 99, and 100.
Regardless of the outcome, it takes at most 14 drops to determine f.
 
 
Constraints:
1 <= n <= 1000
*/

class Solution {
public:
    //with certainty = may be that floor is not present
    int twoEggDrop(int f) {       
        
        vector<int> dp(f+1);   // floor vs brick
        dp[0] = 0;
        //fill remaining cells
        for(int i = 1; i <= f; i++){
            if(i == 1) dp[i] = 1;
            else{
                int mini = INT_MAX;
                for(int x = 1; x <= i; x++){
                    int v1 = x-1;      //brick breaks (x-1, b-1)   
                    int v2 = dp[i-x];  //brick survives (f-x, b)       
                    int val = max(v1, v2);
                    mini = min(mini, val);
                }
                dp[i] = mini+1;
            }
        }
    return dp[f];
    }
};


