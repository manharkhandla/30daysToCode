class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        vector<int> freq(26,0);

        for(int i=0;i<n;i++) freq[s[i]-'a']++;

        int vmax=freq[0];
        int cmax=freq[1];

        for(int i=0;i<n;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') vmax=max(vmax,freq[s[i]-'a']);
            else cmax=max(cmax,freq[s[i]-'a']);
        }

        return vmax+cmax;
    }
};