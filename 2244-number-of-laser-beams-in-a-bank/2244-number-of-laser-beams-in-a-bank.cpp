class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int>laser;
        int ans = 0;
        for(int i=0;i<n;i++){
            int count = 0;
            for(auto it : bank[i]){
                if(it=='1'){
                    count++;
                }
            }
            if(count>0){
                laser.push_back(count);
            }
            
        }
        if(laser.size()<=1){
            return 0;
        }
        for(int i=0;i<laser.size()-1;i++){
            ans += laser[i]*laser[i+1];
        }
        return ans;
    }
};