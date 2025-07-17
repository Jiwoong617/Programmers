#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int ans = 0, n = nums.size();
    map<int, int> m;
    for(int a : nums)
        m[a]++;
        
    if(m.size() > n/2)
        ans = n/2;
    else
        ans = m.size();
    
    return ans;
}
