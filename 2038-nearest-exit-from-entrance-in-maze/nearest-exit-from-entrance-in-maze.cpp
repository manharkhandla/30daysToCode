class Solution {
public:

    vector<vector<int>> dir{{0,1}, {0,-1}, {1,0}, {-1,0}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        while(!q.empty())
        {
            int N = q.size();

            while(N--)
            {
                int currRow = q.front().first;
                int currCol = q.front().second;
                q.pop();

                if((make_pair(currRow,currCol) != make_pair(entrance[0],entrance[1])) && (currRow==0 || currRow==m-1 || currCol==n-1 || currCol==0))
                {
                    return steps;
                }

                for(auto &d : dir)
                {
                    int new_r = currRow + d[0];
                    int new_c = currCol + d[1];

                    if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && maze[new_r][new_c]!='+')
                    {
                        q.push(make_pair(new_r,new_c));
                        maze[new_r][new_c] = '+';
                    }
                }

            }
            steps++;
        }

        return -1;
    }
};