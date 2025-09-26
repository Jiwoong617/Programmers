#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> m;
    for(int i : tangerine)
        m[i]++;
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](const auto& a, const auto& b)
         {
	        return a.second > b.second;
         });

    int cnt = 0;
    for(int i = 0; i<v.size(); i++)
    {
        if(k<=0)
            break;
        
        cnt++;
        k-=v[i].second;
    }
    
    return cnt;
}
