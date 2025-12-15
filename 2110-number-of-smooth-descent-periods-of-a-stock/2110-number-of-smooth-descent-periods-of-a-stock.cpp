class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long n = prices.size();
        long long ans = 1;
        long long cur = 1;
        for(int i=0;i<n-1;i++){
            if(prices[i]-prices[i+1]==1){
                cur++;
            }
            else{
                cur=1;
            }
            ans+=cur;
        }
        return ans;
    }
};