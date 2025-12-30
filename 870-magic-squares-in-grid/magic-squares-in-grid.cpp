class Solution {
public:

    bool solve(vector<vector<int>>& grid,int r,int c)
    {
        int totalSum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        unordered_set<int> seen;

        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (grid[r+i][c+j]>9 || grid[r+i][c+j]<1 ||  seen.count(grid[r+i][c+j])) return 0;     
                else seen.insert(grid[r+i][c+j]);
            }           
        }

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if((grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2])!=totalSum) return 0;

                if((grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i])!=totalSum) return 0;
            }
        }

        int d1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        if(d1 != totalSum) return 0;

        int d2 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];
        if(d2 != totalSum) return 0;

        return 1;
    }


    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        for(int i=0;i<=row-3;i++)
        {
            for(int j=0;j<=col-3;j++)
            {
                if(solve(grid,i,j)) ans++;
            }
        }

        return ans;

    }
};