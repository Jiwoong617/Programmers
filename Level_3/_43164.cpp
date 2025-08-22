#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string>> m;
unordered_map<string, vector<bool>> visited;
vector<string> answer;
int deep = 0;

bool dfs(string now, int cnt)
{
    if (cnt == deep)
        return true;

    for (int i = 0; i < m[now].size(); i++)
    {
        if (visited[now][i] == true) continue;

        visited[now][i] = true;
        answer.push_back(m[now][i]);
        if (dfs(m[now][i], cnt + 1)) return true;

        visited[now][i] = false;
        answer.pop_back();
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    for (auto s : tickets)
    {
        m[s[0]].push_back(s[1]);
        visited[s[0]].push_back(false);
        deep++;
    }

    for (auto& a : m)
    {
        sort(a.second.begin(), a.second.end());
    }

    answer.push_back("ICN");
    dfs("ICN", 0);

    return answer;
}
