#include <string>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

void dfs(vector<int>& p, vector<string>& m, int& ans, int fat, int idx)
{
    if(idx >= m.size() || !accumulate(p.begin(), p.end(), 0))
    {
        ans = min(ans, fat);
        return;
    }
    
    int dig = min((int)m.size() - idx, 5);
    for(int i = 0; i<3; i++)
    {
        if(!p[i])
            continue;
        
        int cost = 0;
        for(int j = idx; j<idx + dig; j++)
        {
            int a = 0;
            if(m[j][0] == 'd') a = 2;
            else if (m[j][0] == 'i') a = 1;
            else a = 0;
            
            cost += pow(5, max(a-(2-i), 0)); 
        }
        p[i]--;
        dfs(p, m, ans, fat+cost, idx+dig);
        p[i]++;
    }
}

int solution(vector<int> p, vector<string> m) {
    int ans = 25*m.size();
    
    dfs(p, m, ans, 0, 0);
    return ans;
}
