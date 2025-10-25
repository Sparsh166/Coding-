class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int>ifac; 
        vector<int>jfac;
        for(int i =0;i<n;i++){
            ifac.push_back(values[i]+i);
            jfac.push_back(values[i]-i);
        }
        int candidate = values[0];
        int best_sol = values[0];
        int max_sum = INT_MIN;

        for(int i=1;i<n;i++){
            candidate = best_sol + jfac[i];
            best_sol = max(best_sol, ifac[i]);
            max_sum = max(candidate, max_sum);
        }
        return max_sum;
    }
};