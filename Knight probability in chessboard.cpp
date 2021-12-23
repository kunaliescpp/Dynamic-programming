/*
Problem Link: https://leetcode.com/problems/knight-probability-in-chessboard/

Knight Probability in Chessboard

On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. 
The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, 
then one cell in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off 
the chessboard) and moves there.
The knight continues moving until it has made exactly k moves or has moved off the chessboard.
Return the probability that the knight remains on the board after it has stopped moving.

Example 1:
Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board. From each of those positions, there are 
also two moves that will keep the knight on the board. The total probability the knight stays on the board is 0.0625.


Constraints:
1 <= n <= 25
0 <= k <= 100
0 <= row, column <= n
*/

class Solution {
public:
    static bool isInside(int ni, int nj, int n){            //dhai chaal ke bad ghoda chess me he ya nhi
        
        if( ni >= 0 && nj >= 0 && nj <= n-1 && ni <= n-1){
            return true;
        }
        return false;
    }
    
    
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<double>>curr (n, vector<double> (n));
        vector<vector<double>>next (n, vector<double> (n));            
        curr[row][column] = 1;
        
         vector<vector<int>> graph = {{2,1}, {-2, 1}, {1, 2}, {-1, 2}, {1, -2}, {-2, -1}, {-1,-2}, {2, -1}};
        
        for(int m = 1; m <= k; m++){                           //m = moves
            //check probility
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(curr[i][j] != 0){
                       
                       int ni = 0;
                       int nj = 0;
                       
                        for(vector<int> p: graph){
                            int ni = i + p[0];
                            int nj = j + p[1];
              
                            if(isInside(ni, nj, n)) next[ni][nj]+= curr[i][j]/8.0;
                        }  
                    }
                }   
            }
          
            //curr = next;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    curr[i][j] = next[i][j];
                    next[i][j] = 0.0;
                }
            }  
        }
       
        //sum all the element in curr
         double sum = 0;
         for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
              sum+= curr[i][j];
            }
         }
    return sum;
    }
};


