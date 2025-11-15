#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> s, int k) {
    int l = *min_element(s.begin(), s.end());
    int r = *max_element(s.begin(), s.end());
    
    while(l <= r)
    {
        int mid = (l+r)/2;
        int cnt = 0;
        for(int i : s)
        {
            if(i-mid > 0) cnt = 0;
            else cnt++;
            
            if(cnt >= k) break;
        }
        
        if(cnt >= k)
            r = mid-1;
        else
            l = mid +1;
    }
    
    return l;
}
