class Solution {
public:
    int maximum(vector<int>& bloomDay){
        int n = bloomDay.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(bloomDay[i],maxi);
        }
        return maxi;
    }
    int minimum(vector<int>& bloomDay){
        int n = bloomDay.size();
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(bloomDay[i],mini);
        }
        return mini;
    }
    int possible(vector<int>& bloomDay, int days , int m, int k){
        int n = bloomDay.size();
        int cnt=0;
        int numberofb =0;
        for(int i=0;i<n;i++){
            if(days>=bloomDay[i]){
                cnt++;
            }
            else{
                numberofb+= cnt/k;
                cnt=0;
            }
        }
        numberofb+=cnt/k;
        return numberofb;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size();
        if(val>n){return -1;}
        int low = minimum(bloomDay);
        int high = maximum(bloomDay);
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay, mid, m, k)>=m){
                high=mid-1;
            }
            else{low=mid+1;}
        }
        return low;
    }
};