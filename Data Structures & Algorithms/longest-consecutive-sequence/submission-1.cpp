class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!mp[nums[i]])
            {
                mp[nums[i]]=mp[nums[i]-1]+mp[nums[i]+1]+1;
                mp[nums[i]-mp[nums[i]-1]]=mp[nums[i]];
                mp[nums[i]+mp[nums[i]+1]]=mp[nums[i]];
                ans=max(ans,mp[nums[i]]);
            }
        }
        return ans;
    }
};
