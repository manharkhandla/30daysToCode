class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        int n = piles.size();
        for(int i=0;i<n;i++) pq.push(piles[i]);
        int ans = 0;
        
        for(int i=0;i<k;i++)
        {
            int maxStone = pq.top();
            pq.pop();
            pq.push(maxStone-(maxStone/2));
        }

        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};