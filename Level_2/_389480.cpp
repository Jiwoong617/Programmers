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
