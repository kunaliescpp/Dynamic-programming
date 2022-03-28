/*
Prolem Link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

Fractional Knapsack 

Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value 
in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

Example 1:
Input: N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output: 240.00
Explanation:Total maximum value of item we can have is 240.00 from the given capacity of sack. 

Example 2:
Input: N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output: 160.00
Explanation: Total maximum value of item we can have is 160.00 from the given capacity of sack.


Constraints:
1 <= N <= 10^5
1 <= W <= 10^5
*/

//class implemented
/*
struct Item{
    int value;
    int weight;
}; */

class Solution{
    public:
    
    static bool mycmp(struct Item a, struct Item b){
        
        double r1 = (double)a.value/ a.weight;
        double r2 = (double)b.value/ b.weight;
        
        if(r1 > r2) return true;
    return false;
    }
    
    double fractionalKnapsack(int W, struct Item arr[], int n){
       
       sort(arr, arr+n, mycmp);
       
       double resVal = 0.0;
       for(int i = 0; i < n; i++){
           
           if(arr[i].weight <= W){
               resVal += arr[i].value;
               W -= arr[i].weight;
           } else {
               resVal +=  (double)W * ((double)arr[i].value / arr[i].weight);
               break;
           }
       }
    return resVal;   
    }
};


