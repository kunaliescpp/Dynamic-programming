/*
Problem Link: https://practice.geeksforgeeks.org/problems/minimal-moves-to-form-a-string4331/1

Minimal moves to form a string 

Given a string S, check if it is possible to construct the given string S by performing any of the below operations any number 
of times. In each step, we can:

Add any character at the end of the string.
or, append the string to the string itself.
The above steps can be applied any number of times. The task is to find the minimum steps required to form the string.

Example 1:
Input: S = "aaaaaaaa"
Output: 4
Explanation: 
move 1: add 'a' to form "a"
move 2: add 'a' to form "aa"
move 3: append "aa" to form "aaaa"
move 4: append "aaaa" to form "aaaaaaaa"

Example 2:
Input: S = "abcabca"
Output: 5
Explanation: 
move 1: add 'a' to form "a"
move 2: add 'b' to form "ab"
move 3: add 'c' to form "abc"
move 4: append "abc" to form "abcabc"
move 5: add 'a' to form "abcabca"

Constraints:
1 ≤ |S| ≤ 10^3
*/

class Solution{
  public:	
	
	int minSteps(string s){
	    
	    int n = s.size();
	    vector<int> dp(n, INT_MAX);
	    
	    string s1 = "", s2 = "";
	    dp[0] = 1;
	    s1 += s[0];                       //s1 = a
        for(int i = 1; i < n; i++){
            
            s1 += s[i];                  // s1 = ab
            dp[i] = min(dp[i], dp[i-1]+1);
        
            s2 = s.substr(i+1, i+1);    // s2 = s(startidx = i+1 to length i+1)   s[i+1] -> s[2*i+1] 
            
            if(s1 == s2) dp[2*i + 1] = min(dp[i] + 1, dp[2*i + 1]);    //dp[3] =  min(dp[2), cp[3])
        }
        
    return dp[n-1];
	}
};


