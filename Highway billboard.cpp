/*
Problem Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/highway-billboard-official/ojquestion

Highway Billboard

1. You are given a number M representing length of highway(range).
2. You are given a number N representing number of bill boards.
3. You are given N space separated numbers representing (P)position of bill-boards.
4. You are given N space separated numbers representing (R)revenue corresponding to each (P)position.
5. You are given a number T such that bill-boards can only be placed after specific distance(T).
6. Find the maximum revenue that can be generated.

Input Format: 
A number M(length of highway)
A number N(number of bill boards)
P1 ,P2 ,P3 ,P4 ,P5 .... Pn (placement of N bill-boards)
R1 ,R2 ,R3 ,R4 ,R5 .... Rn (revenue from each bill-board)
A number T (neccessary distance b/w two bill-board)

Output Format:
Find the maximum revenue that can be generated.

Example 1:
Input: 
20
5
6 7 12 14 15
5 8 5 3 1
5

Output: 11

Constraints
1 <= M <= 100000
1 <= N <= 50000
1 <= Pi <= M
1 <= Ri <= 100
1 <= T
*/

#include <bits/stdc++.h>
using namespace std;

int maxRevenue(int m, vector x, vector rev, int n, int t){

  unordered_map<int, int>mp;
  for(int i = 0; i < n; i++){
    mp[x[i]] = rev[i];
  }

  vector dp(m+1);
  dp[0] = 0;
  for(int i = 1; i <= m; i++){
    if(mp.count(i) == 1){
      int boardInstalled = dp[i-1];
      int boardnotInstalled = mp[i] + ((i-(t+1) >= 0) ? dp[i-(t+1)] : 0);
      dp[i] = max(boardInstalled, boardnotInstalled);
    } else{
       dp[i] = dp[i-1];
    }
  }
  
return dp[m];
}

int main(){

  int m;
  cin >> m; //miles of road

  int n;
  cin >> n; // no of billboards
  
  vector x(n);
  vector rev(n);
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }

  for(int i = 0; i < n; i++){
    cin >> rev[i];
  }

  int t;
  cin >> t;
  cout << maxRevenue(m, x, rev, n, t);
return 0;
}


