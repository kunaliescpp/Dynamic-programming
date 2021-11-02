/*
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell 
one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
Input: prices = [1]
Output: 0
 

Constraints:
1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int obsp = -prices[0];
        int ossp = 0;
        int ocsp = 0;
        
        for(int i = 1; i < n; i++){
            
            int nbsp = 0;
            int nssp = 0;
            int ncsp = 0;
            if(ocsp - prices[i] > obsp) nbsp = ocsp - prices[i];
            else nbsp = obsp;
            
            if(obsp + prices[i] > ossp) nssp = prices[i] + obsp;
            else nssp = ossp;
            
            if(ossp > ocsp) ncsp = ossp;
            else ncsp = ocsp;
    
            obsp = nbsp;
            ossp = nssp;
            ocsp = ncsp;
        }
       return ossp;
    }
};


