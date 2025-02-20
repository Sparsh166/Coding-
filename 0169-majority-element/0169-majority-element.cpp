class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int ans = 0;
     int n = nums.size();
     int el;
     int count =0;
     for (int i=0;i<nums.size();i++){
        if(count==0){
            count ++;
            el=nums[i];
        }
        else if(nums[i]==el){
            count++;
        }
        else{
            count --;
        }
     }
     int cnt =0;
     for(int i=0;i<nums.size();i++){
        if(nums[i]==el){
            cnt++;
        }
        if(cnt>n/2){
            ans = el;
        }
     }   
     return ans;
    }
};