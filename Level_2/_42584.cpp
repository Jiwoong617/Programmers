#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> p) {
    vector<int> ans(p.size());
    for(int i = 0; i<p.size(); i++)
    {
        for(int j = i+1; j<p.size(); j++)
        {
            ans[i]++;
            if(p[j] < p[i])
                break;
        }
    }
    
    return ans;
}
