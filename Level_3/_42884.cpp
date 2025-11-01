#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> loc) {
    int ans = 0, cam = -30001;
    sort(loc.begin(), loc.end(), [](vector<int>& a, vector<int>& b)
         {
             return a[1] < b[1];
         });
    
    for(auto a : loc)
    {
        if(cam < a[0])
        {
            ans++;
            cam = a[1];
        }
    }
    
    return ans;
}
