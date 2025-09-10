class Solution {
public:
    bool isVovel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0,count = 0;
        int i=0,j=0;

        while(j<n)
        {
            if(isVovel(s[j])) count++;
            if(j-i+1==k)
            {
                ans=max(ans,count);
                if(isVovel(s[i])) count--;
                i++;            
            }
            j++;
        }

        return ans;
    }
};