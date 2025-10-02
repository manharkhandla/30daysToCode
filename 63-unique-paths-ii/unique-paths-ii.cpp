class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> t(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1) return 0;
        t[0][0] = 1;

        bool foundRow1 = false;
        bool foundCol1 = false;

        
        for (int col = 1; col < n; col++) 
        {
            if (obstacleGrid[0][col] == 1) foundRow1 = true;
            if (foundRow1) t[0][col] = 0;
            else t[0][col] = 1;
        }

        
        for (int row = 1; row < m; row++) 
        {
            if (obstacleGrid[row][0] == 1) foundCol1 = true;
            if (foundCol1) t[row][0] = 0;
            else t[row][0] = 1;
        }

        
        for (int i = 1; i < m; i++) 
        {
            for (int j = 1; j < n; j++) 
            {
                if (obstacleGrid[i][j] == 1) t[i][j] = 0;
                else t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }

        return t[m-1][n-1];
    }
};
