class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    int buyKaro = -prices[i] + next[0];
                    int skipKaro = next[1];
                    profit = max(buyKaro,skipKaro);
                }
                else{
                    int sellKaro=prices[i]+next[1];
                    int skipKaro = next[0];
                    profit = max(sellKaro,skipKaro);
                }
            curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};
