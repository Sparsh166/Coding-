class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     int n = fruits.size();
     map<int,int>mpp;
     int l = 0;
     int r = 0;
     int k = 2;
     int maxlen = 0;
     while(r<n){
        mpp[fruits[r]]++;
        if(mpp.size()>k){
            while(mpp.size()>k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
        }
        if(mpp.size()<=k){
            maxlen = max(maxlen, r-l+1);
        }
        r++;
     }   
     return maxlen;
    }
};