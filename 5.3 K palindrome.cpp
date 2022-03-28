/*
Problem Link: https://practice.geeksforgeeks.org/problems/k-palindrome/1

K-Palindrome 

A string is k palindrome if it can be transformed into a palindrome on removing at most k characters from it. 
Your task is to complete the function is_k_palin which takes two arguments a string str and a number N . 
Your function should return true if the string is k palindrome else it should return false.

Example:
Input: 2
abcdecba 1
acdcb  1
Output:
1
0
*/

// length of lcs
int longestCommonSubsequence(string text1, string text2) {
    
    int m = text1.size();
    int n = text2.size();
    
    int **dp = new int *[m+1];
    for(int i = 0; i < m+1; i++){
        dp[i] = new int [n+1];
    }
    
    //Fill 1st row
    for(int j = 0; j <= n; j++){
        dp[0][j] = 0;
    }
    
    //Fill 1st column
    for(int i = 1; i <= m; i++){                                
        dp[i][0] = 0;
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
          
          if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];     
          
          else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }     
    }
return dp[m][n];    
}

bool is_k_palin(string s,int k){

    int n = s.size();
    string temp = s;
    reverse(temp.begin(), temp.end());
    
    int len = longestCommonSubsequence(s, temp);
    
    if(n-len <= k) return true;
   
return false; 
}


