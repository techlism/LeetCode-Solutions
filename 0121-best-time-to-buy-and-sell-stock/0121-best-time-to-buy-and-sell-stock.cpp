class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm = prices[0] ; // assumed that the stock is purchased on first day.
        int profit = 0 ;
        for(int i=1;i<prices.size();i++){
            // the current profit vs prev profit
            profit = max(prices[i] - minm, profit);
            minm = min(prices[i], minm); // update the buying price if lower price found            
        }
        return profit;
    }
};