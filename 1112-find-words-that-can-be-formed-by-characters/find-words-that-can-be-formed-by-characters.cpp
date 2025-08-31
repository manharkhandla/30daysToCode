class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n = words.size();
        int s = chars.size();
        vector<int> freq(26,0);
        int ans = 0;

        for(int i=0;i<s;i++) freq[chars[i]-'a']++;

        for(int i=0;i<n;i++)
        {
            vector<int> temp = freq;
            bool check = 1;
            for(char &ch: words[i])
            {
                if(temp[ch-'a']>0) temp[ch-'a']--;
                else
                {
                    check = 0;
                    break;
                } 
            }
            if(check) ans+=words[i].size();
        }

        return ans;
    }
};