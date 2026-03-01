class Solution {
public:
    int minPartitions(string n) {
        
        int s = n.size();
        int largest = n[0]-'0';

        for(int i=1;i<s;i++) if(n[i]-'0' > largest) largest = n[i]-'0';

        return largest;

    }
};
