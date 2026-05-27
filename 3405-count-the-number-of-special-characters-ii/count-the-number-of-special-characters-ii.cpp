class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        int n = word.size();
        vector<pair<int,int>> accur(26,{-1, -1});
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            bool lower = word[i] >= 'a' && word[i] <= 'z' ? true : false;

            if(lower)
            {
                accur[word[i]-'a'].first = i;
            }

            else 
            {
                if(accur[word[i]-'A'].second == -1) accur[word[i]-'A'].second = i;
            }
        }

        for(int i=0;i<26;i++)
        {
            if(accur[i].first < accur[i].second && accur[i].first != -1) ans++;
        }


        return ans;

    }
};