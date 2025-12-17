class Solution {
public:
    void helper(vector<int>& candidates, int target, int ind, vector<int> arr, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            arr.push_back(candidates[i]);
            helper(candidates,target-candidates[i],i+1,arr,ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>arr;
        vector<vector<int>>ans;
        helper(candidates,target,0,arr,ans);
        return ans;
    }

};