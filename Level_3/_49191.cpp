#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> r) {
    int ans = 0;
    vector<vector<bool>> v(n, vector<bool>(n, false));
    for(auto& a : r)
        v[a[0]-1][a[1]-1] = true;
    
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            for(int k = 0; k<n; k++)
                if(v[j][i] && v[i][k])
                    v[j][k] = true;
    
    for(int i = 0; i<n; i++)
    {
        int cnt = 0;
        for(int j = 0; j<n; j++)
        {
            if(v[i][j] || v[j][i])
                cnt++;
        }
        ans = (cnt==n-1 ? ans+1:ans);
    }
    return ans;
}
