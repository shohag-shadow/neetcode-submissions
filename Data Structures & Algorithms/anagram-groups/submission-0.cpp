class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto u:strs)
        {
            string v=u;
            sort(v.begin(),v.end());
            mp[v].push_back(u);
        }
        vector<vector<string>>ans;
        for(auto u:mp)ans.push_back(u.second);
        return ans;
    }
};
