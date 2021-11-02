/*
Problem Link: https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1

Consecutive 1's not allowed 

Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. 
Output your answer modulo 10^9 + 7.

Example 1:
Input: N = 3
Output: 5
Explanation: 5 strings are (000, 001, 010, 100, 101).

Example 2:
Input: N = 2
Output: 3
Explanation: 3 strings are (00,01,10).


Constraints:
1 ≤ N ≤ 10^5
*/

class Solution{
  public:
	// ll =  long long
	ll countStrings(int n) {
	    
	    int oczeroes = 1, ocones = 1;
	    int mod = 1e9 + 7;
	    for(int i = 2; i <= n; i++){
	        
	        int nczeroes = (ocones + oczeroes)%mod;
	        int ncones = oczeroes;
	        
	        oczeroes = nczeroes;
	        ocones = ncones;
	    }
	
	return (ocones + oczeroes)%mod;
	}
};


