class Solution {
public:
    typedef pair<int,char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P,vector<P>> pq;

        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});

        string ans = "";

        while(!pq.empty())
        {
            int currentFreq = pq.top().first;
            int currentChar = pq.top().second;
            pq.pop();

            if(ans.length()>=2 && ans[ans.length()-1]==currentChar && ans[ans.length()-2]==currentChar)
            {
                if(pq.empty()) break;

                int nextFreq = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();
                ans.push_back(nextChar);
                nextFreq--;
                if(nextFreq>0) pq.push({nextFreq,nextChar});
            }
            else
            {
                currentFreq--;
                ans.push_back(currentChar);
            }

            if(currentFreq>0) pq.push({currentFreq,currentChar});
        }
        return ans;
    }
};