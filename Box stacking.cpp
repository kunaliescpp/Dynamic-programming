/*
Problem Link: https://practice.geeksforgeeks.org/problems/box-stacking/1

Box Stacking 

You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. 
You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of 
another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D 
base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable 
to use multiple instances of the same type of box. You task is to complete the function maxHeight which returns 
the height of the highest possible stack so formed.
 
Note: Base of the lower box should be strictly larger than that of the new box we're going to place. This is in terms
of both length and width, not just in terms of area. So, two boxes with same base cannot be placed one over the other.

Example 1:
Input: n = 4
height[] = {4,1,4,10}
width[] = {6,2,5,12}
length[] = {7,3,6,32}
Output: 60
Explanation: One way of placing the boxes is as follows in the bottom to top manner:
(Denoting the boxes in (l, w, h) manner) (12, 32, 10) (10, 12, 32) (6, 7, 4)  (5, 6, 4) (4, 5, 6) (2, 3, 1) (1, 2, 3)
Hence, the total height of this stack is 10 + 32 + 4 + 4 + 6 + 1 + 3 = 60. No other combination of boxes produces a
height greater than this.

Example 2:
Input: n = 3
height[] = {1,4,3}
width[] = {2,5,4}
length[] = {3,6,1}
Output: 15
Explanation: One way of placing the boxes is as follows in the bottom to top manner:
(Denoting the boxes in (l, w, h) manner) (5, 6, 4) (4, 5, 6) (3, 4, 1), (2, 3, 1)  (1, 2, 3).
Hence, the total height of this stack is 4 + 6 + 1 + 1 + 3 = 15
No other combination of boxes produces a height greater than this.


Constraints:
1 <= N <= 100
1 <= l,w,h <= 100
*/


class Solution{
    public:
    //Base of the lower box should be strictly larger than that of the new box we're going 
    //to place. This is in terms of both length and width not just in terms of area 
    class Box{
       public:
       int length;
       int width;
       int height;
       
    //   Box(int x, int y, int z){
    //       length = x;
    //       width = y;
    //       height = z;
    //   }
    };
    
    static bool mycmp(Box &a, Box &b){
        
        if(a.length*a.width > b.length*b.width) return true;
        
    return false;
    }
    
    int lis(vector<Box> v, int len) {
        
        vector<int> dp(len);   // arr of height
        for(int i = 0; i < len; i++){
            dp[i] = v[i].height;
        }
        
        int maxi = 0;
        for(int i = 1; i < len; i++){
            for(int j = 0; j < i; j++){
               if((v[i].width < v[j].width) && (v[i].length < v[j].length)){
                   dp[i] = max(dp[i], v[i].height+dp[j]);
               }
            }
            maxi = max(maxi, dp[i]);  // max height
        }
    return maxi; 
    }
    
    int maxHeight(int height[],int width[],int length[],int n){
        
        vector<Box> v;
        Box box;
        for(int i = 0; i < n; i++){
            
            //intial dimensions
            box.height = height[i];
            box.length = max(length[i], width[i]);    //for comparing at the time of lis, we now make sure
            box.width = min(length[i], width[i]);     // that max should be compare with max && min should
                                                     // compare with min, for best result(maxHeight)
            v.push_back(box);
            
            //First rotation of box
            box.height = width[i];
            box.length = max(length[i], height[i]);
            box.width = min(length[i], height[i]);
            
            v.push_back(box);
            
            //Second rotation of box
            box.height = length[i];
            box.length = max(width[i], height[i]);
            box.width = min(width[i], height[i]);
            
            v.push_back(box);
        }
        
        sort(v.begin(), v.end(), mycmp); // sort Area in decreasing order
        int ans = lis(v, 3*n);            // lis on width && length
        
    return ans;
    }
};


