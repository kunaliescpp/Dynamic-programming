/*
Problem Link: https://practice.geeksforgeeks.org/problems/temple-offerings2831/1

Temple Offerings 

Consider a devotee wishing to give offerings to temples along a mountain range. The temples are located in a row at different heights. 
Devotee is very religious and wants to offer each temple at least one offering. If two adjacent temples are at different altitudes, 
then the temple that is higher up should receive more offerings than the one that is at lower altitude. If two adjacent temples are at 
the same height, then their offerings relative to each other does not matter. The height of the N temples are given in the array arr[]. 
Find the minimum number of offerings required.

Example 1:
Input: N = 3
arr = {1, 2, 2}
Output: 4
Explaination: Bring 1 offering each for first and third temple and 2 offerings for the second temple.
 
Example 2:
Input: N = 6
arr = {1, 4, 3, 6, 2, 1}
Output: 10
Explaination: 1 offering each for 1st, 3rd and 6th temple, 
2 offerings each for 2nd and 5th temple and 3 offerings for the 4th temple.
 
 
Constraints:
1 ≤ N ≤ 10^4
1 ≤ arr[i] ≤ 1000
*/

class Solution{
public:
    int offerings(int n, int arr[]){
        
        int larr[n];
        larr[0] = 1;
        for(int i = 1; i < n; i++){
            if(arr[i-1] < arr[i]) larr[i] = larr[i-1] + 1;
            else larr[i] = 1;
        }
    
        int rarr[n];
        rarr[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            if(arr[i] > arr[i+1]) rarr[i] = rarr[i+1] + 1;
            else rarr[i] = 1;
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += max(larr[i], rarr[i]);
        }
    
    return sum;   
    }
};


