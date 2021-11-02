/*
Problem Link: https://www.lintcode.com/problem/514/

Paint Fence

There is a fence with n posts, each post can be painted with one of the k colors. You have to paint all the posts such that 
no more than two adjacent fence posts have the same color. 
Return the total number of ways you can paint the fence.

n and k are non-negative integers.

Example 1:
Input: n=3, k=2  
Output: 6
Explanation:
          post 1,   post 2, post 3
    way1    0         0       1 
    way2    0         1       0
    way3    0         1       1
    way4    1         0       0
    way5    1         0       1
    way6    1         1       0
    
Example 2:
Input: n=2, k=2  
Output: 4
Explanation:
          post 1,   post 2
    way1    0         0       
    way2    0         1            
    way3    1         0          
    way4    1         1       
*/


class Solution {
public:
    //no more than two adjacent fence posts have the same color , 1 0 0 1 0 0 with k = 2 is valid case
    int numWays(int n, int k) {
         
        if(n == 1) return k;

        int same = k * 1;                        // last 2 colours are same
        int diff = k * (k-1);                    // last 2 colours are diff
        int total = same + diff;                 // total of both (same + diff)
        
        for(int i = 3; i <= n; i++){                              
            same = diff * 1;                   
            diff = total * (k-1);
            total = same + diff;
        }
    
    return total;
    }
};


