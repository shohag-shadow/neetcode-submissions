class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char>innerboard[3][3];
        for(int i=0;i<9;i++)
        {
            set<char>row,col;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(row.count(board[i][j]))
                    {
                        return false;
                    }
                    row.insert(board[i][j]);
                    if(innerboard[i/3][j/3].count(board[i][j]))
                    {
                        return false;
                    }
                    innerboard[i/3][j/3].insert(board[i][j]);
                }
                if(board[j][i]!='.')
                {
                    if(col.count(board[j][i]))
                    {
                        return false;
                    }
                    col.insert(board[j][i]);
                }
            }
        }
        return true;
    }
};
