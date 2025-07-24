class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        int stSize = stones.size();
        int jSize = jewels.size();
        int cnt = 0;

        for(int i=0;i<jSize;i++)
        {
            for(int j=0;j<stSize;j++)
            {
                if(jewels[i]==stones[j]) cnt++;
            }
        }

        return cnt;
    }
};