#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> ps, int loc) {
    queue<pair<int, int>> q; //idx, ps
    for (int i = 0; i < ps.size(); i++)
        q.push(make_pair(i, ps[i]));
    sort(ps.begin(), ps.end());
    
    int cnt = 0;
    while(1)
    {
        auto t = q.front(); q.pop();
        if(t.second != ps[ps.size() -1])
        {
            q.push(t);
            continue;
        }
        
        cnt++;
        ps.pop_back();

        if(loc == t.first) return cnt;
    }
    
}
