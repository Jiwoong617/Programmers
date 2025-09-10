#include <string>
#include <vector>

using namespace std;

int ans = 0;
bool visited[8];

void dfs(int deep, vector<vector<int>>& dungeons, int fatigue, int idx)
{
    if (fatigue < dungeons[idx][0])
        return;

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && fatigue - dungeons[idx][1] > 0)
        {
            visited[i] = true;
            dfs(deep + 1, dungeons, fatigue - dungeons[idx][1], i);
            visited[i] = false;
        }
    }

    ans = max(deep, ans);
}

int solution(int k, vector<vector<int>> dungeons) {

    for (int i = 0; i < dungeons.size(); i++)
    {
        visited[i] = true;
        dfs(1, dungeons, k, i);
        visited[i] = false;
    }

    return ans;
}
