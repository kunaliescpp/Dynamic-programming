/*
Problem Link: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

Count Palindromic Subsequences 

Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) 
which could be formed from the string str.
Note: You have to return the answer module 109+7;
 
Example 1:
Input: 
Str = "abcd"
Output: 4
Explanation: palindromic subsequence are : "a" ,"b", "c" ,"d"
 
Example 2:
Input: Str = "aab"
Output: 4
Explanation: palindromic subsequence are :"a", "a", "b", "aa"


Constraints:
1<=length of string str <=1000
*/

class Solution{
    public:
    long long int  countPS(string s){
       
       //gap method
        int n = s.size();
        int mod = 1e9 + 7;
        
        vector<vector<int>>dp (n , vector<int> (n));
        
        for(int g = 0; g < n; g++){
             int i = 0;
            for(int j = g; j < n; i++,j++){
                if(g == 0) dp[i][j] = 1;
                else if(g == 1){
                    if(s[i] == s[j]) dp[i][j] = 3;
                    else  dp[i][j] = 2;
                }
                else {
                    if(s[i] == s[j])  dp[i][j] = (dp[i][j-1] + dp[i+1][j] + 1) % mod;
                    else dp[i][j] = ((dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]) % mod + mod) % mod;
                }
            
            }
       }
    return dp[0][n-1];
    }
};


