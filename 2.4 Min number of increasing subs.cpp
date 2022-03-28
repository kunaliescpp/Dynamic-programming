/*
Problem Link: https://www.geeksforgeeks.org/minimum-number-of-increasing-subsequences/

Minimum number of increasing subsequences

Given an array of integers of size N, you have to divide it into the minimum number of “strictly increasing subsequences” 
For example: let the sequence be {1, 3, 2, 4}, then the answer would be 2. In this case, the first increasing sequence 
would be {1, 3, 4} and the second would be {2}.

Example 1:
Input : arr[] = {1 3 2 4} 
Output: 2 
There are two increasing subsequences {1, 3, 4} and {2}

Example 2: 
Input : arr[] = {4 3 2 1} 
Output : 4

Example 3: 
Input : arr[] = {1 2 3 4} 
Output : 1

Example 4:
Input : arr[] = {1 6 2 4 3} 
Output : 3
*/


//Binary search Solution -> nlogn 
int floor(vector<int>& tail, int number){

  int ans = -1;

  int start = 0;
  int end = tail.size()-1;
  while(start <= end){
     int mid = start + (end-start)/2;
     if(tail[mid] <= number){
        ans = end;
        end = mid-1;
     } else{
        start = mid+1;
     }
  }

  if(ans == -1) return end;
return ans;
}

int lengthOfLDS(vector<int>& nums){

  int n = nums.size();

  vector<int> tail;
  tail.push_back(nums[0]);
  int len = 1;
  for(int i = 1; i < n; i++){
     if(nums[i] < tail[len-1]){
        tail.push_back(nums[i]);
        len++;
        // cout << len;
     } else{
        int f = floor(tail, nums[i]);
        tail[f] = nums[i];
     }
  }

return len;
}


