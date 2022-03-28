/*
Problem Link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

Minimum Score Triangulation of Polygon

You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where 
values[i] is the value of the ith vertex (i.e., clockwise order).
You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of 
the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles 
in the triangulation.
Return the smallest possible total score that you can achieve with some triangulation of the polygon.

Example 1:
Input: values = [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Example 2:
Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.

Example 3:
Input: values = [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
 

Constraints:
n == values.length
3 <= n <= 50
1 <= values[i] <= 100
*/

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
       
        int n = values.size();
        int **dp = new int *[n];
        for(int i = 0; i < n; i++){
             dp[i] = new int [n];
        }
       
        for(int g = 0; g < n; g++){
            int i = 0;
            for(int j = g; j < n; j++, i++){
                if(g==0) dp[i][j] = 0;
                else if(g==1) dp[i][j] = 0;
                else if(g==2) dp[i][j] = values[i]*values[i+1]*values[i+2];
                else{
                    int mini = INT_MAX;                                 // k loops b to e                             |
                    for(int k = i+1; k <= j-1; k++){                    // a b c d e f                                |   leftrem & rightrem is : ex-1st case
                     int trikata =  values[i]*values[j]*values[k];      //   - - - -                                  | remaining point in the <- of '|' side = 2
                     int leftrem = dp[i][k];                            // hm katege abf, acf, adf, aef from base "_" | remaining point in the -> of '\' side = 5
                     int rightrem = dp[k][j];                                            
                     int total = trikata + leftrem + rightrem;
                
                       mini = min(mini, total);
                    }                                                      
                       dp[i][j] = mini;
                }                                                             
              
            }
        }
     return dp[0][n-1];  
    }
};


