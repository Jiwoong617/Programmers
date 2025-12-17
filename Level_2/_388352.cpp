#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num, v;
int answer = 0;

bool check(int n, vector<vector<int>>& q, vector<int>& ans)
{
    for(int i = 0; i<q.size(); i++)
    {
        int cnt = 0;
        for(int j = 0; j<q[i].size(); j++)
        {
            if(find(v.begin(), v.end(), q[i][j]) != v.end())
                cnt++;
        }
        
        if(ans[i] != cnt) return false;
    }
    
    return true;
}

void dfs(int n, vector<vector<int>>& q, vector<int>& ans, int now)
{
    if(v.size() == 5)
    {
        if(check(n,q,ans))
            answer++;
        return;
    }
        
    for(int i=now; i<n; i++)
    {
        v.push_back(num[i]);
        dfs(n, q, ans, i+1);
        v.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    for(int i = 0; i<n; i++)
        num.push_back(i+1);
    
    dfs(n, q, ans, 0);
    return answer;
}
