class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(n==1){return true;}
        if(bits[n-2]==0){return true;}
        int left = 0;
        int right = 1;
        while(left<n && right<=n){
            if((bits[left]==1 && bits[right] == 1) or (bits[left]==1 && bits[right] ==0)){
                left = left+2;
                right = right+2;
                if(left>=n&&right>=n){return false;}
            }
            else{
                left++;
                right++;
            }
        
        }
        return true;

    }
};