/*
Problem Link: https://leetcode.com/problems/2-keys-keyboard/

2 Keys Keyboard

There is only one character 'A' on the screen of a notepad. You can perform two operations on this notepad for each step:
Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

Example 1:
Input: n = 3
Output: 3
Explanation: Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Example 2:
Input: n = 1
Output: 0
 

Constraints:
1 <= n <= 1000
*/

class Solution {
public:
    int minSteps(int n) {                         // n = 7                      
        
       int current = 1;                           // A _ _ _ _ _ _ 
       int cnt = 0;                               // if we simply copy and paste then A comes 8 times
       int copy = 0;                              // so to avoid this we made a buffer
        
        while(current < n){                      
            
            int rest =  n - current;
            if(rest % current == 0){              //if( 6 divides  by 1) then |copy & paste| i.e. paste the
               copy = current;                   //newly copied value
               current+= copy;                   // A A _ _ _ _ _   
               cnt+= 2;
            }
            
            
            else {                                  //else |only paste| i.e. paste the previous copied value
                current+= copy;                   // A A A ...
                cnt+= 1;
            }
        }   
    
    return cnt;
    }
};


