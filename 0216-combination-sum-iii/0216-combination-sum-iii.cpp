class Solution {
public:
    void helper(int k, int n, int ind, int sum, vector<int>arr, vector<vector<int>>&ans){
        if(sum==n && arr.size()==k){
            ans.push_back(arr);
            return;
        }
        if(sum>n || arr.size()>k){
            return;
        }
        
        for(int i = ind;i<=9;i++){
            if(i+sum<=n){
                arr.push_back(i);
                helper(k,n,i+1,sum+i,arr,ans);
                arr.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        vector<vector<int>>ans;
        int sum = 0;
        helper(k,n,1,sum,arr,ans);
        return ans;
    }
};