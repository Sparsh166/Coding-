class Solution {
public:
    bool ispalindrome(string s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void helper(string s, int ind, vector<string>arr, vector<vector<string>>&ans){
        if(ind == s.length()){
            ans.push_back(arr);
            return;
        }
        for(int i=ind;i<s.length();i++){
            if (ispalindrome(s,ind,i)){
                arr.push_back(s.substr(ind,i-ind+1));
                helper(s,i+1,arr,ans);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>arr;
        vector<vector<string>>ans;
        helper(s,0,arr,ans);
        return ans;
    }
};