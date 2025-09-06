class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = t.size();
        if(n==1) return t[0];

        vector<int> freq(26,0);

        for(int i=0;i<n;i++) freq[t[i]-'a']++;
        
        for(int i=0;i<n-1;i++) freq[s[i]-'a']--;
        
        for(int i=0;i<26;i++) if(freq[i] > 0) return 'a' + i;

        return 'a';
    }
};