class Solution {
public:
    void helper(string digits, int ind, string arr, vector<string>&ans,unordered_map<char,string>&mp){
        if(ind==digits.length()){
            ans.push_back(arr);
            return;
        }
        char ch = digits[ind];
        string str = mp[ch];
        for(int i=0; i<str.size();i++){
            arr.push_back(str[i]);
            helper(digits, ind+1, arr,ans,mp);
            arr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        string arr = "";
        vector<string>ans;
    
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        helper(digits,0,arr,ans,mp);
        return ans;
    }
};