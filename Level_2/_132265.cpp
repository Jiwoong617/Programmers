#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int ans = 0;
    map<int, int> a, b;
    for(int i : topping)
        a[i]++;
    
    for(int i : topping)
    {
        a[i]--;
        b[i]++;
        if(a[i] == 0)
            a.erase(i);
        
        if(a.size() == b.size())
            ans++;
    }
    
    return ans;
}
