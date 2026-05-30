class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size()*matrix[0].size()-1;
        int x=matrix[0].size();
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int i=m/x;
            int j=m%x;
            if(matrix[i][j]>target)
            {
                r=m-1;
            }
            else if(matrix[i][j]<target)
            {
                l=m+1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
