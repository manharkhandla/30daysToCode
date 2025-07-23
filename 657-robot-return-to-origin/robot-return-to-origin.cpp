class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int xAxis = 0;
        int yAxis = 0;
        for(int i=0;i<n;i++)
        {
            if(moves[i]=='U') xAxis += 1;
            else if(moves[i]=='D') xAxis -= 1;
            else if(moves[i]=='R') yAxis += 2;
            else yAxis -= 2;
        }

        if(xAxis==0 && yAxis==0) return true;
        else return false;
    }
};