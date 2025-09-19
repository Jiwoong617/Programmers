#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> ans(2,0);
    while(s.length() != 1)
    {
        ans[0]++;
        int cnt = count(s.begin(), s.end(), '1');
        ans[1]+=s.length() - cnt;
        
        s = "";
        while(cnt)
        {
            s+=(cnt%2) + '0';
            cnt /=2;
        }
        
    }
    return ans;
}
