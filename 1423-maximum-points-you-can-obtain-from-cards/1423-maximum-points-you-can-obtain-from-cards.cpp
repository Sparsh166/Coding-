class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        int maxsum = 0;
        int rind = n-1;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
            maxsum = max(maxsum,lsum);
        }

        for(int i = k-1; i>=0;i--){
            lsum -=cardPoints[i];
            rsum+=cardPoints[rind];
            maxsum = max(maxsum,rsum+lsum);
            rind--;

        }
        return maxsum;
    }
};