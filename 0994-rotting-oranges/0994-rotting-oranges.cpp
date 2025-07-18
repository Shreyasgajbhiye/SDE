class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        int rotcnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    v[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                else{
                    v[i][j] = 0;
                    if(grid[i][j] == 1) rotcnt++;
                }
            }
        }

        int tm = 0;
        int cnt = 0;
        int rdel[] = {-1, 0, +1, 0};
        int cdel [] = {0, 1, 0 , -1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(t, tm);

            for(int i=0;i<4;i++){
                int row = r + rdel[i];
                int col = c + cdel[i];

                if(row >=0 && col >= 0 && row < n && col < m && v[row][col] == 0 && grid[row][col] == 1){
                    q.push({{row, col}, t+1});
                    v[row][col] = 2;
                    cnt++;
                }
            }
        }

        if(cnt != rotcnt) return -1;
        return tm;
    }
};