class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int K) {
        int n = grid.size(), m = grid[0].size();
        vector dist(n, vector(m, vector<int>(K+1, INT_MAX)));
        
        queue<tuple<int,int,int>> q;
        dist[0][0][0] = 0;
        q.push({0, 0, 0});
        
        int dr[4] = {-1,0,1,0}, dc[4] = {0,-1,0,1};
        int steps = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, k_used] = q.front(); q.pop();
                if (r == n-1 && c == m-1) 
                    return steps;
                
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) 
                        continue;
                    
                    int nk = k_used + grid[nr][nc];
                    if (nk > K) 
                        continue;
                    if (dist[nr][nc][nk] == INT_MAX) {
                        dist[nr][nc][nk] = steps + 1;
                        q.push({nr, nc, nk});
                    }
                }
            }
            steps++;
        }
        
        return -1; // no path found
    }
};
