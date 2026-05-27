class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<pair<int,int>>indexed_nums;
         for(int i=0;i<nums.size();i++)indexed_nums.push_back({nums[i],i});
         sort(indexed_nums.begin(),indexed_nums.end());
         int i=0,j=nums.size()-1;
         while(i<j)
         {
            int s=indexed_nums[i].first+indexed_nums[j].first;
            if(s>target)j--;
            else if(s<target)i++;
            else if(indexed_nums[i].second<indexed_nums[j].second) return {indexed_nums[i].second,indexed_nums[j].second};
            else return {indexed_nums[j].second,indexed_nums[i].second};
         }

    }
};
