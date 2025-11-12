#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <functional>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int ans = 0;
    map<int, vector<pair<int, int>>> m; // 시작, 도착, 비용
    for(auto a : road)
    {
        m[a[0]].push_back(make_pair(a[1], a[2]));
        m[a[1]].push_back(make_pair(a[0], a[2]));
    }
    
    vector<int> visited(N+1, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push(make_pair(1, 1)); //비용, 도착
    while(!q.empty())
    {
        auto t = q.top(); q.pop();
        if(!visited[t.second])
        {
            visited[t.second] = t.first;
            if(t.first - 1 <= K)
                ans++;
        }
        
        for(int i = 0; i<m[t.second].size(); i++)
        {
            int a = m[t.second][i].first;
            int b = m[t.second][i].second;
            if(!visited[a])
                q.push(make_pair(t.first + b, a));
        }
    }
    
    return ans;
}
