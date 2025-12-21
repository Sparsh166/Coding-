class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int>mp;
        for(int i=0;i<paths.size();i++){
            string source = paths[i][0];

            mp[source] = 1;
        }
        for(int i=0;i<paths.size();i++){
            string dest = paths[i][1];

            if(mp[dest]!=1){
                return dest;
            }
        }
        return "";
    }
};