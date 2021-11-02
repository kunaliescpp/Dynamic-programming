/*
Problem Link: leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

Best Time to Buy and Sell Stock with transaction fee (infinite transactions allowed)

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing 
a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction
fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:
1 <= prices.length <= 5 * 10^4
1 <= prices[i] < 5 * 10^4
0 <= fee < 5 * 10^4
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        //loan leke stock kharidenge par hmpe loan ke sath 1 stock hoga...
        //2nd din tabhi bekunga jab 2nd din stock bek ke ,3rd day stock mje me khareeed saku
        
        int obsp = -prices[0];                               // old brought stock price
        int ossp = 0;                                        // old sell stock price
        for(int i = 1; i < n; i++){
           
            int nbsp = 0;                                    //new brought stock price
            int nssp = 0;                                    //new sell stock price
            
            if(ossp - prices[i] > obsp){
                nbsp = ossp - prices[i];
            } else {
               nbsp = obsp;
            }
           
            if(obsp + prices[i] - fee > ossp){
                nssp = obsp + prices[i] - fee;
            } else {
                nssp = ossp;
            }
    
            obsp = nbsp;
            ossp = nssp;
        }  
     
     return ossp;
    }
};


