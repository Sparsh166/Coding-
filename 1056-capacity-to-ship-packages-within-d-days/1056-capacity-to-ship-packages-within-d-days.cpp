class Solution {
public:
    int maxim(vector<int>& weights){
        int n = weights.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(weights[i],maxi);
        }
        return maxi;
    }
    int summation(vector<int>& weights){
        int n = weights.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        return sum;
    }
    int tdays(vector<int>& weights, int capacity){
        int n = weights.size();
        int day = 1;
        int load = 0;
        for(int i=0; i<n; i++){
            if(load+weights[i]>capacity){
                day++;
                load = weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = maxim(weights);
        int high = summation(weights);
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            int day = tdays(weights,mid);
            if(day<=days){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};