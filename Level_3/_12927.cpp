#include <string>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

long long solution(int n, vector<int> w) {
    long long ans = 0;
    if(accumulate(w.begin(), w.end(), -n) < 1) return 0;
    
    multiset<int> s(w.begin(), w.end());
    while(n)
    {
        int t = *prev(s.end()) - 1;
        if(t<0) s.erase(prev(s.end()));
        else
        {
            s.erase(prev(s.end()));
            s.insert(t);
            n--;
        }
    }
    
    for(int i : s)
        ans += i*i;
    
    return ans;
}
