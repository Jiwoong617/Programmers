#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int* p;

int findP(int n)
{
    if(p[n] == n) return n;
    return p[n] = findP(p[n]);
}

bool unionF(int n, int m)
{
    int a = findP(n);
    int b = findP(m);
    
    if(a == b) return true;
    
    if(a < b) p[b] = a;
    else p[a] = b;
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int ans = 0;
    p = new int[n];
    for(int i = 0; i<n; i++)
        p[i] = i;
    
    sort(costs.begin(), costs.end(), [](auto& a, auto& b){
        return a[2] < b[2];
    });
    
    for(auto& a : costs)
        if(!unionF(a[0], a[1]))
            ans += a[2];

    return ans;
}
