class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){return 0;}
        int profit =0;
        int buy = prices[0];
        for(int i=0;i<prices.size();i++){
            if(buy>prices[i]){
                buy=prices[i];
            }
            else{
            int earn = prices[i]-buy;
            profit = max(earn,profit);}
        }
        return profit;
    }
};