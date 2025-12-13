#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(vector<vector<int>>& v, int x, int y, vector<int>& out)
{
    set<int> s;
    
    queue<pair<int, int>> q;
    q.push({x,y});
    v[x][y] = 0;
    
    int cnt = 0;
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        s.insert(t.second);
        cnt ++;
        for(int i = 0; i<4; i++)
        {
            int tx = t.first + dx[i];
            int ty = t.second + dy[i];
            
            if(tx >= 0 && ty >= 0 && tx < v.size() && ty < v[0].size() && v[tx][ty])
            {
                v[tx][ty] = 0;
                q.push({tx,ty});
            }
        }
    }
    
    for(auto a : s)
        out[a] += cnt;
}

int solution(vector<vector<int>> land) {
    vector<int> v(land[0].size(), 0);
    
    for(int i = 0; i<land.size(); i++)
    {
        for(int j = 0; j<land[i].size(); j++)
        {
            if(land[i][j])
                bfs(land, i, j, v);
        }
    }
    
    return *max_element(v.begin(), v.end());
}
