#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(n > s) return {-1};

    vector<int> ans(n, s/n);
    int cnt = s % n;
    for(int i = n; cnt>= 0; i--)
    {
        cnt--;
        ans[i]++;
    }
    
    return ans;
}
