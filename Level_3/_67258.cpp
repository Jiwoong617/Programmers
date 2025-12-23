#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> g) {
    map<string, int> m, cnt;
    for(int i = 0; i<g.size(); i++)
        m[g[i]]++;
    
    int n = m.size();
    int l = 0, r = 0, ansl = 0, ansr = n-1, best = g.size()+1;
    while(r<g.size())
    {
        cnt[g[r]]++;
        r++;
        while(n == cnt.size())
        {
            int len = r-l;
            if(len < best)
            {
                best = len;
                ansl = l;
                ansr = r-1;
            }
            
            cnt[g[l]]--;
            if(!cnt[g[l]])
                cnt.erase(g[l]);
            l++;
        }
    }
    
    return {ansl+1, ansr+1};
}
