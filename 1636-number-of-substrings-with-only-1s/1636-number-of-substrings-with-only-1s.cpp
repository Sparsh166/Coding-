class Solution {
public:
    int numSub(string s) {
        long long count =0;
        long long ans = 0;
        long long mod = 1e9+7;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count++;
            }
            else{
                ans+= ((count*(count+1))/2)%mod;
                count=0;
            }
        }
        ans+= ((count*(count+1))/2)%mod;
        return ans;
    }
};