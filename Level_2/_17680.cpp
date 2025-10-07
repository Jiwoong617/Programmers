#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int cs, vector<string> c) {
    if(cs == 0)
        return c.size()*5;
    
    int ans = 0;

    list<string> cache;
    unordered_map<string, list<string>::iterator> m;

    for (auto& a : c)
    {
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        
        if (m.find(a) != m.end()) 
        {
            cache.erase(m[a]);
            cache.push_front(a);
            m[a] = cache.begin();
            ans++;
        }
        else 
        {
            if (cache.size() == cs) 
            {
                m.erase(cache.back());
                cache.pop_back();
            }
            cache.push_front(a);
            m[a] = cache.begin();
            ans += 5;
        }
    }

    return ans;
}
