class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int>mp;
         for(auto u:nums)mp[u]++;
         vector<pair<int,int>>v;
         for(auto u:mp)v.push_back({u.second,u.first});
         sort(v.begin(),v.end(),greater<pair<int,int>>());
        vector<int>ans;
        for(int i=0;i<k;i++)ans.push_back(v[i].second);
        return ans;
    }
};
