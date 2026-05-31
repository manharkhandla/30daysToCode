class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        int n = asteroids.size();

        sort(asteroids.begin(),asteroids.end());

        long long m = mass;

        for(int i=0;i<n;i++)
        {
            if(asteroids[i] > m) return false;
            m += asteroids[i];
        }

        return true;

    }
};