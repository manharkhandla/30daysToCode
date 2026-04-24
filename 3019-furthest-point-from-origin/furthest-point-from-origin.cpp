class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int countOfR = 0;
        int countOfL = 0;
        int countOf_ = 0;

        int n = moves.size();

        for(int i=0;i<n;i++)
        {
            if(moves[i]=='L') countOfL++;
            if(moves[i]=='R') countOfR++;
            if(moves[i]=='_') countOf_++;
        }

        cout<<countOfL<<" "<<countOfR<<" "<<countOf_;

        return (countOf_ + max(countOfL,countOfR) - min(countOfL,countOfR));

    }
};