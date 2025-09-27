#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> p, int limit) {
    int ans = 0,l = 0, r = p.size()-1;
    sort(p.begin(), p.end());
    
    while(l <= r)
    {
        if(p[l]+p[r] <= limit)
        {
            l++;
            r--;
        }
        else
            r--;
        ans++;
    }
    
    return ans;
}
