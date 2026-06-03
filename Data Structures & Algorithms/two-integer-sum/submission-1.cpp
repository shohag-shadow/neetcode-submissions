class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         int i=0,j=nums.size()-1,sum;
         sort(nums.begin(),nums.end());
         while(i<j)
         {
            sum=nums[i]+nums[j];
            if(sum>target)
            {
                j--;
            }
            else if(sum<target)
            {
                i++;
            }
            else
            {
                return {i,j};
            }
         }

    }
};
