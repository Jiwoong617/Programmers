#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(vector<string>& maps, vector<vector<bool>>& visited, int x, int y, int& n)
{
    n += maps[x][y] - '0';
    visited[x][y] = true;
    
    for(int i = 0; i<4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx >= 0 && ty >= 0 && tx < maps.size() && ty < maps[0].length())
            if(!visited[tx][ty] && maps[tx][ty] != 'X')
                dfs(maps, visited, tx, ty, n);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> ans;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].length(), false));
    for(int i = 0; i<maps.size(); i++)
    {
        for(int j = 0; j<maps[0].length(); j++)
        {
            if(maps[i][j] != 'X' && !visited[i][j])
            {
                int n = 0;
                dfs(maps, visited, i, j, n);
                if(n != 0)
                    ans.push_back(n);
            }
        }
    }
    
    if(!ans.size())
        return vector<int>(1, -1);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}
