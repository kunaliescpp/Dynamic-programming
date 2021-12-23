/*
Problem Link: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

Maximum Sum of 3 Non-Overlapping Subarrays

Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, 
return the lexicographically smallest one.

Example 1:
Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5]. We could have also taken [2, 1], but an 
answer of [1, 3, 5] would be lexicographically larger.

Example 2:
Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]
 
Constraints:
1 <= nums.length <= 2 * 104
1 <= nums[i] < 216
1 <= k <= floor(nums.length / 3)
*/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> v;
        vector<int> left(n);
        vector<int> right(n);
        
        // prefix sum for future use
        vector<int> psum(n);
        for(int i = 0; i < n; i++){
            
            if(i == 0) psum[i] = nums[0];
            else psum[i] = psum[i-1] + nums[i];
        }
    
        // left subarray
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(i < k){
                sum += nums[i];
                left[i] = sum;
            } else {
               sum += nums[i] - nums[i-k];
               left[i] = max(left[i-1], sum);
            }
        }
    
        // right subarray
        sum = 0;
        for(int i = n-1; i >= 0; i--){
            if(i + k >= n){
                sum += nums[i];
                right[i] = sum;
            } else {
                sum += nums[i] - nums[i+k];
                right[i] = max(right[i+1], sum);
            }
        }
        
        // middle subarray
        int lsum = 0;
        int spmsa = -1;                     //spmsa = start pt. of middle subarray
        int rsum = 0;
        int maxi = 0;
        for(int i = k; i <= n-(2*k); i++){
            if(left[i-1] + right[i+k] + (psum[i+k-1]-psum[i-1]) > maxi){
                maxi = left[i-1] + right[i+k] + (psum[i+k-1]-psum[i-1]);
                lsum = left[i-1];
                rsum = right[i+k];
                spmsa = i;
            } 
        }
        
        //start pt. of left subarray
        for(int i = k-1; i < spmsa; i++){
            if(psum[i] - (i-k < 0 ? 0 : psum[i-k]) == lsum){
                v.push_back(i-k+1);
                break;
            }
        }
        
        v.push_back(spmsa);
        
        //starting pt. of right subarray
        for(int i = spmsa+(2*k)-1; i < n; i++){
            if(psum[i] - psum[i-k] == rsum){
                v.push_back(i-k+1);
                break;
            }
        }
        
    return v;
    }
};


