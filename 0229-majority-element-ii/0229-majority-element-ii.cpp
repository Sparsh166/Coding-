class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 =0;
        int cnt2 = 0;
        int el1;
        int el2;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(cnt1==0&& nums[i]!=el2){
                cnt1++;
                el1=nums[i];
            }
            else if(cnt2==0&& nums[i]!=el1){
                cnt2++;
                el2=nums[i];
            }
            else if(el1==nums[i]){
                cnt1++;
            }
            else if(el2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--,cnt2--;
            }
        }
        vector<int>ls;
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
                count1++;
            }
            else if(nums[i]==el2){
                count2++;
            }
        }
        int mini = (int)(n/3)+1;
        if(count1>=mini){
            ls.push_back(el1);
        }
        if(count2>=mini){
            ls.push_back(el2);
        }
        sort(ls.begin(),ls.end());
        return ls;
    }
};