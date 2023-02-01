#include<iostream>
#include<vector>
#include<queue>

void wallsAndGates(vector<vector<int>>& rooms) {
    queue<pair<int, int>> bfs;
    for (int i = 0; i < rooms.size(); i++) {
        for (int j = 0; j < rooms[i].size(); j++) {
            if (rooms[i][j] == 0) {
                bfs.push({ i, j });
            }
        }
    }
    vector<vector<int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    while (!bfs.empty()) {
        int cr = bfs.front().first;
        int cc = bfs.front().second;
        bfs.pop();

        for (int j = 0; j < directions.size(); j++) {
            int r = cr + directions[j][0];
            int c = cc + directions[j][1];
            if (r >= 0 && r < rooms.size() && c >= 0 && c < rooms[0].size()) {
                if (rooms[r][c] == INT_MAX) {
                    rooms[r][c] = rooms[cr][cc] + 1;
                    bfs.push({ r, c });
                }
            }
        }
    }

}