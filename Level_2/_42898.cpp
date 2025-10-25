#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> v(n+1, vector<int>(m+1, 0));
    v[1][1] = 1;
    for(auto a : puddles)
        v[a[1]][a[0]] = -1;
    
    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j<m+1; j++)
        {
            if (i == 1 && j == 1) continue;
            
            if(v[i][j] == -1)
            {
                v[i][j] = 0;
                continue;
            }
            
            v[i][j] = (v[i-1][j] + v[i][j-1])%1000000007;
        }
    }
    
    
    return v[n][m];
}
