/*
Problem Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/max-non-overlapping-bridges-official/ojquestion

Maximum Non-overlapping Bridges

1. You are given a number n, representing the number of bridges on a river.
2. You are given n pair of numbers, representing the north bank and south bank co-ordinates of each bridge.
3. You are required to print the count of maximum number of non-overlapping bridges.


Constraints : 
0 <= n <= 20
0 <= n1n, n1s, n2n, n2s, .. <= 100

Sample Input : 
10
10 20
2 7
8 15
17 3
21 40
50 4
41 57
60 80
80 90
1 30

Sample Output : 
7
*/

#include
using namespace std;

class Bridge{
  public:
  int north;
  int south;

  Bridge(int north, int south){
  this->north = north;
  this->south = south;
  }
};

static bool mycmp(Bridge& a, Bridge& b){
  if(a.north == b.north){
    if(a.south <= b.south) return true;
    else return false;
  }

  else if(a.north < b.north) return true;

return false;
}

int maxBridges(vector& values, int n){

  vector lis(n, 1);

  sort(values.begin(), values.end(), mycmp);

  int maxi = lis[0];
  for(int i=1; i<n; i++){
      for(int j=0; j<i; j++){
         if(values[i].south > values[j].south) lis[i] = max(lis[i], 1 + lis[j]);
      }
  }
  maxi = max(maxi, lis[i]);
  }

return maxi;
}

int main(){

  int n;
  cin >> n;

  vector v;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    v.push_back(Bridge(a, b));
  }

  cout << maxBridges(v, n);

return 0;
}


