/*
Problem Link: https://leetcode.com/problems/longest-palindromic-subsequence/

Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing 
the order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        int dp[n][n];
        
        int cnt = 0;
        //gap method
        for(int g = 0; g < n; g++){
            int row = 0;
            for(int col = g; col < n; col++,row++){
            if(g == 0) dp[row][col] = 1;
             else if (g==1) dp[row][col] = (s[row] == s[col]) ? 2: 1;

             else dp[row][col] = (s[row] == s[col]) ? 2 + dp[row+1][col-1] : max(dp[row+1][col], dp[row][col-1]);

            }
        }
    return dp[0][n-1];
    }
};


