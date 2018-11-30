class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int lands = 0, neighbors = 0;
        for (unsigned i = 0; i < grid.size(); ++i)
            for (unsigned j = 0; j < grid[0].size(); ++j)
                if (grid[i][j]) {
                    ++lands;
                    if (i && grid[i - 1][j])
                        ++neighbors;
                    if (j && grid[i][j - 1])
                        ++neighbors;
                }
        return lands * 4 - neighbors * 2;
    }
};
