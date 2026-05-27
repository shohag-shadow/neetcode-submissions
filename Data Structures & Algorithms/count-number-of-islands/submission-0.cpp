class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis)
    {
        if(i<0||j<0||i>=n||j>=m||vis[i][j]||grid[i][j]=='0')
        {
            return ;
        }
        vis[i][j]=1;
        dfs(i-1,j,grid,vis);
        dfs(i+1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i,j-1,grid,vis);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'&&vis[i][j]==0)
                {
                    ans++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};
