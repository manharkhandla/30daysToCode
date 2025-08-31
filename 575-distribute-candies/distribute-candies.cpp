class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int ans = 0;
        int lastEatCandy = -10001;
        int totalEatedCandy = 0;

        sort(candyType.begin(),candyType.end());

        for(int i=0;i<n;i++)
        {
            if(totalEatedCandy >= n/2) return ans;
            if(candyType[i]==lastEatCandy) continue;
            else
            {
                ans++;
                totalEatedCandy++;
                lastEatCandy = candyType[i];
            }
        }

        return ans;
    }
};