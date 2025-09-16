#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> visited(n+1, 0);
    vector<vector<int>> v(n+1, vector<int>());
    for(auto a : edge)
    {
        v[a[0]].push_back(a[1]);
        v[a[1]].push_back(a[0]);
    }
    
    queue<int> q; q.push(1);
    visited[1] = 1;
    while(!q.empty())
    {
        int t = q.front(); q.pop();
        for(int i : v[t])
        {
            if(visited[i]) continue;
            
            q.push(i);
            visited[i] = visited[t] + 1;
        }
    }
    
    return count(visited.begin(), visited.end(), *max_element(visited.begin(), visited.end()));
}
