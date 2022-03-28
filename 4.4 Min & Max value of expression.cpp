/*
Problem Link: https://www.geeksforgeeks.org/minimum-maximum-values-expression/

Minimum and Maximum values of an expression with * and +

Given an expression which contains numbers and two operators ‘+’ and ‘*’, we need to find maximum and minimum value which can be
obtained by evaluating this expression by different parenthesization. 

Example 1: 
Input  : expr = “1+2*3+4*5” 
Output : Minimum Value = 27, Maximum Value = 105 
Explanation:
Minimum evaluated value = 1 + (2*3) + (4*5) = 27
Maximum evaluated value = (1 + 2)*(3 + 4)*5 = 105
*/
 
void printMinAndMaxValueOfExp(string exp) {

  vector<int> num;
  vector<char> opr;
  for (int i = 0; i < exp.size(); i++){
      if (exp[i] == '+' || exp[i] == '*'){
      opr.push_back(exp[i]);
      } else {
      num.push_back(exp[i] - '0');
      }
  }

  int n = num.size();
  vector<vector<int>> minVal(n, vector(n, INT_MAX));
  vector<vector<int>> maxVal(n, vector(n, INT_MIN));
  for (int g = 0; g < n; g++){
    int i = 0;
    for (int j = g; j < n; j++){
      if(i == j){
        minVal[i][j] = min(num[i]-'0', minVal[i][j]);
        maxVal[i][j] = max(num[i]-'0', maxVal[i][j]);
      } else{
        for(int k = i; k < j; k++){
            if (opr[k] == '+') {
              minVal[i][j] = min(minVal[i][j], minVal[i][k]+minVal[k + 1][j]);
              maxVal[i][j] = max(maxVal[i][j], maxVal[i][k]+maxVal[k + 1][j]);
            } else{ //if (opr[k] == '*')
              minVal[i][j] = min(minVal[i][j], minVal[i][k]*minVal[k + 1][j]);
              maxVal[i][j] = max(maxVal[i][j], maxVal[i][k]*maxVal[k + 1][j]);
            }
        } // for loop ends
      }
    }
  i++;
  }

  cout << "Minimum value -> " << minVal[0][n - 1] << endl;
  cout << "Maximum value -> " << maxVal[0][n - 1];
}


