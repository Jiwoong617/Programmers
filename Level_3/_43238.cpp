#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long l = 1, r = (long long)times.back()*n;
    while(l <= r)
    {
        long long cnt = 0, mid = (l+r)/2;
        for(int i : times)
            cnt += mid/i;
        
        if(cnt >= n)
            r = mid-1;
        else
            l = mid+1;
    }
      
    return l;
}
