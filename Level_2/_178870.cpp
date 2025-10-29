#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> ans = {0, 1000000};
    vector<int> sum(sequence.size() +1, 0);
    for(int i = 0; i<sequence.size(); i++)
        sum[i+1] = sum[i] + sequence[i];
    
    int l = 1, r = 1;
    while(l <= r && r <sum.size())
    {
        int t = sum[r] - sum[l-1];
        if(t < k) r++;
        else if(t > k) l++;
        else
        {
            if(r-l < ans[1]-ans[0])
                ans = {l-1, r-1};
            l++;
        }
    }
    return ans;
}
