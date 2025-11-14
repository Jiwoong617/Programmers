#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> w) {
    long long ans = 0;
    map<int, long long> m;
    for(int i : w)
        m[i]++;
    
    for(auto& i : m)
    {
        int a = i.first;
        long long b = i.second;
        
        if(b > 1)
            ans += b * (b-1)/2;
                
        if(m.find(a*2) != m.end())
            ans += m[a*2] * b;
        
        if(a%2 == 0 && m.find(a/2*3) != m.end())
            ans += m[a/2*3] * b;
        
        if(a%3 == 0 && m.find(a/3*4) != m.end())
            ans += m[a/3*4] * b;
    }
    
    return ans;
}
