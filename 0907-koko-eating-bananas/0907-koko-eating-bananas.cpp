class Solution {
public:
    int maxim(vector<int>& piles){
        int n = piles.size();
        long long maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max((long long)piles[i], maxi);
        }
        return maxi;
    } // <-- missing brace added here

    int totalhours(vector<int>& piles, int hourly){
        long long totalh = 0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            totalh += (piles[i]+hourly-1)/hourly;
        }
        return totalh;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = maxim(piles);
        int result = -1;
        while(low <= high){
            long long mid = (low + high)/2;
            long long totalh = totalhours(piles, mid);
            if(totalh <= h){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return result;
    }
};
