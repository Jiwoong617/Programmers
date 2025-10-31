#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> st, int w)
{
    int div = w*2+1;
    int ans = 0;
    if(st[0]-w-1 > 0)
        ans = ((st[0]-w-1) % div ? (st[0]-w-1)/div+1 :(st[0]-w-1)/div);

    for(int i = 0; i<st.size()-1; i++)
    {
        int range = st[i+1]-w-1 - (st[i]+w);
        if(range < 1) continue;
            
        ans += range /div;
        if(range%div) ans++;
        
    }
    
    if(st.back() + w < n)
    {
        int range = n-st.back()-w;
        ans += range /div;
        if(range%div) ans++;
    }
    
    return ans;
}
