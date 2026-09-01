class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1;
        vector<pair<int,int>> litterPos;
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = classroom[i][j];
                if (c == 'S') { sr = i; sc = j; }
                else if (c == 'L') {
                    litterId[i][j] = litterPos.size();
                    litterPos.push_back({i, j});
                }
            }
        }

        int L = litterPos.size();
        int fullMask = (1 << L) - 1;
        int E = energy; // max capacity

        // dist[r][c][mask][e]
        // flatten to 1D for speed/memory
        auto idx = [&](int r, int c, int mask, int e) {
            return (((r * n + c) * (1 << L) + mask) * (E + 1)) + e;
        };

        int totalStates = m * n * (1 << L) * (E + 1);
        vector<int> dist(totalStates, -1);

        int startMask = 0;
        if (litterId[sr][sc] != -1) startMask |= (1 << litterId[sr][sc]); // S won't be L per problem, but safe

        queue<array<int,4>> q; // r, c, mask, e
        int startIdx = idx(sr, sc, startMask, E);
        dist[startIdx] = 0;
        q.push({sr, sc, startMask, E});

        if (startMask == fullMask) return 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, mask, e] = q.front(); q.pop();
            int d = dist[idx(r, c, mask, e)];

            if (e == 0) continue; // stuck unless this cell was R, but then e would've been reset to E already

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (classroom[nr][nc] == 'X') continue;

                int ne = e - 1;
                int nmask = mask;
                if (classroom[nr][nc] == 'L') {
                    int bit = litterId[nr][nc];
                    if (bit != -1) nmask |= (1 << bit);
                }
                if (classroom[nr][nc] == 'R') {
                    ne = E; // reset to full capacity
                }

                int ni = idx(nr, nc, nmask, ne);
                if (dist[ni] == -1) {
                    dist[ni] = d + 1;
                    if (nmask == fullMask) return d + 1;
                    q.push({nr, nc, nmask, ne});
                }
            }
        }

        return -1;
    }
};