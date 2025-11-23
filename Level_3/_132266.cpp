#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int d) {
    vector<vector<int>> m(n+1, vector<int>());
    vector<int> v(n+1,-1), ans;
    for(auto a : roads)
    {
        m[a[0]].push_back(a[1]);
        m[a[1]].push_back(a[0]);
    }
    
    queue<int> q;
    v[d] = 0;
    q.push(d);
    while(!q.empty())
    {
        int t = q.front(); q.pop();
        
        for(int i : m[t])
        {
            if(v[i] == -1)
            {
                q.push(i);
                v[i] = v[t]+1;
            }
        }
    }
    
    for(int i : sources)
        ans.push_back(v[i]);
    
    return ans;
}
