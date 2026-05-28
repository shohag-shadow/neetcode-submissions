class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<pair<int,int>>st;
        vector<int>ans;
        int i=0,j=0;
        while(j<k)
        {
            st.insert({nums[j],j});
            j++;
        }
        while(j<nums.size())
        {
            ans.push_back((*st.rbegin()).first);
            st.erase({nums[i],i});
            st.insert({nums[j],j});
            i++;
            j++;
        }
        ans.push_back((*st.rbegin()).first);
        return ans;
    }
};
