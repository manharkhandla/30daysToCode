class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();

        vector<pair<int,int>> v(n);
        vector<string> ans(n);

        for(int i=0;i<n;i++) v[i] = {score[i],i};

        sort(v.begin(),v.end());



        for(int i = 0; i < n; i++)
        {
            if(i == 0) ans[v[n-i-1].second] = "Gold Medal";
                
            else if(i == 1) ans[v[n-i-1].second] = "Silver Medal";
                
            else if(i == 2) ans[v[n-i-1].second] = "Bronze Medal";
                
            else ans[v[n-i-1].second] = to_string(i + 1);
                
        }

        return ans;

    }
};