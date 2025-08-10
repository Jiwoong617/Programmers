#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<int>> dp(info.size()+1, vector<int>(m, 360));
    dp[0][0] = 0;
    
    for(int i = 1; i<= info.size(); i++)
    {
        int a = info[i-1][0];
        int b = info[i-1][1];
        
        for(int j = 0; j<m; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i-1][j] + a);
            if(j+b < m)
                dp[i][j+b] = min(dp[i][j+b],dp[i-1][j]);
        }
    }
    
    int ans = 360;
    for(int i = 0; i<m; i++)
        ans = min(ans, dp[info.size()][i]);
    
    return (ans >= n ? -1 : ans);
}


//이 아래는 백트래킹으로 풀어서 시간초과난 코드
/*
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int ans = INT_MAX;

void dfs(vector<vector<int>>& v, int& n, int& m, int a, int b, int deep)
{
    if (a >= n || b >= m) return;
    
    if (deep == v.size())
    {
        if (a < n && b < m)
            ans = min(a, ans);

        return;
    }

    dfs(v, n, m, a + v[deep][0], b, deep + 1);
    dfs(v, n, m, a, b + v[deep][1], deep + 1);
}

int solution(vector<vector<int>> info, int n, int m) {
    dfs(info, n, m, 0, 0, 0);
    return (ans == INT_MAX ? -1 : ans);
}
*/
