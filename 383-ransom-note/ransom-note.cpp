class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> isPresent(26,0);

        int n = magazine.size();

        for(int i=0;i<n;i++)
        {
            int idx = magazine[i] - 'a';
            isPresent[idx]++;
        }

        int m = ransomNote.size();

        for(int i=0;i<m;i++)
        {
            int idx = ransomNote[i]-'a';
            if(isPresent[idx]==0) return false;
            isPresent[idx]--;
        }

        return true;

    }
};