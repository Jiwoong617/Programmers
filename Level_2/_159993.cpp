#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y, int ex, int ey, vector<string>& maps)
{
    vector<vector<int>> v(maps.size(), vector<int>(maps[0].length(), 0));
    queue<pair<int, int>> q;
    
    v[x][y] = 1;
    q.push({x,y});
    while(!q.empty())
    {
        pair<int, int> t = q.front(); q.pop();
        if(t.first == ex && t.second == ey)
            return v[t.first][t.second] -1;
        
        for(int i = 0; i<4; i++)
        {
            int tx = t.first + dx[i];
            int ty = t.second + dy[i];
            if(tx >= 0 && ty >= 0 && tx < maps.size() && ty < maps[0].size())
            {
                if(maps[tx][ty] != 'X' && !v[tx][ty])
                {
                    v[tx][ty] = v[t.first][t.second]+1;
                    q.push({tx,ty});
                }
            }
        }
    }
    
    return 0;
}

int solution(vector<string> maps) {
    int sx, sy, lx, ly, ex, ey;
    for(int i = 0; i<maps.size(); i++)
    {
        for(int j = 0; j<maps[i].length(); j++)
        {
            if(maps[i][j] == 'S'){sx=i; sy=j;}
            if(maps[i][j] == 'L'){lx=i, ly=j;}
            if(maps[i][j] == 'E'){ex=i, ey=j;}
        }
    }
    
    int a = bfs(sx, sy, lx, ly, maps);
    int b = bfs(lx, ly, ex, ey, maps);
    if(!a || !b) return -1;
    
    return a+b;
}
