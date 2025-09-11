#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;
int cnt = 0;

void dfs(int idx)
{
    if (visited[idx])
        return;

    cnt++;
    visited[idx] = true;
    for (int i = 0; i < v[idx].size(); i++)
    {
        dfs(v[idx][i]);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int ans = 100;
    for (int i = 0; i < wires.size(); i++)
    {
        v = vector<vector<int>>(n + 1, vector<int>());
        visited = vector<bool>(n + 1, false);
        cnt = 0;
        for (int j = 0; j < wires.size(); j++)
        {
            if (i == j) continue;
            
            v[wires[j][0]].push_back(wires[j][1]);
            v[wires[j][1]].push_back(wires[j][0]);
        }

        dfs(1);
        int m = min(cnt, n - cnt);
        ans = min(ans, n - m*2);
    }

    return ans;
}
