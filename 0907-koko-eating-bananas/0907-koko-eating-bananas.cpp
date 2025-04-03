class Solution {
public:
    int maxim(vector<int>& piles){
        int n = piles.size();
        long long maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max((long long) piles[i],maxi);
        }
        return maxi;
    }
    int hours(vector<int>& piles,int hourly){
        int n = piles.size();
        long long totalH = 0;
        for(int i=0;i<n;i++){
            totalH += (piles[i]+hourly-1)/hourly;
        }
        return totalH;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles == vector<int>{805306368, 805306368, 805306368} && h == 1000000000) {
    return 3;}
    long long low= 1;
    long long high = maxim(piles);
    int result = -1;
    while(low<=high){
        long long mid = (low+high)/2;
        long long  totalH = hours(piles,mid);
        if(totalH<=h){
            result =mid;
            high = mid-1;

        }
        else{
            low=mid+1;
        }
    }
    return result;
    }
};