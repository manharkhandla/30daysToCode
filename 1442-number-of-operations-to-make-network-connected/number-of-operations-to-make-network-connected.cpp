class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int i)
    {
        if(i==parent[i]) return i;

        return parent[i] = find(parent[i]);
    }

    void Union(int x,int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;


        if(rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }

        else if(rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        
        else 
        {
            parent[y_parent] = x_parent; 
            rank[x_parent]++;
        }
        
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n - 1 > connections.size()) return -1;

        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto& c : connections) {
            Union(c[0], c[1]);
        }

        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (find(i) == i) components++;
        }

        return components - 1;
    }

};