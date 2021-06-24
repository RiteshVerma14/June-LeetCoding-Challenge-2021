class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxAns = 0;
		for(int i = 0; i < grid.size(); ++i)
        {
			for(int j = 0; j<grid[i].size(); ++j) 
            {
				if(grid[i][j] == 1)
                {
                    int a=0;
                    mark(grid,i,j,a);
                    maxAns=max(maxAns,a);
                }    
            }
        }
		return maxAns;  
    }
    
    bool isSafe(int i,int j,int m,int n)
    {
        if(i < 0 || j < 0 || i>=m || j >= n) 
            return true;
        else 
            return false;
    }
    
    void mark(vector<vector<int>> &g, int &i, int &j, int &ans)
	{
		if(isSafe(i,j,g.size(),g[0].size()) || g[i][j]==0 || g[i][j] == 2) 
            return;
		g[i][j] = 2;
		++ans;
		mark(g,++i,j,ans);
        mark(g,--i,++j,ans);
        mark(g,--i,--j,ans);
        mark(g,++i,--j,ans);
        ++j;
	}
};
