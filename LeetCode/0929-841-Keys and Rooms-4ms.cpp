class Solution {
public:
    void visit(auto& graph, auto& visited, int node) {
        visited[node] = true;
        for (auto it = graph[node].begin(); it != graph[node].end(); ++it)
            if (!visited[*it])
                visit(graph, visited, *it);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        visit(rooms, visited, 0);
        for (auto it = visited.begin(); it != visited.end(); ++it)
            if (!*it)
                return false;
        return true;
    }
};
