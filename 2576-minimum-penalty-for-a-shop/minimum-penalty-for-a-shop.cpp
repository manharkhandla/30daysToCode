class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.size();

        vector<int> prefix(n,0);
        int suffix = 0;

        for(int i=0;i<n;i++) if(customers[i]=='Y') suffix++;
        int temp = suffix;
       
        for(int i=1;i<n;i++)
        {
            if(customers[i-1]=='N') prefix[i] = prefix[i-1] + 1;
            else prefix[i] = prefix[i-1];
        }

        vector<int> panelty(n,0);

        for(int i=0;i<n;i++)
        {
            panelty[i] = temp + prefix[i];
            if(customers[i]=='Y') temp--;
        }

        panelty.push_back(n-suffix);

        int maxP = n+2;
        int idx = n-1;

        for(int i=0;i<=n;i++)
        {   
            if(panelty[i]<maxP)
            {
                maxP = panelty[i];
                idx = i;
            } 
            cout<<maxP;
        }

        return idx;

    }
};