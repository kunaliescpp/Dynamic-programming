/*
Problem Link: https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

LCS of three strings 

Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

Example 1:
Input: A = "geeks", B = "geeksfor", C = "geeksforgeeks"
Output: 5
Explanation: "geeks"is the longest common subsequence with length 5.

Example 2:
Input: A = "abcd", B = "efgh", C = "ijkl"
Output: 0
Explanation: There's no common subsequence in all the strings.

Constraints:
1<=n1, n2, n3<=20
*/

int LCSof3 (string s1, string s2, string s3, int m, int n, int o){
        
        int dp[m+1][n+1][o+1];
 
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                for(int k=0; k<=o; k++){
        
                    if(i == 0 || j == 0|| k == 0) dp[i][j][k] = 0;
                    else if (s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;    
                    else  dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
                }
            }
        }
        
    return dp[m][n][o];
}


