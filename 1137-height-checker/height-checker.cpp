class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count[101] = {0};
        int n = heights.size();
        for(int i = 0; i < n; ++i) ++count[heights[i]];
        int res = 0, idx = 0;
        for (int h = 1; h <= 100; ++h) {
            while (count[h]-- > 0) {
                if (heights[idx++] != h) ++res;
            }
        }
        return res;
    }
};