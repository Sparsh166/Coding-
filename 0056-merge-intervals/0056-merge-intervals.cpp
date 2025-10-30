class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> temp;
        sort(intervals.begin(), intervals.end());
        temp.push_back(intervals[0]);
        for(int i = 1;i<n;i++){
            if(temp.back()[1] >= intervals[i][0]){
                temp.back()[1] = max(temp.back()[1],intervals[i][1]);
            }
            else{
                temp.push_back(intervals[i]);
            }
        }
        return temp;
    }
};