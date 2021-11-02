/*
Problem Link: https://leetcode.com/problems/largest-1-bordered-square/

Largest 1-Bordered Square

Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, 
or 0 if such a subgrid doesn't exist in the grid.

Example 1:
Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9

Example 2:
Input: grid = [[1,1,0,0]]
Output: 1
 

Constraints:
1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] is 0 or 1
*/


class Solution {
public:
	int largest1BorderedSquare(vector<vector<int>>& grid) {
		int r = grid.size(), c = grid[0].size();
		vector<vector<int>>hor(r, vector<int> (c, 0));
		vector<vector<int>>ver(r, vector<int> (c, 0));
        
        // filling horizontal matrix
        for(int i = 0; i < r; i++){                             // 1 2 3
            for(int j = 0; j < c; j++){                         // 1 1 2 
                if(j == 0){                                     // 1 2 3 
                    if(grid[i][j] == 1) hor[i][j] = 1;
                }else{
                    if(grid[i][j] == 1){
                        hor[i][j] = hor[i][j-1] + 1;
                    }
                }
            }
        }
        
	    // filling vertical matrix
        for(int j = 0; j < c; j++){                             // 1 1 1
            for(int i = 0; i < r; i++){                         // 2 1 2 
                if(i == 0){                                     // 3 2 3 
                    if(grid[i][j] == 1) ver[i][j] = 1;
                }else{
                    if(grid[i][j] == 1){
                        ver[i][j] = ver[i-1][j] + 1;
                    }
                }
            }
        }
	
        // check every cell of matrix
        int ans = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){    
                if(grid[i][j] == 0) continue;
                int end = min(i+1, j+1);                         // 1 1 1 
                while(end >= 1){                                 // 1 2 2
                                                                 // 1 2 3
                    bool ok1 = false, ok2 = false, ok3 = false, ok4 = false;
                    
                    if(hor[i][j] >= end) ok1 = true;
                    if(ver[i][j] >= end) ok2 = true;
                    if(hor[i+1-end][j] >= end) ok3 = true;
                    if(ver[i][j+1-end] >= end) ok4 = true;
                    
                    if(ok1 && ok2 && ok3 && ok4){
                        ans = max(ans, end);
                        break;
                    }
                    
                    end--;
                }
            }
        }
    return ans*ans;
    }
};


