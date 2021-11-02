/*
Problem Link: https://leetcode.com/problems/wildcard-matching/

Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial). 

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:
Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:
Input: s = "acdcb", p = "a*c?b"
Output: false


Constraints:
0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m = s.size(); 
        int n = p.size();
        
       bool dp[n+1][m+1];
        for(int i = n; i >= 0; i--){
            for(int j = m; j >= 0; j--){
                
                if(i == n && j == m) dp[i][j] = true;
                
                else if(i == n) dp[i][j] = false;
                
                else if(j == m){
                    if(p[i] == '*') dp[i][j] = dp[i+1][j];
                    else dp[i][j] = false;
                }
                
                else{
                    if(p[i] == '?') dp[i][j] = dp[i+1][j+1];
                    else if (p[i] == '*') dp[i][j] = (dp[i+1][j] || dp[i][j+1]);
                    else if(p[i] == s[j]) dp[i][j] = dp[i+1][j+1];
                    else dp[i][j] = false;    
                }
                
             } 
        }
    
     return dp[0][0];
    }
};


