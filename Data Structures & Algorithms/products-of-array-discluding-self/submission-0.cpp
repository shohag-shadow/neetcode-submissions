class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefmul;
        int mul=1;
        for(auto u:nums)
        {
            mul*=u;
            prefmul.push_back(mul);
        }
        vector<int>postmul(nums.size());
        mul=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            mul*=nums[i];
            postmul[i]=mul;
        }
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=1;
            if(i!=0)ans[i]*=prefmul[i-1];
            if(i!=nums.size()-1)ans[i]*=postmul[i+1];
        }
        return ans;
    }
};
