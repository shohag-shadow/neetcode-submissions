class Solution {
public:
    struct node{
        node* link[27]={NULL};
        bool isend=false;
        bool istaken=false;
    };
    node *root=new node();
    void add(string &s)
    {
        node *ptr=root;
        for(int i=0;i<s.size();i++)
        {
            if(ptr->link[s[i]-'a']==NULL)ptr->link[s[i]-'a']=new node();
            ptr=ptr->link[s[i]-'a'];
        }
        ptr->isend=true;
    }
    vector<string>ans;
    int n,m;
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<bool>>&vis,node* ptr,string &s)
    {
        if(i<0||j<0||i>=n||j>=m)return ;
        if(vis[i][j])return ;
        vis[i][j]=true;
        char c=board[i][j];
        if(ptr->link[c-'a']==NULL)
        {
            vis[i][j]=false;
            return ;
        }
        s+=c;
        ptr=ptr->link[c-'a'];
        if(ptr->isend==true&&ptr->istaken==false)
        {
            ptr->istaken=true;
            ans.push_back(s);
        }
        dfs(i+1,j,board,vis,ptr,s);
        dfs(i-1,j,board,vis,ptr,s);
        dfs(i,j+1,board,vis,ptr,s);
        dfs(i,j-1,board,vis,ptr,s);
        vis[i][j]=false;
        s.pop_back();
        return ;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto &s:words)add(s);
        n=board.size();
        m=board[0].size();
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size()));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                string s;
                dfs(i,j,board,visited,root,s);
            }
        }
        return ans;
    }
};
