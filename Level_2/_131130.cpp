#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    vector<bool> v(cards.size()+1, false);
    vector<int> ans;
    for(int i = 0; i<cards.size(); i++)
    {
        int cnt = 0;
        int now = cards[i];
        while(!v[now])
        {
            cnt++;
            v[now] = true;
            now = cards[now-1];
        }
        ans.push_back(cnt);
    }
    sort(ans.rbegin(), ans.rend());
    return ans[0]*ans[1];
}
