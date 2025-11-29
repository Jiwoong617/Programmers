#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

pair<int, int> ricochet(int x, int y, int dir, const vector<vector<int>>& map)
{
    int nx = x;
    int ny = y;

    while (true)
    {
        int tx = nx + dx[dir];
        int ty = ny + dy[dir];
        if (tx < 0 || ty < 0 || tx >= map.size() || ty >= map[0].size() || map[tx][ty] == -1)
            break;

        nx = tx;
        ny = ty;
    }

    return {nx, ny};
}


int bfs(int x, int y, int gx, int gy, vector<vector<int>>& map)
{
    queue<pair<int, int>> q;
    q.push({x,y});
    map[x][y] = 1;
    
    while(!q.empty())
    {
        pair<int, int> t = q.front(); q.pop();
        if(t.first == gx && t.second == gy) return map[gx][gy]-1;
        for(int i = 0; i<4; i++)
        {
            pair<int,int> p = ricochet(t.first, t.second, i, map);
            if (p.first == t.first && p.second == t.second) continue;
            if (map[p.first][p.second] > 0) continue;
            
            map[p.first][p.second] = map[t.first][t.second] + 1;
            q.push(p);
        }
    }
    
    return -1;
}

int solution(vector<string> v) {
    vector<vector<int>> map(v.size(), vector<int>(v[0].length(), 0));
    int rx, ry, gx, gy;
    for(int i = 0; i<v.size(); i++)
    {
        for(int j = 0; j<v[0].length(); j++)
        {
            if(v[i][j] == 'D')
                map[i][j] = -1;
            else if(v[i][j] == 'R') { rx = i; ry = j; }
            else if(v[i][j] == 'G') { gx = i; gy = j; }
        }
    }
        
    return bfs(rx, ry, gx, gy, map);
}
