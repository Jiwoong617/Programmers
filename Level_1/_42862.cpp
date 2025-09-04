#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> l, vector<int> r) {
    int ans = n - l.size();
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    
    for(int i = 0; i<r.size(); i++)
    {
        for(int j = 0; j<l.size(); j++)
        {
            if(l[j] == r[i])
            {
                l[j] = -1;
                r[i] = -1;
                ans++;
            }
        }
    }
    
    for(int i = 0; i<r.size(); i++)
    {
        for(int j = 0; j<l.size(); j++)
        {
            if(r[i] == -1 || l[j] == -1)
                continue;
            
            if(r[i] == l[j] + 1 || r[i] == l[j] - 1)
            {
                r[i] = -1;
                l[j] = -1;
                ans++;
                break;
            }
        }
    }
    
    return ans;
}
