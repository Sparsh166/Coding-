class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive;
        vector<int> negative;
        for(int i =0 ;i<n;i++){
            if(nums[i]>0){
                positive.push_back(nums[i]);
            }
            else if(nums[i]<0){
                negative.push_back(nums[i]);
            }
        }

        vector<int>result;
        int left =0;
        int right =0;
        while(left<positive.size() && right<negative.size()){
         result.push_back(positive[left++]);
         result.push_back(negative[right++]);   
        }
        while(left<positive.size()){
            result.push_back(positive[left++]);
        }
        while(right<negative.size()){
            result.push_back(negative[right++]); 
        }
        return result;
    }
};