#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> v) {
    sort(v.begin(), v.end(), [](auto& a, auto& b){
        return a[1] < b[1];
    });
    
    int ans = 1, e = v[0][1];
    for(int i = 1; i<v.size(); i++)
    {
        if(v[i][0] >= e)
        {
            ans++;
            e = v[i][1];
        }
    }
    return ans;
}
