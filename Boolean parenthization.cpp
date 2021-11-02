/*
Problem Link: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

Boolean Parenthesization 

Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Example 1:
Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates to true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

Example 2:
Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the only ways.


Constraints:
1 ≤ N ≤ 200 
*/

class Solution{
public:
    int countWays(int N, string s){
        
        string str1, str2;
        for(int i = 0; i < N; i++){
            if(s[i] == 'T' || s[i] == 'F') str1 += s[i];
            else str2 += s[i];
        }
        
        int n = str1.size();
        vector< vector<int>> dpt(n, vector<int> (n));
        vector< vector<int>> dpf(n, vector<int> (n));
        for(int g = 0; g < n; g++){
            int i = 0;
            for(int j = g; j < n; j++){
                
                if(g == 0){
                    if(str1[i] == 'T'){
                        dpt[i][j] = 1;
                        dpf[i][j] = 0;
                    } else {
                        dpt[i][j] = 0;
                        dpf[i][j] = 1;
                    }
                }
            
                else{
                    for(int k = i; k < j; k++){
                    
                        int opr = str2[k];
                        
                        int ltc = dpt[i][k];
                        int rtc = dpt[k+1][j];
                        int lfc = dpf[i][k];
                        int rfc = dpf[k+1][j];
                        
                        if(opr == '&'){
                            dpt[i][j] += (ltc*rtc)% 1003;
                            dpf[i][j] += (lfc*rfc + ltc*rfc + rtc*lfc)% 1003;
                        }
                        else if(opr == '|'){
                            dpt[i][j] += (ltc*rtc + ltc*rfc + lfc*rtc)% 1003;
                            dpf[i][j] += (lfc*rfc)% 1003;
                        }
                        else {                                      //if(s[i] == '^')
                            dpt[i][j] += (ltc*rfc + lfc*rtc)% 1003;
                            dpf[i][j] += (lfc*rfc + ltc*rtc)% 1003;
                        }
                    }
                } // ends, if(gap > 0)
            
                i++;
            }
        }
   
    return (dpt[0][n-1])%1003;
    }
};


