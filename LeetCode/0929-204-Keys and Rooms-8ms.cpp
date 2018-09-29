class Solution {
public:    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> dist(rooms.size(), INT_MAX);
        dist[0] = 0;
        queue<int> Q;
        Q.push(0);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto it = rooms[u].begin(); it != rooms[u].end(); ++it)
                if (dist[*it] == INT_MAX) {
                    dist[*it] = dist[u] + 1;
                    Q.push(*it);
                }
        }
        for (auto it = dist.begin(); it != dist.end(); ++it)
            if (*it == INT_MAX)
                return false;
        return true;
    }
};
