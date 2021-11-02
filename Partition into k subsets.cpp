/*
Problem Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/partition-into-subsets-official/ojquestion

Partition Into Subsets
1. You are given a number n, representing the number of elements.
2. You are given a number k, representing the number of subsets.
3. You are required to print the number of ways in which these elements can be partitioned in k non-empty subsets.

For n = 4 and k = 3 total ways is 6
12-3-4
1-23-4
13-2-4
14-2-3
1-24-3
1-2-34

Example:
Input: 4, 3
Output: 6


Constraints:
0 <= n <= 20
0 <= k <= n
*/

long partition(int n, int k){

  if(k == 0 || n == 0 || n < k) return 0;

  vector> dp(k+1, vector (n+1, 0));

  for(int i = 1; i <= k; i++){
    for(int j = 1; j <= n; j++){
      
       if(j < i) dp[i][j] = 0;
       else if (j == i) dp[i][j] = 1;
       else dp[i][j] = dp[i-1][j-1] + (dp[i][j-1] * i);
    }
  }

return dp[k][n];
}

int main(){

  int n, k;
  cin >> n;
  cin >> k;

  long res = partition(n, k);
  cout << res;
}


