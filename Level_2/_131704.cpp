#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int ans = 0;
    vector<int> v;

    for (int i = 1; i <= order.size(); i++) 
    {
        v.push_back(i);

        while (v.size() && v.back() == order[ans]) 
        {
            v.pop_back();
            ans++;
        }
    }
    
    return ans;
}
