class Solution {
public:

    void DFS(vector<vector<int>>& rooms,vector<bool> &visited,int i)
    {
        if(visited[i]) return;
        visited[i] = 1;

        for(int &v : rooms[i])
        {
            if(!visited[v]) DFS(rooms,visited,v);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),0);

        DFS(rooms,visited,0);

        for(int i=0;i<rooms.size();i++)
        {
            if(visited[i]==0) return false;
        }

        return true;
    }
};