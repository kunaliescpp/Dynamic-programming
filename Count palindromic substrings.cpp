/*
Problem Link: https://leetcode.com/problems/palindromic-substrings/

Palindromic Substrings

Given a string s, return the number of palindromic substrings in it. A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
*/

class Solution {
public:
    int countSubstrings(string s) {
        
        //gap method
        int n = s.size();
        int cnt = 0;
        
        vector<vector<int>>dp (n , vector<int> (n));
        
        for(int g = 0; g < n; g++){
             int i = 0;
            for(int j = g; j < n; i++,j++){
                if(g == 0) dp[i][j] = 1;
                else if(g == 1){
                    if(s[i] == s[j]) dp[i][j] = 1;
                    else  dp[i][j] = 0;
                }
                else {
                    if(s[i] == s[j] && dp[i+1][j-1] == 1)  dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
            
            if(dp[i][j] == 1) cnt++;
            }
       }
    return cnt;
    }
};


