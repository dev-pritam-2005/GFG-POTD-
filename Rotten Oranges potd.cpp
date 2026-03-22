class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        queue<tuple<int,int,int>> q;
        int fresh = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 2)
                    q.push({i, j, 0});
                else if (mat[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0) return 0;

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        int time = 0;

        while (!q.empty()) {
            auto [r, c, t] = q.front();
            q.pop();

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && mat[nr][nc] == 1) {
                    mat[nr][nc] = 2;
                    fresh--;
                    time = t + 1;
                    q.push({nr, nc, t + 1});
                }
            }
        }

        return fresh == 0 ? time : -1;
    }
};