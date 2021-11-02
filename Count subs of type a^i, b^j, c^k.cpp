/*
Problem Link: https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck4425/1

Count subsequences of type a^i, b^j, c^k 

Given a string S, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: 
1. Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.
2.  For large test cases, output value will be too large, return the answer MODULO 10^9+7

Example 1:
Input: S = "abbc"
Output: 3
Explanation: Subsequences are abc, abc and abbc.

Example 2:
Input: S = "abcabc"
Output: 7
Explanation: Subsequences are abc, abc, abbc, aabc abcc, abc and abc.


Constraints:
1 <= |S| <= 10^5
*/

class Solution{
  public:

    int fun(string &s) {
        
        int n = s.size(); int mod = 1e9 + 7;
        int a = 0; 
        int ab = 0;
        int abc = 0;
        for(int i = 0; i < n; i++){
            
            if(s[i] == 'a'){
                a = ((2*(a%mod))%mod+1)%mod;
            } else if(s[i] == 'b'){
                ab = ((2*(ab%mod))%mod+a%mod)%mod;
            } else if(s[i] == 'c'){
                abc = ((2*(abc%mod))%mod+ab%mod)%mod;
            }
        }
    
    return (int)abc % mod;
    }
};


