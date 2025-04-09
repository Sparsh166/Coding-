class Solution {
public:
    int maximum(vector<int>& weights){
        int n = weights.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,weights[i]);
        }
        return maxi;
    }

    int summation(vector<int>& weights){
        int n = weights.size();
        int suma = 0;
        for(int i=0;i<n;i++){
            suma+=weights[i];
        }
        return suma;
    }

    int capacity(vector<int>& weights,int weight, int days){
        int n = weights.size();
        int cnt=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+weights[i]>weight){
                cnt++;
                sum=0;
            }
            sum +=weights[i];
            
        }
        return cnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {
     int low = maximum(weights);
     int high = summation(weights);
     int ans =high;
     while(low<=high){
        int mid = (low+high)/2;
        int cnt = capacity(weights,mid,days);
        if(cnt<=days){
            ans =mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
     }
     return ans;   
    }
};