#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    if(a.size() < 3) return a.size();
    
    int ans = 2;
    
    vector<int> l(a.size(), a[0]), r(a.size(), a.back());
    for(int i = 1; i<a.size(); i++)
    {
        l[i] = min(a[i], l[i-1]);
        r[a.size()-1 - i] = min(a[a.size()-1 -i], r[a.size()-i]);
    }
    
    for(int i = 1; i<a.size()-1; i++)
        if(l[i-1] >= a[i] || r[i+1] >= a[i])
            ans++;
    
    return ans;
}
