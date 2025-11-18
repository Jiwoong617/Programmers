#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> s) {
    long long ans = 0, a = 0, b = 0;
    bool toggle = false;
    for(int i : s)
    {
        if(toggle)
        {
            a += i;
            b += -i;
        }
        else
        {
            a += -i;
            b += i;
        }
        
        a = max(0LL, a);
        b = max(0LL, b);
        ans = max(ans, a);
        ans = max(ans, b);
        toggle = !toggle;
    }
    return ans;
}
