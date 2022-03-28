/*
Problem Link: https://leetcode.com/problems/russian-doll-envelopes/

Russian Doll Envelopes

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's 
width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:
1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 10^4
*/


class Solution {
public:
    // Approach : (width => sorting, height => LIS)
    static bool comp(vector<int>& a, vector<int>& b){
        
        if(a[0] == b[0]){                                  //  [3, 7] [3, 4]
            if(a[1] > b[1]) return true;                   //  [3, 7] > [3, 4]
            else return false;                             //  [3, 7] < [3, 10] haiye he, nothing done in this case
        }
        
        if(a[0] < b[0]) return true;                      
        
    return false;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> dp(n);
        dp[0] = 1;
        int ans = 1;
        for(int i = 0; i < n; i++){
             dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
                    ans = max(ans, dp[i]);
        }
    
    return ans;
    }
};


