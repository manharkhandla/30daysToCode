class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for(int i=0;i<tickets.size();i++)
        {
            q.push(i);
        }

        int time = 0;

        int f;

        while(tickets[k]!=0)
        {
            f = q.front();
            q.pop();
            tickets[f]--;
            time++;
            if(tickets[f]!=0)  q.push(f);
        }
        

        return time;
    }
};